#include <iostream>
#include <string>
#include <string>
using namespace std;


struct hello
{
    int     age;
    string  _char;
};

void set(hello &Obj)
{
    cout << "Enter your age: "; cin >> Obj.age; cin.ignore(100, '\n');
    cout << "Enter your name: "; cin >> Obj._char;
}


int main()
{
    hello _struct = {};


   // string name;

    set(_struct);
    cout << _struct._char << ' ' << _struct.age << endl;

    // cout << "Enter your name: "; getline(cin, name); cout << name << endl;

    return 0;
}