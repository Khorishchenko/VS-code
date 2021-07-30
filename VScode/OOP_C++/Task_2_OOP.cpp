#include <iostream>

// a) Напишите простой класс с именем Numbers. Этот класс должен иметь:

//    три закрытые переменные-члены типа double: m_a, m_b и m_c;
//    открытый метод с именем setValues(), который позволит устанавливать значения для m_a, m_b и m_c;
//    открытый метод с именем print(), который будет выводить объект класса Numbers в следующем формате: <m_a, m_b, m_c>.

// Следующий код функции main():

// b) Добавьте функцию isEqual() в класс Numbers, чтобы следующий код работал корректно:



class Numbers
{
    private:
        int m_a;
        int m_b;
        int m_c;

    public:
        void setValues(int a, int b, int c){
            m_a = a;
            m_c = c;
            m_b = b;
        }

        void print(){
            std::cout << '<' << m_a << ',' << m_b << ',' << m_c << '>' << std::endl;
        }
        bool isEqual(const Numbers &Obj){
            if (m_a == Obj.m_a && m_b == Obj.m_b && m_c == Obj.m_c)
                return true;
            else
                return false;
        }
};

int main()
{
    Numbers point1;
    point1.setValues(3.0, 4.0, 5.0);
 
    Numbers point2;
    point2.setValues(3.0, 4.0, 5.0);

    point1.print();
 
    if (point1.isEqual(point2))
        std::cout << "point1 and point2 are equal\n";
    else
        std::cout << "point1 and point2 are not equal\n";
 
    Numbers point3;
    point3.setValues(7.0, 8.0, 9.0);
 
    if (point1.isEqual(point3))
        std::cout << "point1 and point3 are equal\n";
    else
        std::cout << "point1 and point3 are not equal\n";

    return 0;
}