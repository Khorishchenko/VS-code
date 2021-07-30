#include <iostream>

// Создайте динамический массив из 50 integer элементов.  
// Установите значение всех элементов в 0x7A7A7A7A без использования циклов.


int main()
{
    int size = 50;
    int array[size];
    std::fill(array, array + size,  0x7A7A7A7A );        // Присвоение значений всем элементам массива

    for(const auto &number : array)                     // foreach
        std::cout << number << std::endl;
    return 0;
}