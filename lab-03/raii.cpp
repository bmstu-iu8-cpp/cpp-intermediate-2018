#include <iostream>
#include <exception>

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

// implement RAII
class DummyRAII
{
    Dummy * Ptr;

public:
    explicit DummyRAII(Dummy* ptr);
    ~DummyRAII();

    DummyRAII& operator=(const DummyRAII&) = delete;
    DummyRAII(const DummyRAII&) = delete;
};

int main()
{
    try
    {
        Dummy * raw = new Dummy();
        DummyRAII guard(raw);

        throw std::runtime_error("some error");
    }
    catch (const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}
