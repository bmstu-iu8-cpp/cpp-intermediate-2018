#include <iostream>
#include <stdexcept>

struct Dummy
{
    Dummy()
    {
        std::cout << "Dummy" << std::endl;
    }
    ~Dummy()
    {
        std::cout << "~Dummy" << std::endl;
    }
};

void someFunc()
{
    throw std::runtime_error("some error");
}

int main()
{
    try
    {
        Dummy d;
        someFunc();
    }
    catch (const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Dummy * d = new Dummy();
        someFunc();

        // memory leak!!!
        delete d;
    }
    catch (const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}
