#include <iostream>

#include "Point2d.h"

int main()
{
    Point2d a;

    std::cout << a[0] << " " << a[1] << std::endl;
    a[0] = 1;
    a[1] = 2;
    
    Point2d b(a);
    std::cout << std::boolalpha << (b == a) << std::endl;

    b[0] = -1;
    std::cout << b[0] << " " << b[1] << std::endl;
    
    a = b;
    std::cout << std::boolalpha << (b == a) << std::endl;

    a += b;
    std::cout << std::boolalpha << (b != a) << std::endl;
    std::cout << a[0] << " " << a[1] << std::endl;
}