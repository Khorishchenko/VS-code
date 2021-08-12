#include <iostream>

// Перегрузка операторов с операндами разных типов


class Dollars
{
private:
	int m_dollars;
 
public:
	Dollars(int dollars) { m_dollars = dollars; }
 
	// Выполняем Dollars + int через дружественную функцию
	friend Dollars operator+(const Dollars &d1, int value);
 
	// Выполняем int + Dollars через дружественную функцию
	friend Dollars operator+(int value, const Dollars &d1);
 
 
	int getDollars() { return m_dollars; }
};
 
// Примечание: Эта функция не является методом класса!
Dollars operator+(const Dollars &d1, int value)
{
	// Используем конструктор Dollars и operator+(int, int).
	// Мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
	return Dollars(d1.m_dollars + value);
}
 
// Примечание: Эта функция не является методом класса!
Dollars operator+(int value, const Dollars &d1)
{
	// Используем конструктор Dollars и operator+(int, int).
	// Мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
	return Dollars(d1.m_dollars + value);
}
 
int main()
{
	Dollars d1 = Dollars(5) + 5;
	Dollars d2 = 5 + Dollars(5);
 
	std::cout << "I have " << d1.getDollars() << " dollars." << std::endl;
	std::cout << "I have " << d2.getDollars() << " dollars." << std::endl;
 
	return 0;
}


//============================================================================================================================================================//


#include <iostream>
 
class Values
{
private:
	int m_min; // минимальное значение, которое мы обнаружили до сих пор
	int m_max; // максимальное значение, которое мы обнаружили до сих пор
 
public:
	Values(int min, int max)
	{
		m_min = min;
		m_max = max;
	}
 
	int getMin() { return m_min; }
	int getMax() { return m_max; }
 
	friend Values operator+(const Values &v1, const Values &v2);
	friend Values operator+(const Values &v, int value);
	friend Values operator+(int value, const Values &v);
};
 
Values operator+(const Values &v1, const Values &v2)
{
	// Определяем минимальное значение между v1 и v2
	int min = v1.m_min < v2.m_min ? v1.m_min : v2.m_min;
 
	// Определяем максимальное значение между v1 и v2
	int max = v1.m_max > v2.m_max ? v1.m_max : v2.m_max;
 
	return Values(min, max);
}
 
Values operator+(const Values &v, int value)
{
	// Определяем минимальное значение между v и value
	int min = v.m_min < value ? v.m_min : value;
 
	// Определяем максимальное значение между v и value
	int max = v.m_max > value ? v.m_max : value;
 
	return Values(min, max);
}
 
Values operator+(int value, const Values &v)
{
	// Вызываем operator+(Values, int)
	return v + value;
}
 
int main()
{
	Values v1(11, 14);
	Values v2(7, 10);
	Values v3(4, 13);
 
	Values vFinal = v1 + v2 + 6 + 9 + v3 + 17;
 
	std::cout << "Result: (" << vFinal.getMin() << ", " << vFinal.getMax() << ")\n";
 
	return 0;
}