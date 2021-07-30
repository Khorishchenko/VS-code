#include <iostream>
#include <iomanip>

// Напишите функцию, которая принимает три целочисленных параметра.
//  В результате вызова функции, первый параметр должен равняться сумме первого и второго параметров, а второй сумме первого и третьего.


 void sum(int *parameter_1, int *parameter_2, int *parameter_3) {
     *parameter_1 += *parameter_2;
     *parameter_2 = *parameter_1 + *parameter_3;
}

int main()
{
    int a(4), b(5), c(7);

    sum(&a, &b, &c);

    std::cout << std::setw(4) << a << std::setw(4) <<  b << std::setw(4) << c << std::endl;

    return 0;
}