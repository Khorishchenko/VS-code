#include <iostream>
#include <string>
#include <array>
int main()
{
    std::array<std::string, 8> names{"Sasha", "Ivan", "John", "Orlando", "Leonardo", "Nina", "Anton", "Molly"};
    std::string name;
    std::cout << "Name: ", std::cin >> name;
    bool f = false;
    for (std::string str : names)
        if (str == name)
        {
            f = true;
            break;
        }
    if (f)
        std::cout << "Found\n";
    else
        std::cout << "Not found\n";
    return 0;
}