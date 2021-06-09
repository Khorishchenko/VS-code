#include <iostream>
using namespace std;


int main()
{
    char a[] = "123";
    char b[5] = "123";
    const char *c = "123";

    a[3] = '3';
    b[4] = '3';
    c[2] = 'a';         // class_B.cpp:13:10: error: assignment of read-only location '*(c + 2)'
}