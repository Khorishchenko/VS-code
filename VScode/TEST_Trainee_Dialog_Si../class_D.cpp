//#include <stdafx.h>
#include <stdio.h>
 
class A
{
public:
	virtual void f(A *a)
	{
		printf("A\n");
		delete a;
	}
};

class B:public A
{
public:
	virtual void f(B*b)
	{
		A::f(b);
		printf("B\n");
		delete b;
	}
};

int main()
{
	A *a = new B();
	a->f(a);
}