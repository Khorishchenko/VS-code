#include <iostream>
#include <fstream>
#include <string>
using namespace std;


//Дан текстовый файл. Подсчитать количество строк в нём.

int main()
{
    int size = 0;

    ifstream file;
    file.open("/Users/sergejhorisenko/Desktop/VScode/C++_Test_pract/myfile.txt");

    try{
        if (!file.is_open())
            throw "Don't open this file !!! ERROR";
        else
            cout << "File is Open. It is Ok" << endl;
        string str;
        while (!file.eof())
        {
            getline(file, str);
            size++;
        }
    }
    catch(const char *str)
    {
        cout << str << endl;
    }

    cout << "Your file has [" << size <<"] string(s)" << endl;
}