#ifndef INTARRAY_H
#define INTARRAY_H

#include <exception>

typedef  size_t; 

class IntegerArray
{
public:
    class BadIndex : public std::bad_exception {};
    class BadLength : public std::bad_exception {};

private:
    int* _data;
    size_t _size;
    size_t _capacity;

    void resize();

public:
    IntegerArray();
    IntegerArray(size_t);
    IntegerArray(size_t, int);
    ~IntegerArray();

    size_t size() const;
    size_t size();

    IntegerArray(const IntegerArray&);
    IntegerArray(IntegerArray&&);

    int& get(size_t);
    int& get(size_t) const;
    void resize(size_t);
    void push_back(int);

};

#endif