#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
public:
    Span();
    Span(unsigned int N);
    Span(const Span &other);
    ~Span();

    Span &operator=(const Span &other);
    void addNumber(int num);
    template <typename Iterator>
    void insertRange(Iterator begin, Iterator end)
    {
        if (std::distance(begin, end) + _data.size() > _max)
            throw std::length_error("Max size reached.");
        _data.insert(_data.end(), begin, end);
    }
    int shortestSpan() const;
    int longestSpan() const;

private:
    unsigned int _max;
    std::vector<int> _data;
};

#endif