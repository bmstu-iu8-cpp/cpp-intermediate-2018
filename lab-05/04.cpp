#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct Warrior
{
    void Attack() const
    {
        std::cout << "Warrior in attack" << std::endl;
    }
};

struct Archer
{
    void Attack() const
    {
        std::cout << "Archer in attack" << std::endl;
    }
};


template <typename T>
void InAttack(const T& unit)
{
    unit.Attack();
}

int main()
{
    Warrior w;
    Archer a;

    InAttack(w);
    InAttack(a);
}