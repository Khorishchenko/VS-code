#include<iostream>
#include <string>
#include <math.h>
#define get(name) getline(cin, name)
#define len(name) name.size()
using namespace std;

 

//  Учитывая строку слов, вам нужно найти слово с наибольшей оценкой.

// Каждая буква слова оценивается в баллах в соответствии с ее положением в алфавите: a = 97, b = 98, c = 99 и т. Д.

// Вам нужно вернуть слово с наивысшей оценкой в виде строки.

// Если два слова имеют одинаковый балл, верните слово, которое встречается раньше всего в исходной строке.

// Все буквы будут строчными, и все введенные данные будут действительными.


int main() {
    string name;
    get(name);
    int plan = 1;
    for (int i = 0; i < len(name); i++) {
        if (name[i] != ' ') {
            continue;
        }
        plan++;
    }
    string* sharaga = new string[plan];
    for (int i = 0, j = 0; i < len(name); i++) {
        if (name[i] != ' ') {
            sharaga[j] += name[i];
            continue;
        }
        j++;
    }
    int suma = 0, max = 0, index = 0;
    for (int i = 0; i < plan; i++) {
        suma = 0;
        for (int j = 0; j < len(sharaga[i]); j++) {
            suma += int(sharaga[i][j]);
        }
        if (suma > max) {
            max = suma;
            index = i;
        }
    }
    cout << sharaga[index];
}