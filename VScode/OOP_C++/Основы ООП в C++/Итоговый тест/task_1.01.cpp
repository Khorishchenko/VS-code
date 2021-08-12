#include <iostream>
#include <cmath>

// a) Напишите класс с именем Point. В классе Point должны быть две переменные-члены типа double: m_a и m_b со значениями по умолчанию 0.0. 
// Напишите конструктор для этого класса и функцию вывода print().

// b) Теперь добавим метод distanceTo(), который будет принимать второй объект класса Point в качестве параметра и будет 
// вычислять расстояние между двумя объектами. Учитывая две точки (a1, b1) и (a2, b2),
//  расстояние между ними можно вычислить следующим образом: sqrt((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2)). 
// Функция sqrt находится в заголовочном файле cmath.

// b



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

        int distanceTo(Point &Obj){
            return sqrt((this->m_a - Obj.m_a) * (this->m_a - Obj.m_a) + (this->m_b - Obj.m_b) * (this->m_b - Obj.m_b));
        }
};


int main()
{
    Point first;
    Point second(2.0, 5.0);
    first.print();
    second.print();
    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';
 
    return 0;
}