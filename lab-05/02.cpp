#include <iostream>
#include <string>


class Human
{
    std::string Name;
public:
    ~Human() = default;

    virtual std::string GetId() const
    {
        return Name;
    }

    void SetName(const std::string& name)
    {
        Name = name;
    }
};

class Student
    : public Human
{
    std::string Group;
public:
    std::string GetId() const override
    {
        return Group + ":" + Human::GetId();
    }

    void SetGroup(const std::string& group)
    {
        Group = group;
    }
};

int main()
{
    Human h;
    h.SetName("Vasya");
    std::cout << h.GetId() << std::endl;


    Student s;
    s.SetGroup("IU8");
    s.SetName("Slava");
    std::cout << s.GetId() << std::endl;
    std::cout << static_cast<Human>(s).GetId() << std::endl;

}