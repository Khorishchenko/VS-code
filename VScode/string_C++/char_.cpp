#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define get(name) getline(cin, name)
#define get_ch(name, size) cin.getline(name, size)
#define ig cin.ignore(100, '\n')
 

int main()
{
    const int size = 10;
    int arr[10];

    for (int i = 0; i < size; i++)
    {
        wcout << (arr[i] = rand() % 10) << endl;
    }

    return 0;
}

