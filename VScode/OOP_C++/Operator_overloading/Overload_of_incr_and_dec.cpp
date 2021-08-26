// Перегрузка операторов инкремента и декремента

// Перегрузка операторов инкремента (++) и декремента (−−) довольно-таки проста, но с одним маленьким нюансом. Есть две версии операторов инкремента и декремента: 
// версия префикс (например, ++x, --y) и версия постфикс (например, x++, y--).

// Поскольку операторы инкремента и декремента являются унарными и изменяют свои операнды, то перегрузку следует выполнять через методы класса.

// Перегрузка операторов инкремента и декремента версии префикс


#include <iostream>
 
class Number
{
private:
    int m_number;
public:
    Number(int number=0)
        : m_number(number)
    {
    }
 
    Number& operator++();
    Number& operator--();
 
    friend std::ostream& operator<< (std::ostream &out, const Number &n);
};
 
Number& Number::operator++()
{
    // Если значением переменной m_number является 8, то выполняем сброс значения m_number на 0
    if (m_number == 8)
        m_number = 0;
    // В противном случае, просто увеличиваем m_number на единицу
    else
        ++m_number;
 
    return *this;
}
 
Number& Number::operator--()
{
    // Если значением переменной m_number является 0, то присваиваем m_number значение 8
    if (m_number == 0)
        m_number = 8;
    // В противном случае, просто уменьшаем m_number на единицу
    else
        --m_number;
 
    return *this;
}
 
std::ostream& operator<< (std::ostream &out, const Number &n)
{
	out << n.m_number;
	return out;
}
 
int main()
{
    Number number(7);
 
    std::cout << number;
    std::cout << ++number;
    std::cout << ++number;
    std::cout << --number;
    std::cout << --number;
 
    return 0;
}


// Перегрузка операторов инкремента и декремента версии постфикс

#include <iostream>
 
class Num
{
private:
    int m_number;
public:
    Num(int number=0)
        : m_number(number)
    {
    }
 
    Num& operator++(); // версия префикс
    Num& operator--(); // версия префикс
 
    Num operator++(int); // версия постфикс
    Num operator--(int); // версия постфикс
 
    friend std::ostream& operator<< (std::ostream &out, const Num &n);
};
 
Num& Num::operator++()
{
    // Если значением переменной m_number является 8, то выполняем сброс значения m_number на 0
    if (m_number == 8)
        m_number = 0;
    // В противном случае, просто увеличиваем m_number на единицу
    else
        ++m_number;
 
    return *this;
}
 
Num& Num::operator--()
{
    // Если значением переменной m_number является 0, то присваиваем m_number значение 8
    if (m_number == 0)
        m_number = 8;
    // В противном случае, просто уменьшаем m_number на единицу
    else
        --m_number;
 
    return *this;
}
 
Num Num::operator++(int)
{
    // Создаем временный объект класса Num с текущим значением переменной m_number
    Num temp(m_number);
 
    // Используем оператор инкремента версии префикс для реализации перегрузки оператора инкремента версии постфикс
    ++(*this); // реализация перегрузки
 
    // Возвращаем временный объект
    return temp;
}
 
Num Num::operator--(int)
{
    // Создаем временный объект класса Num с текущим значением переменной m_number
    Num temp(m_number);
 
    // Используем оператор декремента версии префикс для реализации перегрузки оператора декремента версии постфикс
    --(*this); // реализация перегрузки
 
    // Возвращаем временный объект
    return temp; 
}
 
std::ostream& operator<< (std::ostream &out, const Num &n)
{
	out << n.m_number;
	return out;
}
 
int main()
{
    Num number(6);
 
    std::cout << number;
    std::cout << ++number; // вызывается Num::operator++();
    std::cout << number++; // вызывается Num::operator++(int);
    std::cout << number;
    std::cout << --number; // вызывается Num::operator--();
    std::cout << number--; // вызывается Num::operator--(int);
    std::cout << number;
 
    return 0;
}