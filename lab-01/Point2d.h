#pragma once
#include <iostream>
#include <map>

class Point2d
{
    int X;
    int Y;
public:
    Point2d();
    ~Point2d();
    Point2d(int x, int y);
    Point2d(const Point2d& p);

    // ≈сли конструктор принимает один аргумент, его прин¤то объ¤вл¤ть explicit
    explicit Point2d(const std::pair<int, int>& p);

    // оператор присваивани¤
    Point2d& operator=(const Point2d&);

    // const в конце означает, что это константный метод
    // такие методы не измен¤ют пол¤ объекта
    bool operator==(const Point2d& p) const;

    Point2d& operator+=(const Point2d& p);

    int operator[](int) const;
    int& operator[](int);
};

Point2d operator+(const Point2d& p, const Point2d& q);
bool operator!=(const Point2d& p, const Point2d& q);

std::ostream& operator<<(std::ostream& out, const Point2d& p);
