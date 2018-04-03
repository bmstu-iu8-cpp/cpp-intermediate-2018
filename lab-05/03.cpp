#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct Unit
{
    ~Unit() = default;
    virtual void Attack() = 0;
};

struct Warrior
    : Unit
{
    void Attack() override
    {
        std::cout << "Warrior in attack" << std::endl;
    }
};

struct Archer
    : Unit
{
    void Attack() override
    {
        std::cout << "Archer in attack" << std::endl;
    }
};

int main()
{
    // Unit u;

    Warrior w;
    w.Attack();
    std::cout << "----------------" << std::endl;

    Archer a;
    a.Attack();
    std::cout << "----------------" << std::endl;

    Unit* pW = new Warrior();
    pW->Attack();
    delete pW;
    std::cout << "----------------" << std::endl;

    Unit* pA = new Archer();
    pA->Attack();
    delete pA;
    std::cout << "----------------" << std::endl;

    std::vector<Unit*> v;
    v.push_back(new Warrior());
    v.push_back(new Archer());
    v.push_back(new Archer());
    v.push_back(new Archer());
    for (Unit* p : v)
    {
        p->Attack();
    }
    for (Unit* p : v)
    {
        delete p;
    }
    v.clear();
    std::cout << "----------------" << std::endl;


    std::unique_ptr<Unit> ptr { new Archer() };
    ptr->Attack();
    std::cout << "----------------" << std::endl;


    std::vector<std::unique_ptr<Unit>> v2;
    v2.emplace_back(new Archer());
    v2.emplace_back(new Warrior());
    v2.emplace_back(new Warrior());
    for (auto& p : v2)
    {
        p->Attack();
    }
}