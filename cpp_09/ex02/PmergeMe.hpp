#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    ~PmergeMe();

    PmergeMe &operator=(const PmergeMe &other);

    void run(int argc, char **argv);

private:
    std::vector<int> _vec;
    std::deque<int> _deq;

    void parseInput(int argc, char **argv);

    void sortVector();
    void fordJohnsonVec(std::vector<int> &arr);
    void insertBinaryVec(std::vector<int> &arr,
                         std::vector<int>::iterator end,
                         int value);

    void sortDeque();
    void fordJohnsonDeq(std::deque<int> &arr);
    void insertBinaryDeq(std::deque<int> &arr,
                         std::deque<int>::iterator end,
                         int value);

    static std::vector<int> buildJacobsthal(int n);
    void printSequence(const std::string &label,
                       const std::vector<int> &v) const;
};

#endif