#include <iostream>
using namespace std;

class A
{
    private:
        int a;
    public:
        A() : a(1) {cout << a << endl;}
        A(int y) :a(y) {cout << a << endl;} 
        A(const A &x) :a(x.a) {cout << '3' << a << endl;}
};

int main()
{
    A a; A b(3); b = 5;
}


