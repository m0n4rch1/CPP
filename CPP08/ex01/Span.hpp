#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>
#include <iostream>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span(unsigned int n);

    Span(const Span &other);
    Span &operator=(const Span &other);

    ~Span();

    void addNumber(int number);

    template <typename InputIt>
    void addNumbers(InputIt begin, InputIt end) {
        if (_numbers.size() + std::distance(begin, end) > _maxSize)
            throw std::runtime_error("Not enough space to add all numbers");
        _numbers.insert(_numbers.end(), begin, end);
    }

    int shortestSpan() const;
    int longestSpan() const;
};

#endif
