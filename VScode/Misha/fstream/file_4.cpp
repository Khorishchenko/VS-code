#include <iostream>
#include <fstream>

// Дан текстовый файл. Необходимо создать новый файл, в который переписать из исходного файла все слова, 
// состоящие не менее чем из семи букв.

int main()
{
    std::fstream file("testFile.txt");
    std::ofstream output("test.txt", std::ofstream::out | std::ofstream::trunc);
    std::string word;
    while (file >> word)
        if (word.size() > 6)
            output << word << " ";
    output.close(), std::cout << "Done!!!\n";
}