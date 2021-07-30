#include <iostream>
#include <array>

std::size_t const N(4);

//  Есть массив размером N, в котором записаны уникальные целые числа от 1 до N
// (в произвольном порядке). При этом одно число пропущено (вместо него в элементе храниться значение 0). 
// Напишите функцию, которая принимает такой массив и находит (возвращает и печатает в консоль) значение пропущенного элемента.

int f(const std::array<int, N> &arr){
    int number;
    for (int index = 0, size = arr.size(); index < size; index++){
        if (arr[index] == 0) 
            std::cout << (number = index + 1) << std::endl;
    }
    return number;
}

int main()
{
    std::array<int, N> myarray { 1, 2, 0, 4 };

    std::cout << f(myarray) << std::endl; 

    return 0;
}
