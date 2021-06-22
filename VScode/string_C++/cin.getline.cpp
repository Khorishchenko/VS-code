#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

// work with string Використання cin.ignore() and getline

int main()
{
    
    int myAge = 0;
    string myName;
    cout << "Enter your Age: ";
    cin >> myAge;

    cin.ignore(32500, '\n');
    cout << "Enter your Name and Last name: ";
    getline(cin, myName);

    cout << "You are lived, " << setprecision(2) << (float)myAge/myName.length() 
                << " years for each letter in your name !" << endl;

    return 0;
}