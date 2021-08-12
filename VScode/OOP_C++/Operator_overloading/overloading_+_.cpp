#include <iostream>

// Вспомним, как выглядит перегрузка оператора через дружественную функцию:

class Dollars
{
private:
    int m_dollars;
 
public:
    Dollars(int dollars) { m_dollars = dollars; }
 
    // Выполняем Dollars + int
    friend Dollars operator+(const Dollars &dollars, int value);
 
    int getDollars() { return m_dollars; }
};
 
// Примечание: Эта функция не является методом класса!
Dollars operator+(const Dollars &dollars, int value)
{
    return Dollars(dollars.m_dollars + value);
}
 
int main()
{
	Dollars dollars1(7);
	Dollars dollars2 = dollars1 + 3;
	std::cout << "I have " << dollars2.getDollars() << " dollars.\n";
 
	return 0;
}