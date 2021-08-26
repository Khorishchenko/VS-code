// Перегрузка операторов сравнения

// Поскольку все операторы сравнения являются бинарными и не изменяют свои левые операнды, 
// то выполнять перегрузку следует через дружественные функции.

// Например, перегрузим оператор равенства == и оператор неравенства != для класса Car:



#include <iostream>
#include <string>
 
class Car
{
private:
    std::string m_company;
    std::string m_model;
 
public:
    Car(std::string company, std::string model)
        : m_company(company), m_model(model)
    {
    }
 
    friend bool operator== (const Car &c1, const Car &c2);
    friend bool operator!= (const Car &c1, const Car &c2);
};
 
bool operator== (const Car &c1, const Car &c2)
{
    return (c1.m_company == c2.m_company &&
            c1.m_model == c2.m_model);
}
 
bool operator!= (const Car &c1, const Car &c2)
{
    return !(c1== c2);
}
 
// int main()
// {
//     Car mustang("Ford", "Mustang");
//     Car logan("Renault", "Logan");
 
//     if (mustang == logan)
//         std::cout << "Mustang and Logan are the same.\n";
 
//     if (mustang != logan)
//         std::cout << "Mustang and Logan are not the same.\n";
 
//     return 0;
// }


// Перегрузим операторы сравнения >, <, >= и <=:


class Dollars
{
private:
    int m_dollars;
 
public:
    Dollars(int dollars) { m_dollars = dollars; }
 
    friend bool operator> (const Dollars &d1, const Dollars &d2);
    friend bool operator<= (const Dollars &d1, const Dollars &d2);
 
    friend bool operator< (const Dollars &d1, const Dollars &d2);
    friend bool operator>= (const Dollars &d1, const Dollars &d2);
};
 
bool operator> (const Dollars &d1, const Dollars &d2)
{
    return d1.m_dollars > d2.m_dollars;
}
 
bool operator>= (const Dollars &d1, const Dollars &d2)
{
    return d1.m_dollars >= d2.m_dollars;
}
 
bool operator< (const Dollars &d1, const Dollars &d2)
{
    return d1.m_dollars < d2.m_dollars;
}
 
bool operator<= (const Dollars &d1, const Dollars &d2)
{
    return d1.m_dollars <= d2.m_dollars;
}
 
int main()
{
    Dollars ten(10);
    Dollars seven(7);
 
    if (ten > seven)
        std::cout << "Ten dollars are greater than seven dollars.\n";
    if (ten >= seven)
        std::cout << "Ten dollars are greater than or equal to seven dollars.\n";
    if (ten < seven)
        std::cout << "Seven dollars are greater than ten dollars.\n";
    if (ten <= seven)
        std::cout << "Seven dollars are greater than or equal to ten dollars.\n";
 
    return 0;
}