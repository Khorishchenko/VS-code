#include <iostream>
#include <string>
using namespace std;

// исключение C++

int main()
{
    int number;
    
    try
    {
        if (!(number != 0 || number > 0 || number < 0))
        {
            throw "error!!!";
        }
        else
            cout << number << endl;
    }
    catch(const char *str)
    {
        cout << str << endl;
    }
    return 0;
}