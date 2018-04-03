#include <algorithm>
#include <iostream>
#include <string>

// private наследование говорит, что "класс реализован с помощью другого класса"
// в нашем случае
// Sentence реализован с помощью std::string
struct Sentence
    : private std::string
{
    size_t NumWords() const
    {
        return std::count(begin(), end(), ' ') - 1;
    }

    Sentence(const std::string& s)
        : std::string(s)
    {
    }
    
    bool IsQuestion() const
    {
        return EndWith('?');
    }

    bool IsExclamatory() const
    {
        return EndWith('!');
    }

private:
    
    bool EndWith(char c) const
    {
        if (empty())
            return false;

        return *rbegin() == c;
    }
};

int main()
{
    Sentence s("Hello, world!");
    std::cout << s.NumWords() << std::endl;
    std::cout << std::boolalpha << s.IsExclamatory() << std::endl;
    std::cout << std::boolalpha << s.IsQuestion() << std::endl;
}