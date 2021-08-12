class Dollars
{
private:
	int m_dollars;
 
public:
	Dollars(int dollars) { m_dollars = dollars; }
 
	int getDollars() const { return m_dollars; }
};
 
// Указываем прототип operator+(), чтобы иметь возможность использовать перегруженный оператор + в других файлах
Dollars operator+(const Dollars &d1, const Dollars &d2);