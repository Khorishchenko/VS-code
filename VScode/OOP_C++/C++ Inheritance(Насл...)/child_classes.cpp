#include <iostream>

// Урок №155. Порядок построения дочерних классов

// Заключение

// Язык C++ выполняет построение дочерних классов поэтапно, начиная с верхнего класса иерархии и заканчивая нижним классом иерархии. 
// По мере построения каждого класса для выполнения инициализации вызывается соответствующий конструктор соответствующего класса.

// На следующем уроке мы рассмотрим роль конструкторов в процессе построения дочерних классов.


class Parent
{
public:
    int m_id;
 
    Parent(int id=0)
        : m_id(id)
    {
        std::cout << "Parent\n";
    }
 
    int getId() const { return m_id; }
};
 
class Child: public Parent
{
public:
    double m_value;
 
    Child(double value=0.0)
        : m_value(value)
    {
        std::cout << "Child\n";
    }
 
    double getValue() const { return m_value; }
};
 
// int main()
// {
//     std::cout << "Instantiating Parent:\n";
//     Parent dParent;
 
//     std::cout << "Instantiating Child:\n";
//     Child dChild;
 
//     return 0;
// }


//====================================================================================//

class A
{
public:
    A()
    {
        std::cout << "A\n";
    }
};
 
class B: public A
{
public:
    B()
    {
        std::cout << "B\n";
    }
};
 
class C: public B
{
public:
    C()
    {
        std::cout << "C\n";
    }
};
 
class D: public C
{
public:
    D()
    {
        std::cout << "D\n";
    }
};


int main()
{
    std::cout << "Constructing A: \n";
    A cA;
 
    std::cout << "Constructing B: \n";
    B cB;
 
    std::cout << "Constructing C: \n";
    C cC;
 
    std::cout << "Constructing D: \n";
    D cD;
}