#include <iostream>

// a) Напишите класс Fraction, который имеет два целочисленных члена: числитель и знаменатель. Реализуйте функцию print(), которая будет выводить дробь.




class Fraction
{
    private:
        int m_x;
        int m_y;
    public:
        Fraction(int x, int y) : m_x(x), m_y(y) {}

        void print(){
            std::cout << m_x << '/' << m_y << std::endl;
        }

};


int main()
{
    Fraction f1(1, 4);
    f1.print();
 
    Fraction f2(1, 2);
    f2.print();
}