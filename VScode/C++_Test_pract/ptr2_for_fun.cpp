#include <iostream>
using namespace std;

int MaxNumber(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int a, b;
    cin >> a >> b;
    
    int (*ptr)(int, int);
    ptr = MaxNumber;

    cout << (*ptr)(a, b) << endl;
    return 0;
}