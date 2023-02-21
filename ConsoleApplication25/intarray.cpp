#include "intarrray.h"
#include <iostream>

IntegerArray::IntegerArray()
    : _size(0)
    , _capacity(0)
    , _data(0)
{
}

IntegerArray::IntegerArray(size_t size)
    : _size(size)
    , _capacity(size)
    , _data(new int[size])
{
}

IntegerArray::IntegerArray(size_t size, int defaultVal)
    : _size(size)
    , _capacity(size)
    , _data(new int[size])
{
    for (int i = 0; i < size; ++i) {
        _data[i] = defaultVal;
    }
}

IntegerArray::~IntegerArray() {
    delete[] _data;
}

IntegerArray::IntegerArray(const IntegerArray& other)
    : _size(other._size)
    , _capacity(other._capacity)
    , _data(new int[other._capacity])
{
    for (int i = 0; i < _size; ++i) {
        _data[i] = other._data[i];
    }
}

IntegerArray::IntegerArray(IntegerArray&& other)
    : _size(other._size)
    , _capacity(other._capacity)
    , _data(other._data)
{
    //
}
size_t IntegerArray::size() const {
    return _size;
}

size_t IntegerArray::size() {
    return _size;
}

int& IntegerArray::get(size_t index) {
    if (index < _size) {
        return _data[index];
    }
    else {
        throw BadIndex();
    }
}

int& IntegerArray::get(size_t index) const {
    if (index < _size) {
        return _data[index];
    }
    else {
        throw BadIndex();
    }
}

void IntegerArray::resize(size_t newSize) {
    if (_size >= newSize) {
        _size = newSize;
    }
    else if (_capacity >= newSize) {
        for (int i = _size; i < newSize; ++i) {
            push_back(0);//bad
        }
    }
    else {
        resize();
        resize(newSize);//bad
    }
}

void IntegerArray::resize() {
    _capacity = (_capacity * 2) + 1;
    int* newData = new int[_capacity];
    for (int i = 0; i < _size; ++i) {
        newData[i] = _data[i];
    }
    delete[] _data;
    _data = newData;
}

void IntegerArray::push_back(int value) {
    if (_size >= _capacity) {
        resize();
    }
    _data[_size] = value;
    ++_size;
}


