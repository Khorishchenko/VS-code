#include <iostream>
#include <fstream>


// Дан текстовый файл. Необходимо создать но- вый файл убрав из него все неприемлемые слова. 
// Список неприемлемых слов находится в другом файле.

int main()
{
    std::fstream wordsFile("bad_word.txt"), file("testFile.txt");
    std::ofstream output("test.txt", std::ofstream::out | std::ofstream::trunc);
    std::string line, text, word;
    while (getline(file, line))
        text += line + "\n";
    text = text.substr(0, text.size() - 1); // Видаляємо лишню нову строку щоб не було більше строк ніж було
    while (wordsFile >> word)
    {
        size_t pos = -1;
        while ((pos = text.find(word)) != -1)
            text.erase(pos, word.length());
    }
    output << text, output.close(), std::cout << "Done!!!\n";
}