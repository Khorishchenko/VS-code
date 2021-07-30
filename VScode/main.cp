#include <iostream>
#include <string>
#include <fstream>
int main()
{
    std::ifstream file_a("textA.txt");
    std::ofstream file_b("textB.txt", std::ofstream::out | std::ofstream::trunc);
    std::string line, text;
    while (getline(file_a, line))
        text = line + "\n" + text;
    text = text.substr(0, text.size() - 1), file_b << text, file_a.close(), file_b.close();
}