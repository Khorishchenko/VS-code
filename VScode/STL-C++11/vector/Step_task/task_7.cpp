#include <iostream>
#include <string>
#include <vector>
#include <time.h>
int sum(std::vector<int> arr)
{
    int s = 0;
    for (int i : arr)
        s += i;
    return s;
}
int main()
{
    srand(time(0));
    std::vector<std::vector<int>> collections = {{6, 7, 8}, {7, 8, 9}, {6, 9, 10}, {6, 9, 8}, {7, 6, 10}};
    std::cout << "Choose one of collections:\n";
    int i = 1;
    for (auto c : collections)
        std::cout << i++ << ") " << c[0] << " " << c[1] << " " << c[2] << "\n";
    int select;
    std::cout << "> ", std::cin >> select;
    int userSum = sum(collections[select]),
        compSum = sum(collections[rand() % 5]);
    std::cout << "Your sum: " << userSum << "\nComputer sum: " << compSum << "\n";
    std::cout << (userSum == compSum ? "It's draw" : (userSum > compSum ? "You won" : "You lose")) << "!!!\n";
    return 0;
}