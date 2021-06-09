#include <iostream>
using namespace std;

int main()
{
    int array[10];
    int *a = array;
    int *b = &array[9];
    int N = a - b;
    cout <<  N  << endl;            // -9 WOW !!! FUCT
}