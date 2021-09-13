#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
    std::vector<int> myVector{15, 15, 15, 15, 15, 15, 15, 15, 15, 15};              // Создание вектора 
    // or std::vector<int> myVector(10, 15);


    myVector.push_back(10);                                                         // Добавить элемент в конец вектора

    std::cout << "My Vector size is " << myVector.size() << std::endl;              // Размер вектора по значению
    std::cout << "My vector capacity is " <<  myVector.capacity() << std::endl;     // Размер вектора по ячейкам помяты



    for (int i = 0; i < myVector.size(); i++)
    {
        std::cout << std::setw(4) << myVector[i];
    }
    std::cout << std::endl;

    myVector.clear();                                                               // Очистить вектор 

    std::cout << "My Vector size is " << myVector.size() << std::endl;
    std::cout << "My vector capacity is " <<  myVector.capacity() << std::endl;

    myVector.reserve(100);                                                          // Выделить количество памяти по ячейкам  

    std::cout << "My Vector size is " << myVector.size() << std::endl;
    std::cout << "My vector capacity is " <<  myVector.capacity() << std::endl;

    std::cout << ((bool)myVector.empty()) << std::endl;                             // Проверка на наличия значения в векторе 1 нету 0 есть 

    myVector.resize(20, 10);                                                        // Создать вектор на 20 элементы заполнить значением 10 все элементы 


    std::cout << "My Vector size is " << myVector.size() << std::endl;
    std::cout << "My vector capacity is " <<  myVector.capacity() << std::endl;

    std::cout << ((bool)myVector.empty()) << std::endl;

    for (int i = 0; i < myVector.size(); i++)
    {
        std::cout << std::setw(4) << myVector[i];
    }
    std::cout << std::endl;

    myVector.shrink_to_fit();                                                       // Уравнять количество ячеек памяти вектора с количеством значения вектора 

    std::cout << "My Vector size is " << myVector.size() << std::endl;
    std::cout << "My vector capacity is " <<  myVector.capacity() << std::endl;

    std::cout << ((bool)myVector.empty()) << std::endl;

    return 0;
}