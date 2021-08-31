#include <iostream>
#include <vector>

void print_MyArray(std::vector<int> &array);

int main()
{   
    std::vector<int> array(10, 15);

    print_MyArray(array);

    return 0;
}

void print_MyArray(std::vector<int> &array){
    for(const auto &element : array)
        std::cout << element << ' ';
    std::cout << '\n'; 
}