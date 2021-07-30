#include <iostream> 
#include <fstream> 
#include <cstring> 
#include <stdlib.h>
using namespace std;


//  Дан текстовый файл. Посчитать сколько раз в нем встречается заданное пользователем слово.

int main()
{
    char slovo[65], poisk[65];
    int kolich = 0;

    cout << "enter word: ";
    cin >> poisk;

    ifstream input("C:/Users/gorilla/Downloads/bad word.txt");
    if (input.fail()) { cout << "okeyy"; return 1; }

    while (!input.eof())
    {
        input >> slovo;
        (strstr(slovo, poisk)) ? kolich++ : 0;
    }
    cout << "number of repiting: " << kolich << endl;
    return 0;
}