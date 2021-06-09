#include <iostream>
using namespace	std;

class A{
public:
	virtual void f(int n = 2) {cout << n + 1 << endl;}

};

class B : public A {
public:
	void f(int n = 3) {cout << n - 1 << endl ;}
};

int main()
{
	A * a = new B;
	a->f();
	return 0;
}