#include <iostream>
#include <fstream>
#include <string>
using namespace std;


// Дан текстовый файл. Необходимо переписать его строки в другой файл. 
// Порядок строк во втором файле должен быть обратным по отношению к порядку строк в заданном файле.

int main()
{
    ifstream file1;
    ofstream file;

    file1.open("/Users/sergejhorisenko/Desktop/VS-code/VScode/fstream/myfile.txt");
    file.open("/Users/sergejhorisenko/Desktop/VS-code/VScode/fstream/ofstream/mytext.txt");

    if (file1.is_open() && file.is_open())
             { cout << "YES!!!"; }                       // Проверка на открытие файлов

    string word_waste; int num = 0, i = 0;

    while (!file1.eof())                                //Вычисляем количество строк
    { 
        getline(file1, word_waste); 
        num++; 
    }               

    string *word = new string[num];                         //Создаем массив
    file1.seekg(0);                                         //Становимся на начало файла

    for (int i = 0; i < num; i++){                          //Записываем все строки в массив
        getline(file1, word[i]); 
    }
    --num;
    int size = num;
    int x = 0;
    while (x < size){                                      //Переписываем строки с массива в новый файл в обратном порядке
        file << word[num--] << endl; 
        x++;
    }

    delete []word;
}