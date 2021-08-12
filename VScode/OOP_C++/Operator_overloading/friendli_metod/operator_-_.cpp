#include <iostream>
 
class Dollars
{
private:
	int m_dollars;
 
public:
	Dollars(int dollars) { m_dollars = dollars; }
 
	// Выполняем Dollars + Dollars через дружественную функцию
	friend Dollars operator+(const Dollars &d1, const Dollars &d2);
 
	// Выполняем Dollars - Dollars через дружественную функцию
	friend Dollars operator-(const Dollars &d1, const Dollars &d2);
 
	int getDollars() const { return m_dollars; }
};
 
// Примечание: Эта функция не является методом класса!
Dollars operator+(const Dollars &d1, const Dollars &d2)
{
	// Используем конструктор Dollars и operator+(int, int).
	// Мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
	return Dollars(d1.m_dollars + d2.m_dollars);
}
 
// Примечание: Эта функция не является методом класса!
Dollars operator-(const Dollars &d1, const Dollars &d2)
{
	// Используем конструктор Dollars и operator-(int, int).
	// Мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
	return Dollars(d1.m_dollars - d2.m_dollars);
}
 
int main()
{
	Dollars dollars1(5);
	Dollars dollars2(3);
	Dollars dollarsSum = dollars1 - dollars2;
	std::cout << "I have " << dollarsSum.getDollars() << " dollars." << std::endl;
 
	return 0;
}