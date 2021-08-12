#include <iostream>

// b) Добавьте перегрузку оператора умножения (*) для выполнения операции умножения объекта класса Fraction на 
// целочисленное значение и для перемножения двух объектов класса Fraction. Используйте способ перегрузки оператора через дружественную функцию.


class Fraction
{
    private:
        int m_numerator;
        int m_denominator;
    public:
        Fraction(int x = 0, int y = 1) : m_numerator(x), m_denominator(y) {}

        void print(){
            std::cout << m_numerator << '/' << m_denominator << std::endl;
        }

        friend Fraction operator *(const Fraction &Obj, const Fraction &Obj_2);
        friend Fraction operator *(const Fraction &Obj, int value);
        friend Fraction operator *(int value, const Fraction &Obj);
};


Fraction operator *(const Fraction &Obj, const Fraction &Obj_2){
            return Fraction(Obj.m_numerator * Obj_2.m_numerator, Obj.m_denominator * Obj_2.m_denominator);
}

Fraction operator *(const Fraction &Obj, int value){
    return Fraction(Obj.m_numerator * value, Obj.m_denominator);
}

Fraction operator *(int value, const Fraction &Obj){
    return Fraction(Obj.m_numerator * value, Obj.m_denominator);
}


int main()
{
   Fraction f1(3, 4);
    f1.print();
 
    Fraction f2(2, 7);
    f2.print();
 
    Fraction f3 = f1 * f2;
    f3.print();
 
    Fraction f4 = f1 * 3;
    f4.print();
 
    Fraction f5 = 3 * f2;
    f5.print();
 
    Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
    f6.print();
}