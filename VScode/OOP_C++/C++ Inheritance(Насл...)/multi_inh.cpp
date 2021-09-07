#include <iostream>
 
class Parent
{
protected:
	int m_x;
public:
	Parent(int x): m_x(x)
	{
		std::cout << "Parent()\n";
	}
	~Parent()
	{
		std::cout << "~Parent()\n";
	}
 
	void print() { std::cout << "Parent: " << m_x << '\n';  }
};
 
class Child: public Parent
{
public:
	Child(int y):  Parent(y)
	{
		std::cout << "Child()\n";
	}
	~Child()
	{
		std::cout << "~Child()\n";
	}
 
	void print() { std::cout << "Child: " << m_x << '\n'; }
};
 
class D2 : public Child
{
public:
	D2(int z): Child(z)
	{
		std::cout << "D2()\n";
	}
	~D2()
	{
		std::cout << "~D2()\n";
	}
 
        // Обратите внимание, здесь нет метода print()
};
 
int main()
{
	D2 d(7);
	d.print();
}