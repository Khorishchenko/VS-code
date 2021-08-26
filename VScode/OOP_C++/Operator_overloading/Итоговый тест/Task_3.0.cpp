#include <iostream>
#include <cassert>
#include <cmath>

// b) Напишите класс FixedPoint, который реализует рекомендуемое решение из предыдущего задания. 
// Если дробная или целая части значения являются отрицательными, то число должно рассматриваться, как отрицательное. 
// Реализуйте перегрузку необходимых операторов и напишите необходимые конструкторы, чтобы следующий код функции main():


// c) Теперь добавьте конструктор, который будет принимать значение типа double. 
// Вы можете округлить целую часть (слева от точки) с помощью функции round() (которая находится в заголовочном файле cmath).

// Подсказки:

//    Вы можете получить целую часть от числа типа double путем конвертации числа типа double в число типа int.

//    Для перемещения одной цифры влево от точки используйте умножение на 10. Для перемещения двух цифр используйте умножение на 100.


// d) Выполните перегрузку следующих операторов: ==, >>, − (унарный) и + (бинарный).

//b 
class FixedPoint
{
    private:
        std::int16_t  value_1;
        std::int8_t   value_2;

    public:
        FixedPoint(std::int16_t val_1 = 0, std::int8_t  val_2 = 0) 
            : value_1(val_1), value_2(val_2)
            {
                assert(value_2 < 99 || value_2 < -99);

                if (value_1 < 0.0 || value_2 < 0.0)
                {
                    if (value_1 > 0.0)
                        value_1 = -value_1;
                    if (value_2 < 0.0)
                        value_2 = -value_2;
                }
            }
        //c
        FixedPoint(double d) {
            value_1 = static_cast<int16_t>(d);
            value_2 = static_cast<std::int8_t>(round((d - value_1) * 100));
        }
        
         FixedPoint operator- () {
            return FixedPoint(-value_1, -value_2);
        }

        operator double () const;
        friend std::ostream& operator<< (std::ostream &out, const FixedPoint &fixapoint);
        friend FixedPoint operator+ (const FixedPoint &fixpoint, const FixedPoint &fixpoi);
        friend bool operator== (const FixedPoint &fixpoint, const FixedPoint &fixpoin);
        friend std::istream& operator>> (std::istream &in, FixedPoint &fp);
};

FixedPoint::operator double() const {
    return value_1 + static_cast<double>(value_2) / 100;
}


std::ostream& operator<< (std::ostream &out, const FixedPoint &fixpoint){
    out << static_cast<double>(fixpoint);
	return out;
}

FixedPoint operator+ (const FixedPoint &fixpoint, const FixedPoint &fixpoin){
    // return FixedPoint(fixpoint.value_1 + fixpoin.value_1, fixpoint.value_2 + fixpoin.value_2);
    // more best
    return FixedPoint(static_cast<double>(fixpoint) + static_cast<double>(fixpoin));
}

bool operator== (const FixedPoint &fixpoint, const FixedPoint &fixpoin){
    return(fixpoint.value_1 == fixpoin.value_1 && fixpoint.value_2 == fixpoin.value_2);
}

std::istream& operator>> (std::istream &in, FixedPoint &fp){
    double d;
	in >> d;
	fp = FixedPoint(d);
 
	return in;
}



void SomeTest()
{
	std::cout << std::boolalpha;
	std::cout << (FixedPoint(0.75) + FixedPoint(1.23) == FixedPoint(1.98)) << '\n'; // оба значения положительные, никакого переполнения
	std::cout << (FixedPoint(0.75) + FixedPoint(1.50) == FixedPoint(2.25)) << '\n'; // оба значения положительные, переполнение
	std::cout << (FixedPoint(-0.75) + FixedPoint(-1.23) == FixedPoint(-1.98)) << '\n'; // оба значения отрицательные, никакого переполнения
	std::cout << (FixedPoint(-0.75) + FixedPoint(-1.50) == FixedPoint(-2.25)) << '\n'; // оба значения отрицательные, переполнение
	std::cout << (FixedPoint(0.75) + FixedPoint(-1.23) == FixedPoint(-0.48)) << '\n'; // второе значение отрицательное, никакого переполнения
	std::cout << (FixedPoint(0.75) + FixedPoint(-1.50) == FixedPoint(-0.75)) << '\n'; // второе значение отрицательное, возможно переполнение
	std::cout << (FixedPoint(-0.75) + FixedPoint(1.23) == FixedPoint(0.48)) << '\n'; // первое значение отрицательное, никакого переполнения
	std::cout << (FixedPoint(-0.75) + FixedPoint(1.50) == FixedPoint(0.75)) << '\n'; // первое значение отрицательное, возможно переполнение
}


int main()
{
	FixedPoint a(37, 58);
	std::cout << a << '\n';
 
	FixedPoint b(-3, 9);
	std::cout << b << '\n';
 
	FixedPoint c(4, -7);
	std::cout << c << '\n';
 
	FixedPoint d(-5, -7);
	std::cout << d << '\n';
 
	FixedPoint e(0, -3);
	std::cout << e << '\n';
 
	std::cout << static_cast<double>(e) << '\n';

    std::cout << "==========================================" << '\n' << std::endl;

    FixedPoint p(0.03);
	std::cout << p << '\n';
 
	FixedPoint f(-0.03);
	std::cout << f << '\n';
 
	FixedPoint q(4.01); // сохранится, как 4.0099999..., поэтому нам нужно это всё округлить
	std::cout << q << '\n';
 
	FixedPoint g(-4.01); // сохранится, как -4.0099999..., поэтому нам нужно это всё округлить
	std::cout << g << '\n';

    std::cout << "==========================================" << '\n' << std::endl;

    SomeTest();
 
	FixedPoint m(-0.48); 
	std::cout << m << '\n';
 
	std::cout << -m << '\n';
 
	std::cout << "Enter m number: "; // введите 5.678
	std::cin >> m;
	
	std::cout << "You entered: " << m << '\n';
 
	return 0;
}