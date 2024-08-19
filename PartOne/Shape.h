#pragma once
#define MEGABYTE 1024 * 1024

class Shape
{
public:
    Shape(unsigned int size = 1);
    Shape(const Shape &other);
    ~Shape();

public:
    Shape &operator=(const Shape &other);
    unsigned int size() const;

private:
    char *_data = nullptr;
    unsigned int _size;
};

Shape::Shape(unsigned int size)
    : _size(size)
{
    _data = new char[_size * MEGABYTE];
}

Shape::Shape(const Shape &other)
    : _size(other._size)
{
    _data = new char[_size * MEGABYTE];
}

Shape::~Shape()
{
    delete[] _data;
}

Shape &Shape::operator=(const Shape &other)
{
    if (this != &other)
    {
        delete[] _data;
        _size = other._size;
        _data = new char[_size * MEGABYTE];
    }

    return *this;
}

unsigned int Shape::size() const
{
    return _size;
}