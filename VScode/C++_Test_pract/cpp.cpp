#include <iostream>
#include <string>
using namespace std;
#define get(name) getline(cin, name)
#define cha(name) cin.getline(name,100)
#define ignore cin.ignore(100, '\n')

int main()
{
    int size = 10;
    char str[size];

    cin.getline(str, 10);

    int error = 0;
    for (int i = 0; i < size; i++)
    {
    if(str[i] > 100)
        error++;
    }

    cout << size << '/' << error << endl;
}

