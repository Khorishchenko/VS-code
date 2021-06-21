#include<iostream>
#include <string>
#include <fstream> 
using namespace std;
int main() {
    

 

    ifstream file;

 

    file.open("C:/Users/dmmiter/Desktop/ddd.txt");

 


    if (file.is_open())
        cout << "True\n" << endl;
    else
    {
       
            cout << "False\n\n" << endl;
    };

 


    string str;
    int lines = 0;
    while (getline(file, str))
    {
        
            lines++;

 

    }
        cout << "Lines: " << lines;
    file.close();
    return 0;
}