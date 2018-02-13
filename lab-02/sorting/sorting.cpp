#include <algorithm>
#include <iostream>
#include <iterator>
#include <functional>
#include <vector>

template <class It>
void bad_sort(It first, It last)
{
    for (It i = first; i != last; ++i)
    {
        for (It k = i; k != last; ++k)
        {
            if (*k < *i)
            {
                std::iter_swap(i, k);
            }
        }
    }
}

template <class It, class Cmp>
void bad_sort(It first, It last, Cmp cmp)
{
    for (It i = first; i != last; ++i)
    {
        for (It k = i; k != last; ++k)
        {
            if (cmp(*k, *i))
            {
                std::iter_swap(i, k);
            }
        }
    }
}

// or std::greater<>
struct Great
{
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};

template <class T>
struct CountingLess
{
    int Count = 0;

    bool operator()(T a, T b)
    {
        ++Count;
        return a < b;
    }
};


int main()
{
    std::vector<int> v = {15, 25, -11, 10, 13};

    bad_sort(v.begin(), v.end());
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;


    Great gr;
    bad_sort(v.begin(), v.end(), gr);
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;


    CountingLess<int> less;
    bad_sort(v.begin(), v.end(), std::ref(less));
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::cout << "less.Count = " << less.Count << std::endl;


    less.Count = 0;
    sort(v.begin(), v.end(), std::ref(less));
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::cout << "less.Count = " << less.Count << std::endl;

    return 0;
}
