#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>

template <typename T>
class Array
{
public:
    Array() : _size(0), _data(NULL) {}
    Array(unsigned int size) : _size(size), _data(new T[size]()) {}
    Array(const Array<T> &other) : _size(0), _data(NULL) { Array<T>::operator=(other); }
    ~Array() { delete[] _data; }

    Array<T> &operator=(const Array<T> &other)
    {
        if (this == &other)
            return (*this);
        delete[] _data;
        _size = other._size;
        _data = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _data[i] = other._data[i];
        return (*this);
    }
    T &operator[](unsigned int index)
    {
        return const_cast<T &>(static_cast<const Array<T> &>(*this)[index]);
    }
    T const &operator[](unsigned int index) const
    {
        if (index >= _size)
            throw std::out_of_range("index out of bounds");
        return (_data[index]);
    };

    unsigned int size() const { return (_size); }

private:
    unsigned int _size;
    T *_data;
};

#endif