#include <iostream>
#include <cassert>

// class Drob
// {
// private:
//     int m_numerator;
//     int m_denominator;
 
// public:
//     // Конструктор по умолчанию
//     Drob(int numerator=0, int denominator=1) :
//         m_numerator(numerator), m_denominator(denominator)
//     {
//         assert(denominator != 0);
//     }
 
//     friend std::ostream& operator<<(std::ostream& out, const Drob &d1);
// };
 
// std::ostream& operator<<(std::ostream& out, const Drob &d1)
// {
// 	out << d1.m_numerator << "/" << d1.m_denominator;
// 	return out;
// }
 
// int main()
// {
// 	Drob sixSeven(6, 7); // прямая инициализация объекта класса Drob, вызывается конструктор Drob(int, int)
// 	Drob dCopy(sixSeven); // прямая инициализация - какой конструктор вызывается здесь?
// 	std::cout << dCopy << '\n';
// }

#include <iostream> 
#include <cassert>
 
class Dro
{
private:
    int m_numerator;
    int m_denominator;
 
public:
    // Конструктор по умолчанию
    Dro(int numerator=0, int denominator=1) :
        m_numerator(numerator), m_denominator(denominator)
    {
        assert(denominator != 0);
    }
 
    // Конструктор копирования
    Dro(const Dro &drob) :
        m_numerator(drob.m_numerator), m_denominator(drob.m_denominator)
        // Примечание: Мы имеем прямой доступ к членам объекта drob, поскольку мы сейчас находимся внутри класса Dro
    {
        // Нет необходимости выполнять проверку denominator здесь, так как эта проверка уже осуществляется в конструкторе класса Dro
        std::cout << "Copy constructor worked here!\n"; // просто, чтобы показать, что это работает
    }
 
    friend std::ostream& operator<<(std::ostream& out, const Dro &d1);
};
 
std::ostream& operator<<(std::ostream& out, const Dro &d1)
{
	out << d1.m_numerator << "/" << d1.m_denominator;
	return out;
}
 
int main()
{
	Dro sixSeven(6, 7); // прямая инициализация объекта класса Dro, вызывается конструктор Dro(int, int)
	Dro dCopy(sixSeven); // прямая инициализация, вызывается конструктор копирования класса Dro
	std::cout << dCopy << '\n';
}

// Конструктор копирования в вышеприведенном примере использует почленную инициализацию и функционально эквивалентен конструктору по умолчанию, за исключением того, 
// что мы добавили стейтмент вывода, в котором указали текст (сработал конструктор копирования).


