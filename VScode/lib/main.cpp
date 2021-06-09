#include <iostream>
#include <cstring>
#include "library.h"
using namespace std;

// Команда разработчиков работавших над этим проектом:
// Михаил
// Тимофей

int main()
{
    {
        char *str = (char *)"difhvdifniudui";
        cout << "Word strlen: " << StrLen(str) << endl;
    }
    {
        char *str1 = (char *)"Copy";
        char *str2 = (char *)"Paste";
        StrCpy(str1, str2);
        cout << "Word strcpy: " << str1 << endl;
    }
    {
        char *str1 = (char *)"Str";
        char *str2 = (char *)" cat";
        StrCat(str1, str2);
        cout << "Word strcat: " << str1 << endl;
    }
    {
        char *str1 = (char *)"Str finder 228 copits";
        char *str2 = (char *)"228";
        cout << "Word strcat: " << StrStr(str1, str2) << endl;
    }
}