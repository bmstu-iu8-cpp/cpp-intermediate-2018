#include <iostream>
#include <stdexcept>

void solve(float a, float b, float c, float &x1, float &x2)
{
    float d = (b * b) - (4 * a * c);

    if (d < 0)
    {
        throw std::logic_error("error d < 0!");
    }

    x1 = (-b - std::sqrtf(d)) / (2 * a);
    x2 = (-b + std::sqrtf(d)) / (2 * a);
}

int main()
{
    try
    {
        float x1 = 0;
        float x2 = 0;

        solve(1, -6, 5, x1, x2);
        std::cout << "x1=" << x1 << ", x2=" << x2 << std::endl;

        solve(1, 0, 2, x1, x2);
        std::cout << "x1=" << x1 << ", x2=" << x2 << std::endl;
    }
    catch (const std::logic_error & e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
