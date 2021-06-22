#include <iostream>
#include "lib.h"
using namespace std;

int main()
{
    char str[20], str2[10], s;
    cin.getline(str, 20);
    cin.getline(str2, 10);
    cin >> s;
    cout << mystrlen(str);
    cout << mystrcat(str, str2);
    cout << mystrcpy(str, str2);
    cout << mystrchr(str, s);
    cout << mystrstr(str, str2);
}