#include <iostream>

// Задание №1
// a) Напишите класс с именем Point. В классе Point должны быть две переменные-члены типа double: m_a и m_b со значениями по умолчанию 0.0. 
// Напишите конструктор для этого класса и функцию вывода print().

// a

class Point
{
    private:
        double m_a;
        double m_b;

    public:
        Point(double a = 0.0, double b = 0.0) : m_a(a), m_b(b) {}

        void print(){
            std::cout << '(' << m_a << ", " << m_b << ')' << std::endl;
        }
};


int main()
{
    Point first;
    Point second(2.0, 5.0);
    first.print();
    second.print();
 
    return 0;
}