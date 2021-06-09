#include <iostream>
#include <string>
using namespace std;

class Children
{
    private:
        string  name;
        string  surname;
        int     age;
    public:
        void set();
        void get();
    
};

void Children::set()
{
    cout << "\nEnter name children: ", getline(cin, name);
    cout << "Enter surname chikdren: ", getline(cin, surname);
    cout << "Enter age children: "; cin >> age; cin.ignore(100, '\n');
}

void Children::get()
{
    cout << "\nName CHildren: " << name << endl;
    cout << "Surname Children: " << surname << endl;
    cout << "Age Children: " << age << endl;
}

int main()
{
    Children child;
    Children child2;

    child.set();
    child2.set();
    
    child.get();
    child2.get();
}