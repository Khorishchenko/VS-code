#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <iomanip>
#include <fstream>
#define mno(a, b) a * b;
using namespace std;

 

struct student
{
    string name;
    int year;
    std::array<int, 5> arr;
};

 

void fill(const int size, student univ[])
{
    for (int i = 0; i < size; i++)
    {
        int num = 0;
        cout << "Form [ " << i << " ]" << endl;
        cout << "Enter Name: ", getline(cin, univ[i].name);
        cout << "Enter Year: ";
        cin >> univ[i].year;
        cout << endl;
        cout << "Enter 5 Mark`s: ";
        for (int j = 0; i < 5; i++)
        {
            std::cin >> num;
            univ[j].arr[i] = num;
        }
    }
}

 

void show(const int size, student univ[])
{
    for (int i = 0; i < size; i++)
    {
        cout << "Form [ " << i << " ]" << endl;
        cout << "Name: " << univ[i].name << endl;
        cout << "Year: " << univ[i].year << endl;
        // cout << "5 Mark`s: " << univ[i].arr << endl;
    }
}

 


int main()
{
    const int size = 5;
    student univ[size];
    fill(size, univ);
    show(size, univ);
}


// for (int i = 0; i < v.size(); i++)
// {
//     sum =+ v[i];
// }