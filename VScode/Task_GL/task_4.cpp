#include <iostream>

// Есть переменная int a; Объявите указатель на эту переменную и с его помощью 
// запишите в переменную значение 33 (в шестнадцатеричном формате).




int main()
{
    int a;
    int *ptr= &a;
    *ptr = 0x21;

    std::cout << a << std::endl;
    return 0;

}