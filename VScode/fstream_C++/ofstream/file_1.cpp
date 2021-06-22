#include <iostream>
#include <fstream>
#include <string>
using namespace std;


// Задание 2. Дан текстовый файл. Переписать в другой файл все его строки с заменой в них символа 0 на символ 1 и наоборот.


int main()
{
    ofstream file;                                                                             // Об'єкт для запису в файл
    ifstream file_2;

    file_2.open("/Users/sergejhorisenko/Desktop/VS-code/VScode/fstream/myfile.txt");
    file.open("/Users/sergejhorisenko/Desktop/VS-code/VScode/fstream/ofstream/mytext.txt");

    if(file.is_open() && file_2.is_open())
        cout << "Good file is open!" << endl;
    else 
        cout << "Don't goot, file is not open!" << endl;

    string str;
    while(!file_2.eof())
    {
        getline(file_2, str);

        for (int i = 0; i < str.size(); i++){
            if(str[i] == '0')
                str[i] = '1';
        }
        file << str << endl;;
    }

    file.close();
    file_2.close();
    return 0;
}