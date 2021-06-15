#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Дан текстовый файл. Найти длину самой длинной строки.

int longerStr(ifstream &file)
{
    int size = 0;
    string str;
    while(!file.eof())
    {
        getline(file, str);
        if(size < str.size())
            size = str.size();
    }
    return size;
}

int main()
{
    ifstream file;
    file.exceptions(ifstream::badbit | ifstream::failbit);          // Для роботи Вийнятку 

    try
    {
        file.open("/Users/sergejhorisenko/Desktop/VScode/C++_Test_pract/myfile.txt");   // Перевірка на відкреття файлу через Вийняток !
        cout << "Longer string is [" << longerStr(file) << "] letter !" << endl;        // Робота функції 
    }
    catch(const ifstream::failure& e)
    {
        std::cerr << e.what() << '\n';          // Вивід помелки !
        cout << e.code() << endl;
    }

    file.close();
    return 0 ;
}