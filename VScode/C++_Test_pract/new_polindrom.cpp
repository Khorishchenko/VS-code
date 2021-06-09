#include <iostream>
#include <string>
using namespace std;

#define get(name) getline(cin, name)

int main()
{
    setlocale(LC_ALL, "Russian");
    string a, b;
    int i;

    get(a);
    for (i = (a.length() - 1); i >= 0; i--){
        b += a[i];
    }
    (a == b) ? cout << "Да " << endl :  cout << " No" << endl;
    return 0;
}