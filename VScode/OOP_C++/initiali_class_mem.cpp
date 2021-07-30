#include <iostream>

// Списки инициализации членов класса


class Values
{
private:
    int m_value1;
    double m_value2;
    char m_value3;
 
public:
    Values() : m_value1(3), m_value2(4.5), m_value3('d') // напрямую инициализируем переменные-члены класса
    {
    // Нет необходимости использовать присваивание
    }
 
    void print()
    {
         std::cout << "Values(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n";
    }
};
 
int main()
{
    Values value;
    value.print();
    return 0;
}




class Value
{
private:
    int m_value1;
    double m_value2;
    char m_value3;
 
public:
    Value(int value1, double value2, char value3='d')
        : m_value1(value1), m_value2(value2), m_value3(value3) // напрямую инициализируем переменные-члены класса
    {
    // Нет необходимости использовать присваивание
    }
 
    void print()
    {
         std::cout << "Value(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n";
    }
 
};
 
int main()
{
    Value value(3, 4.5); // value1 = 3, value2 = 4.5, value3 = 'd' (значение по умолчанию)
    value.print();
    return 0;
}