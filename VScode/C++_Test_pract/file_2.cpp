#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// Задание 1. Дан текстовый файл. Подсчитать количество слов, начинающихся с символа, который задаёт пользователь.

int count_word(ifstream &file, char myCh)
{
    char ch;
    int size = 0, i = 0;
    string str;

    while(file.get(ch)){
        if (ch = myCh && i++ == 0){                     // пошук символа !
            file.seekg(file.tellg(),ios_base::beg);     // встановлюємо початок з вказаного символа
            
            while(!file.eof()){                         // рахунок слів з вказаного символа 
                str ="";
                file >> str;
                size++;                                 //рахунок слів ! 
            }
        }
    }
    return --size;
}

int main()
{
    ifstream file;                                                                          // создаем объект класса ifstream
    file.open("/Users/sergejhorisenko/Desktop/VScode/C++_Test_pract/myfile.txt");           // открываем файл
    
    char myCh;
    cout << "Enter you char: ", cin >> myCh;

    try                                         // Виняток !
    {
        if (!file.is_open())                        // Перевірка на відкреття файлу !
            throw "Don't open this file !!!";
        cout << "File is open !" << endl;
        cout << "Count word before your char is [" << count_word(file, myCh) << "] " << endl;
    }
    catch(const char *str)
    {
        cout << str << endl;
    }

    file.close();
}