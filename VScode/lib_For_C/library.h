#ifndef USING_NAMESPACE
#define USING_NAMESPACE

#include <iostream>
#include <cstring>
using namespace std;

int StrLen(char *str)
{
    int c = 0;
    char symbol = ' ';
    while (symbol != '\0')
        symbol = str[c++];
    return --c;
}
char *StrCpy(char *str1, char *str2)
{
    int Length = StrLen(str2);
    char *Tmp = new char[Length];
    for (int i = 0; i < Length; i++)
        Tmp[i] = str2[i];
    str1 = Tmp;
    return str1;
}
char *StrCat(char *&str1, char *str2)
{
    int Length1 = StrLen(str1);
    int Length2 = StrLen(str2);
    char *Tmp = new char[Length1 + Length2];
    for (int i = 0; i < Length1; i++)
        Tmp[i] = str1[i];
    for (int i = 0; i < Length2; i++)
        Tmp[i + Length1] = str2[i];
    str1 = Tmp;
    return str1;
}
char *StrChr(char *str, char s)
{
    int Length = StrLen(str);
    for (int i = 0; i < Length; i++)
        if (str[i] == s)
            return &str[i];
    return 0;
}
char *StrStr(char *str1, char *str2)
{
    int Length1 = StrLen(str1);
    int Length2 = StrLen(str2);
    for (int i = 0; i < Length1 - Length2; i++)
    {
        bool f = true;
        for (int j = 0; j < Length2; j++)
            if (str1[i + j] != str2[j])
                f = false;
        if (f)
            return &str1[i];
    }
    return 0;
}
#endif