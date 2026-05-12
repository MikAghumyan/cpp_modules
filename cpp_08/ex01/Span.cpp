#include "Span.hpp"

#include <stdexcept>
#include <algorithm>
#include <climits>

Span::Span() : _max(0), _data(0) {}

Span::Span(unsigned int N) : _max(N), _data(0) {}

Span::Span(const Span &other) { *this = other; }

Span::~Span() {}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->_max = other._max;
        this->_data = other._data;
    }
    return (*this);
}

void Span::addNumber(int num)
{
    if (_data.size() >= _max)
        throw std::length_error("Max size reached.");
    _data.push_back(num);
}

int Span::shortestSpan() const
{
    if (_data.size() < 2)
        throw std::length_error("Not enough lengh to get shortest span.");
    std::vector<int> sorted(_data);
    std::sort(sorted.begin(), sorted.end());
    int minSpan = INT_MAX;
    for (std::vector<int>::iterator it = sorted.begin() + 1; it != sorted.end(); ++it)
    {
        int span = *it - *(it - 1);
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const
{
    if (_data.size() < 2)
        throw std::length_error("Not enough lengh to get shortest span.");
    int min_value = *std::min_element(_data.begin(), _data.end());
    int max_value = *std::max_element(_data.begin(), _data.end());
    return (max_value - min_value);
}