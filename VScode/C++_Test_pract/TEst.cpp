#include <iostream>
#include <cstring>
using namespace std;

// Найдите и замените вхождение некоторого слова на заданное пользователем слово.

int main(){
    setlocale(LC_ALL, "Russian");

    char* pch = nullptr;
    char str[] = "hello world haha";
    char pch1[10], pch2[10];

    puts(str);

    cin.getline(pch1,10), cin.getline(pch2, 10);

    if ((pch = strstr(str, pch1)) != NULL) {
        strncpy(pch, pch2, strlen(pch2));
    }
    cout << (str) << endl; 
    return 0;
}