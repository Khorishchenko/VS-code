#include <iostream>
using namespace std;

bool First(int a, int b)
{
    cout << a << " > " << b << endl;
    return a > b;
}
bool Second(int a, int b)
{
    cout << a << " = " << b << endl;
    return a == b;
}
bool Third(int a, int b)
{
    cout << a << " < " << b << endl;
    return a < b;
}
int main()
{
    bool (*Functions[3])(int, int) = {First,
                                      Second,
                                      Third};
    int Number1, Number2, Function;
    cout << "Number 1: ";
    cin >> Number1;
    cout << "Number 2: ";
    cin >> Number2;
    cout << "Select function: 1-3\n> ";
    cin >> Function;
    cout << (Functions[Function - 1](Number1, Number2) ? "True" : "False") << endl;
}