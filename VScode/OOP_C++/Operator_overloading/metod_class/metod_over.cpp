#include <iostream>
 
class Dollars
{
private:
    int m_dollars;
 
public:
    Dollars(int dollars) { m_dollars = dollars; }
 
    // Выполняем Dollars + int
    Dollars operator+(int value);
 
    int getDollars() { return m_dollars; }
};
 
// Примечание: Эта функция не является методом класса!
Dollars Dollars::operator+(int value)
{
    return Dollars(this->m_dollars + value);
}
 
int main()
{
	Dollars dollars1(7);
	Dollars dollars2 = dollars1 + 3;
	std::cout << "I have " << dollars2.getDollars() << " dollars.\n";
 
	return 0;
}

