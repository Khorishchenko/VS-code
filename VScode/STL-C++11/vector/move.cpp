#include <iostream>
#include <utility>
#include <stdlib.h>


int* my_move()
{
    int *ptr = new int[10];
    std::fill_n(ptr, 10, 10);

    for (int i = 0; i < 10; i++)
        std::cout << ptr[i];
    std::cout << std::endl;
    std::cout << ptr << std::endl;

    return std::move(ptr);



}

int main()
{
    int value = 10;
    int *ptr = &value;

    std::cout << *ptr << std::endl;
    ptr = my_move();
    std::cout << ptr << std::endl;

    return 0;
}