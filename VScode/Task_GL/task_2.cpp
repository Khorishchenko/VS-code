#include <iostream>

//   Напишите макрос, который принимает два параметра и в результате выполнения которого первый 
//   параметр должен равняться сумму первого и второго параметров.

#define sum(parameter_1, parameter_2) parameter_1 += parameter_2;

int main()
{
    int par_1(30), par_2(5);
    sum(par_1, par_2);
    
    std::cout << par_1 << std::endl;
    
    return 0;
}