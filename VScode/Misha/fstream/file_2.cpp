#include <iostream>
#include <fstream>

//  Дан массив строк. Записать их в файл, рас- положив каждый элемент массива на отдельной строке с сохранением порядка.

int main()
{
    std::string strs[] = {"Нello ben0 how0 are you ?", "I am nice and0 you ?"};
    std::ofstream outfile("test.txt", std::ofstream::out | std::ofstream::trunc);
    for (std::string str : strs)
        outfile << str << "\n";
    outfile.close(), std::cout << "Done!!!\n";
}