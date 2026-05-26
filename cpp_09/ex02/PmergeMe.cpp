#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <sys/time.h>
#include <stdexcept>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
    }
    return (*this);
}

std::vector<int> PmergeMe::buildJacobsthal(int n)
{
    std::vector<int> J;

    J.push_back(0);
    J.push_back(1);
    while (J.back() < n)
        J.push_back(J[J.size() - 1] + 2 * J[J.size() - 2]);
    return J;
}

void PmergeMe::parseInput(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        std::istringstream iss(argv[i]);
        long val;
        char leftover;

        if (!(iss >> val))
            throw std::runtime_error("Error: invalid input");
        if (iss >> leftover)
            throw std::runtime_error("Error: invalid input");
        if (val <= 0)
            throw std::runtime_error("Error: only positive numbers are acceptable");

        _vec.push_back(static_cast<int>(val));
        _deq.push_back(static_cast<int>(val));
    }
    if (_vec.empty())
        throw std::runtime_error("Error: empty sequence");
}

void PmergeMe::insertBinaryVec(std::vector<int> &arr,
                               std::vector<int>::iterator end,
                               int value)
{
    std::vector<int>::iterator pos =
        std::lower_bound(arr.begin(), end, value);
    arr.insert(pos, value);
}

void PmergeMe::insertBinaryDeq(std::deque<int> &arr,
                               std::deque<int>::iterator end,
                               int value)
{
    std::deque<int>::iterator pos = std::lower_bound(arr.begin(), end, value);
    arr.insert(pos, value);
}

void PmergeMe::fordJohnsonVec(std::vector<int> &arr)
{
    int n = static_cast<int>(arr.size());
    if (n <= 1)
        return;

    // two elements
    if (n == 2)
    {
        if (arr[0] > arr[1])
            std::swap(arr[0], arr[1]);
        return;
    }

    bool hasStraggler = (n % 2 != 0);
    int straggler = hasStraggler ? arr[n - 1] : 0;

    // make pairs
    std::vector<std::pair<int, int> > pairs;
    int pairCount = n / 2;
    for (int i = 0; i < pairCount; i++)
    {
        int a = arr[2 * i];
        int b = arr[2 * i + 1];
        if (a < b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    // recursively sort for winners
    std::vector<int> winners;
    winners.reserve(pairCount);
    for (int i = 0; i < pairCount; i++)
        winners.push_back(pairs[i].first);
    fordJohnsonVec(winners);
    std::sort(pairs.begin(), pairs.end());

    // make main chain
    std::vector<int> chain;
    chain.reserve(n + 1);
    chain.push_back(pairs[0].second);
    for (int i = 0; i < pairCount; i++)
        chain.push_back(winners[i]);
    // make pending list
    std::vector<int> pend;
    pend.reserve(pairCount - 1);
    for (int i = 1; i < pairCount; i++)
        pend.push_back(pairs[i].second);

    // insert pend elements in Jacobsthal order
    std::vector<int> J = buildJacobsthal(static_cast<int>(pend.size()));
    std::vector<bool> inserted(pend.size(), false);
    for (size_t k = 2; k < J.size(); k++)
    {
        int groupEnd = J[k];           // last index in this group (1-based)
        int groupStart = J[k - 1] + 1; // first index in this group (1-based)

        // clamp to actual pend size
        if (groupStart - 1 >= static_cast<int>(pend.size()))
            break;
        if (groupEnd > static_cast<int>(pend.size()))
            groupEnd = static_cast<int>(pend.size());

        // insert from groupEnd down to groupStart (reverse order)
        for (int idx = groupEnd; idx >= groupStart; idx--)
        {
            int pendIdx = idx - 1; // 0-based in pend array
            if (pendIdx < 0 || pendIdx >= static_cast<int>(pend.size()))
                continue;
            if (inserted[pendIdx])
                continue;

            int value = pend[pendIdx];
            // The partner of pend[pendIdx] is pairs[pendIdx+1].first
            int partner = pairs[pendIdx + 1].first;

            // Find partner's position in chain (upper bound for binary search)
            // chain is sorted, partner is in chain, use lower_bound
            std::vector<int>::iterator partnerIt =
                std::lower_bound(chain.begin(), chain.end(), partner);
            // partnerIt points to partner; search range is [begin, partnerIt)
            // (exclusive — we know value <= partner)

            insertBinaryVec(chain, partnerIt, value);
            inserted[pendIdx] = true;
        }
    }

    // insert any remaining pend elements not yet covered by Jacobsthal groups
    for (size_t i = 0; i < pend.size(); i++)
    {
        if (!inserted[i])
        {
            int value = pend[i];
            int partner = pairs[i + 1].first;
            std::vector<int>::iterator partnerIt =
                std::lower_bound(chain.begin(), chain.end(), partner);
            insertBinaryVec(chain, partnerIt, value);
            inserted[i] = true;
        }
    }

    // insert straggler into the fully built chain (no upper bound restriction)
    if (hasStraggler)
    {
        std::vector<int>::iterator pos =
            std::lower_bound(chain.begin(), chain.end(), straggler);
        chain.insert(pos, straggler);
    }

    arr = chain;
}

void PmergeMe::fordJohnsonDeq(std::deque<int> &arr)
{
    int n = static_cast<int>(arr.size());
    if (n <= 1)
        return;

    if (n == 2)
    {
        if (arr[0] > arr[1])
            std::swap(arr[0], arr[1]);
        return;
    }

    bool hasStraggler = (n % 2 != 0);
    int straggler = hasStraggler ? arr[n - 1] : 0;

    std::vector<std::pair<int, int> > pairs;
    int pairCount = n / 2;
    for (int i = 0; i < pairCount; i++)
    {
        int a = arr[2 * i];
        int b = arr[2 * i + 1];
        if (a < b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    std::deque<int> winners;
    for (int i = 0; i < pairCount; i++)
        winners.push_back(pairs[i].first);

    fordJohnsonDeq(winners);

    std::sort(pairs.begin(), pairs.end());

    std::deque<int> chain;
    chain.push_back(pairs[0].second);
    for (int i = 0; i < pairCount; i++)
        chain.push_back(winners[i]);

    std::vector<int> pend;
    pend.reserve(pairCount - 1);
    for (int i = 1; i < pairCount; i++)
        pend.push_back(pairs[i].second);

    std::vector<int> J = buildJacobsthal(static_cast<int>(pend.size()));
    std::vector<bool> inserted(pend.size(), false);

    for (size_t k = 2; k < J.size(); k++)
    {
        int groupEnd = J[k];
        int groupStart = J[k - 1] + 1;

        if (groupStart - 1 >= static_cast<int>(pend.size()))
            break;
        if (groupEnd > static_cast<int>(pend.size()))
            groupEnd = static_cast<int>(pend.size());

        for (int idx = groupEnd; idx >= groupStart; idx--)
        {
            int pendIdx = idx - 1;
            if (pendIdx < 0 || pendIdx >= static_cast<int>(pend.size()))
                continue;
            if (inserted[pendIdx])
                continue;

            int value = pend[pendIdx];
            int partner = pairs[pendIdx + 1].first;

            std::deque<int>::iterator partnerIt =
                std::lower_bound(chain.begin(), chain.end(), partner);

            insertBinaryDeq(chain, partnerIt, value);
            inserted[pendIdx] = true;
        }
    }

    for (size_t i = 0; i < pend.size(); i++)
    {
        if (!inserted[i])
        {
            int value = pend[i];
            int partner = pairs[i + 1].first;
            std::deque<int>::iterator partnerIt =
                std::lower_bound(chain.begin(), chain.end(), partner);
            insertBinaryDeq(chain, partnerIt, value);
            inserted[i] = true;
        }
    }

    if (hasStraggler)
    {
        std::deque<int>::iterator pos =
            std::lower_bound(chain.begin(), chain.end(), straggler);
        chain.insert(pos, straggler);
    }

    arr = chain;
}

void PmergeMe::sortVector()
{
    struct timeval start, end;
    gettimeofday(&start, NULL);

    fordJohnsonVec(_vec);

    gettimeofday(&end, NULL);

    double elapsed = static_cast<double>(end.tv_sec - start.tv_sec) * 1e6 + static_cast<double>(end.tv_usec - start.tv_usec);

    std::cout << "Time to process a range of "
              << _vec.size()
              << " elements with std::vector : "
              << elapsed << " us\n";
}

void PmergeMe::sortDeque()
{
    struct timeval start, end;
    gettimeofday(&start, NULL);

    fordJohnsonDeq(_deq);

    gettimeofday(&end, NULL);

    double elapsed = static_cast<double>(end.tv_sec - start.tv_sec) * 1e6 + static_cast<double>(end.tv_usec - start.tv_usec);

    std::cout << "Time to process a range of "
              << _deq.size()
              << " elements with std::deque : "
              << elapsed << " us\n";
}

void PmergeMe::printSequence(const std::string &label,
                             const std::vector<int> &v) const
{
    std::cout << label;
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i];
        if (i != v.size() - 1)
            std::cout << " ";
    }
    std::cout << "\n";
}

void PmergeMe::run(int argc, char **argv)
{
    parseInput(argc, argv);

    printSequence("Before: ", _vec);

    sortVector();
    sortDeque();

    printSequence("After:  ", _vec);
}