#include <iostream>
#include <string>

class Human
{
    std::string Name;
    size_t Age;

public:
    ~Human() = default;

    std::string GetName() const
    {
        return Name;
    }

    void SetName(const std::string& name)
    {
        Name = name;
    }
    
    size_t GetAge() const
    {
        return Age;
    }

    void SetAge(size_t age)
    {
        Age = age;
    }
};

// public наследование говорит выражает отношение "является"
// в нашем случае
// Student является Human
class Student
    : public Human
{
    std::string Group;
public:
    std::string GetGroup() const
    {
        return Group;
    }

    void SetGroup(const std::string& group)
    {
        Group = group;
    }
};

int main()
{
    Human h;
    h.SetAge(21);
    std::cout << h.GetAge() << std::endl;

    Student s;
    s.SetAge(19);
    s.SetGroup("Iu8-21");
    std::cout << s.GetAge() << std::endl;
    std::cout << s.GetGroup() << std::endl;
}