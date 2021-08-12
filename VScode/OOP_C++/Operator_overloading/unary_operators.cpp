#include <iostream>

// Перегрузка унарных операторов +, — и логического НЕ


// Рассмотрим унарные операторы плюс (+), минус (-) и логическое НЕ (!), которые работают с одним операндом. 
// Так как они применяются только к одному объекту, то их перегрузку следует выполнять через методы класса.


// Например, перегрузим унарный оператор минус (-) для класса Dollars:


class Dollars
{
private:
    int m_dollars;
 
public:
    Dollars(int dollars) { m_dollars = dollars; }
 
    // Выполняем -Dollars через метод класса
    Dollars operator-() const;
 
    int getDollars() const { return m_dollars; }
};
 
// Эта функция является методом класса!
Dollars Dollars::operator-() const
{
    return Dollars(-m_dollars);
}
 
// int main()
// {
//     const Dollars dollars1(7);
//     std::cout << "My debt is " << (-dollars1).getDollars() << " dollars.\n";
 
//     return 0;
// }


// В следующем примере мы рассмотрим перегрузку унарного оператора минус (−) и оператора логического НЕ (!) для класса Something:

#include <iostream>

class Something
{
private:
	double m_a, m_b, m_c;

public:
	Something(double a = 0.0, double b = 0.0, double c = 0.0) :
		m_a(a), m_b(b), m_c(c)
	{
	}

	// Конвертируем объект класса Something в отрицательный 
	Something operator- () const
	{
		return Something(-m_a, -m_b, -m_c);
	}

	// Возвращаем true, если используются значения по умолчанию, в противном случае - false
	bool operator! () const
	{
		return (m_a == 0.0 && m_b == 0.0 && m_c == 0.0);
	}

    Something operator +() const{
        return Something(+m_a);
    }

	double getA() { return m_a; }
	double getB() { return m_b; }
	double getC() { return m_c; }
};



int main()
{
	Something something; // используем конструктор по умолчанию со значениями 0.0, 0.0, 0.0

	if (!something)
		std::cout << "Something is null.\n";
	else
		std::cout << "Something is not null.\n";

    Something some(-2, -4, -5);
    std::cout << "My debt is " << (+some).getA() << " dollars.\n";

	return 0;
}
