#pragma once

#include <iostream>
#include <map>

template <class T>
class Point2d
{
    T X;
    T Y;

public:
    ~Point2d() = default;

    Point2d()
        : X(0)
        , Y(0)
    { }

    Point2d(T x, T y)
        : X(x)
        , Y(y)
    { }

    Point2d(const Point2d& p)
        : X(p.X)
        , Y(p.Y)
    { }

    explicit Point2d(const std::pair<T, T>& p)
        : X(p.first)
        , Y(p.second)
    { }

    Point2d& operator=(const Point2d& p)
    {
        X = p.X;
        Y = p.Y;

        return *this;
    }

    bool operator==(const Point2d& p) const
    {
        return (X == p.X) && (Y == p.Y);
    }

    Point2d& operator+=(const Point2d& p)
    {
        X += p.X;
        Y += p.Y;

        return *this;
    }

    T operator[](int ind) const
    {
        if (ind == 0)
            return X;
        else if (ind == 1)
            return Y;
        throw std::runtime_error("wrong argument");
    }

    T& operator[](int ind)
    {
        if (ind == 0)
            return X;
        else if (ind == 1)
            return Y;
        throw std::runtime_error("wrong argument");
    }

    size_t compilationError() const
    {
        std::vector<int> v;
        return v.Size();
    }
};

template <class T>
Point2d<T> operator+(const Point2d<T>& p, const Point2d<T>& q)
{
    Point2d<T> c(p);
    c += q;
    return c;
}

template <class T>
bool operator!=(const Point2d<T>& p, const Point2d<T>& q)
{
    return !(p == q);
}

template <class T>
std::ostream& operator<<(std::ostream& out, const Point2d<T>& p)
{
    out << p[0] << " " << p[1];
    return out;
}
