#include <iostream>
#include <fstream>


// Дан текстовый файл. Переписать в другой файл все его строки с заменой в них символа 0 на символ 1 и наоборот.

int main()
{
    std::fstream file("testFile.txt");
    std::ofstream outfile("test.txt", std::ofstream::out | std::ofstream::trunc);
    std::string line;
    while (std::getline(file, line))
    {
        std::string newLine;
        for (char c : line)
            newLine += ((c == '0' || c == '1') ? (c == '0' ? '1' : '0') : c);
        outfile << newLine << "\n";
    }
    outfile.close();
    std::cout << "Done!!!\n";
    return 0;
}