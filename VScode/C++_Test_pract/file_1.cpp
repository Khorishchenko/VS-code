#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// SIZE OF FILE in bite !
//  Дан текстовый файл. Подсчитать количество символов в нём.

int main()
{
    ifstream file;          // создаем объект класса ifstream

    file.open("/Users/sergejhorisenko/Desktop/VScode/C++_Test_pract/myfile.txt");       // открываем файл

    int size = 0;
    
    try                                             // Виняток !
    {
        if(!file.is_open())                         // Перевірка на відкреття файлу !
           throw "Don't open this file !!!";
        else
        {
            char ch;
            while(!file.eof()){                  // Считка слов из файла for end !!!
                file >> ch;
                size++;
            }
        }
        cout << '\n' << size<< endl;
    }
    catch (const char *str)                 // Виняток !
    {
        cout << str << endl;
    }

    file.close();
    return 0;
}