#include <iostream>

// Урок №158. Добавление нового функционала в дочерний класс

class Parent
{
protected:
    int m_value;
 
public:
    Parent(int value)
        : m_value(value)
    {
    }
 
    void identify() { std::cout << "I am a Parent\n"; }
};


class Child: public Parent
{
public:
    Child(int value)
        : Parent(value)
    {
    }
    // Добавление нового функционала в дочерний класс
    int getValue() { return m_value; }

};

int main()
{
    Child child(7);
    std::cout << "child has value " << child.getValue() << '\n';
 
    return 0;
}

