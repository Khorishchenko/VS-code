#include <iostream>
using namespace std;

class A
{
private:
	int a;
public:
	A() :a(1) 
	{
		cout << a;
	}
	A(const A& x) :a(x.a)
	{
		cout << '3' << a;
	}
};

int main()
{
	A b; A mas[3];
	A d(b); 

	return 0;
}