#include <iostream>

// Задание №1
// Создайте класс Numbers, который содержит два целых числа. Этот класс должен иметь две переменные-члены для хранения этих двух целых чисел. 
// Вы также должны создать два метода:

//    метод set(), который позволит присваивать значения переменным;
//    метод print(), который будет выводить значения переменных.

class Numbers
{
    public:
        int m_x;
        int m_y;

        void set(int x, int y){
            m_x = x;
            m_y = y;
        }
        void print(){
            std::cout << "Numbers(" << m_x << ',' << m_y << ')' << std::endl;
        }
};

int main()
{
    Numbers n1;
    n1.set(4, 5);

    Numbers n2{1, 2};

    n1.print();
    n2.print();

    return 0;
}