#include <iostream>
using namespace std;


struct A
{
	A(){cout << "A";}
	~A(){cout << "~A";}
};

struct C{
	C(){
		cout << "C";
		//throw E();
	}
	~C(){cout << "~C";}
};

struct B: public A{
	C c;
	B() {cout << "B";}
	~B() {cout << "~B";}
};

int main()
{
	B b;
	return 0;
}

// A C B ~B ~C ~A