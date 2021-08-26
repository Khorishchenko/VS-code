
// Урок №143. Конструкторы преобразования, ключевые слова explicit и delete


#include <iostream> 
#include <cassert>
 
class Drob
{
private:
	int m_numerator;
	int m_denominator;
 
public:
	// Конструктор по умолчанию
	Drob(int numerator = 0, int denominator = 1) :
		m_numerator(numerator), m_denominator(denominator)
	{
		assert(denominator != 0);
	}
 
	// Конструктор копирования
	Drob(const Drob &copy) :
		m_numerator(copy.m_numerator), m_denominator(copy.m_denominator)
	{
		// Нет необходимости выполнять проверку denominator здесь, так как эта проверка уже осуществлена в конструкторе по умолчанию
		std::cout << "Copy constructor worked here!\n"; // просто, чтобы показать, что это работает
	}
 
	friend std::ostream& operator<<(std::ostream& out, const Drob &d1);
	int getNumerator() { return m_numerator; }
	void setNumerator(int numerator) { m_numerator = numerator; }
};
 
std::ostream& operator<<(std::ostream& out, const Drob &d1)
{
	out << d1.m_numerator << "/" << d1.m_denominator;
	return out;
}
 
Drob makeNegative(Drob d)
{
	d.setNumerator(-d.getNumerator());
	return d;
}
 
int main()
{
	std::cout << makeNegative(7) << std::endl; // передаем целочисленное значение
 
	return 0;
}