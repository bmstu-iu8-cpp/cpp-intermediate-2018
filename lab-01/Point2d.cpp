#include "Point2d.h"


// Конструктор по умолчанию
// обнулим переменные, чтобы в них не было "мусора"
Point2d::Point2d()
// используем список инициализации
// так быстрее, чем если инициализировать поля в теле конструктора
    : X(0)
    , Y(0)
{
    // X = 0;
    // Y = 0;
}

// ничего не делаем
// т.к. класс не владеет никакими ресурсами (динамическая память, дескрипторы файлов, мьютексы и др.) 
Point2d::~Point2d()
{ }

Point2d::Point2d(int x, int y)
    : X(x)
    , Y(y)
{ }

Point2d::Point2d(const Point2d & p)
    : X(p.X)
    , Y(p.Y)
{ }

Point2d::Point2d(const std::pair<int, int>& p)
    : X(p.first)
    , Y(p.second)
{ }

Point2d & Point2d::operator=(const Point2d &p)
{
    // если передаваемый аргумент является "нами",
    // то ничего не делаем
    if (this != &p)
    {
        X = p.X;
        Y = p.Y;
    }

    // возвращаем ссылку на себя
    return *this;
}

bool Point2d::operator==(const Point2d & p) const
{
    return (X == p.X) && (Y == p.Y);
}

Point2d & Point2d::operator+=(const Point2d & p)
{
    X += p.X;
    Y += p.Y;

    // возвращаем ссылку на себя
    return *this;
}

int Point2d::operator[](int ind) const
{
    // если ind == 0, вернем X
    // если ind == 1, вернем Y
    // иначе, сгенерируем исключение 
    if (ind == 0)
        return X;
    else if (ind == 1)
        return Y;
    throw std::runtime_error("wrong argument");
}

int & Point2d::operator[](int ind)
{
    if (ind == 0)
        return X;
    else if (ind == 1)
        return Y;
    throw std::runtime_error("wrong argument");
}

Point2d operator+(const Point2d & p, const Point2d & q)
{
    // реализовывает +, через +=

    Point2d c(p);
    c += q;
    return c;
}

bool operator!=(const Point2d & p, const Point2d & q)
{
    // реализовываем != , через ==
    return !(p == q);
}

std::ostream & operator<<(std::ostream & out, const Point2d & p)
{
    out << p[0] << " " << p[1];
    return out;
}
