#include <iostream>
#include <string>
#include <cstring>
#include <ctype.h>
#include <fstream>
#include <iomanip>
#define newline '\n'
#define get(name) getline(cin, name)
#define ig cin.ignore(100, '\n')
using namespace std;

int main()
{
    ifstream file("/Users/sergejhorisenko/Desktop/VS-code/VScode/fstream/myfile.txt");

    if (file.is_open())
    {
        cout << "The file is open!" << newline;
    }
    else
    {
        cout << "File not open!!!" << newline;
        return -1;
    }
    string s;
    char f;
    int a = 0;
    cout << "Enter a word to check: ";
    cin >> f;
    for (file >> s[0]; !file.eof(); file >> s[0]) {                 // Працює !!! s[0] ! ------
        if (f == s[0])
            a++;
    }
    cout << a;
}
