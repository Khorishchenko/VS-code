#include <iostream>

// Виртуальные функции и Полиморфизм

class Parent
{
public:
    const char* getName() { return "Parent"; }
};
 
class Child: public Parent
{
public:
    const char* getName() { return "Child"; }
};
 
// int main()
// {
//     Child child;
//     Parent &rParent = child;
//     std::cout << "rParent is a " << rParent.getName() << '\n';
// }


// Чтобы сделать функцию виртуальной, нужно просто указать ключевое слово virtual перед объявлением функции. Например:

class Parent_2
{
public:
    virtual const char* getName() { return "Parent_2"; } // добавили ключевое слово virtual
};
 
class Child_2: public Parent_2
{
public:
    virtual const char* getName() { return "Child_2"; }
};
 
int main()
{
    Child_2 child;
    Parent_2 &rParent = child;
    std::cout << "rParent is a " << rParent.getName() << '\n';
 
    return 0;
}