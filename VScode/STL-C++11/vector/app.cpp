#include <iostream>
#include <string>


int main()
{
    int x  = 5;

    std::cout << x << std::endl;
    std::cout << "Hello" << std::endl;
    std::string us_txt = "";
    // std::cin.ignore('\n', 1);
    std::getline(std::cin, us_txt);
    std::cout << us_txt << std::endl;
    return 0;

}