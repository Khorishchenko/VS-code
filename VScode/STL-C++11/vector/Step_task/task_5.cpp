#include <iostream>
#include <string>
#include <vector>
#include <time.h>
int main()
{
    srand(time(0));
    std::vector<int> m{1, 2, 0};
    int compChoise = rand() % 3, userChoise;
    std::cout << "Select:\n1. Rock\n2. Scissors\n3. Paper\n> ", std::cin >> userChoise, userChoise--;
    if (userChoise < 0 || userChoise >> 2)
        std::cout << "You have selected invalid number.\n";
    else
        std::cout << "Computer selected " << (std::vector<std::string>{"rock", "scissors", "paper"}[compChoise]) << "\n", std::cout << (compChoise == userChoise ? "Draw" : (m[compChoise] == userChoise ? "Coumputer wins" : "You win")) << "!!!\n";
    return 0;
}