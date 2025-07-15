#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T>
class Array {
public:
    Array(): _array(nullptr), _size(0) {}
    Array(unsigned int n): _array(new T[n]()), _size(n) {}
    Array(Array const &other): _array(other._size ? new T[other._size]() : nullptr), _size(other._size) {
        for (unsigned int i = 0; i < _size; ++i)
            _array[i] = other._array[i];
    }
    ~Array() {
        delete[] _array;
    }
    Array &operator=(Array const &other) {
        if (this != &other) {
            delete[] _array;
            _size = other._size;
            _array = _size ? new T[_size]() : nullptr;
            for (unsigned int i = 0; i < _size; ++i)
                _array[i] = other._array[i];
        }
        return *this;
    }
    T &operator[](unsigned int index) {
        if (index >= _size)
            throw std::exception();
        return _array[index];
    }
    const T &operator[](unsigned int index) const {
        if (index >= _size)
            throw std::exception();
        return _array[index];
    }
    unsigned int size() const { return _size; }
private:
    T* _array;
    unsigned int _size;
};

#endif