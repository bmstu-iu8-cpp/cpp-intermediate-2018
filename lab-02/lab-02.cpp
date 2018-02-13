#include <string>
#include <vector>

#include "Point2d.h"
#include "factorial.h"


template <class T>
T min(T a, T b)
{
    return (a < b) ? a : b;
}

template <>
const char* min(const char* a, const char* b)
{
    return (strcmp(a, b) < 0) ? a : b;
}

int main()
{
    {
        std::cout << min<int>(1, -1) << std::endl;

        std::cout << min(0.1, -1.1) << std::endl;

        std::cout << min(std::string("aaa"), std::string("bbb")) << std::endl;

        const char * str1 = "aaa";
        const char * str2 = "bbb";
        std::cout << min(str1, str2) << std::endl;
    }


    {
        std::cout << "6! = " << fact<6>() << std::endl;
        std::cout << "7! = " << fact<7>() << std::endl;
    }


    {
        Point2d<float> p(1.2, 1.2);
        // p.some_error_func();

        Point2d<float> pi(1, 2);
    }
}
