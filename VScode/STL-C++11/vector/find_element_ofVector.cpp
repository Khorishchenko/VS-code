#include <algorithm>
#include <iostream>
#include <string>
#include <array>
int main()
{
    std::array<int, 5> nums;
    std::cout << "Input 5 numbers\n";
    for (int &num : nums)
        std::cout << "Number: ", std::cin >> num;
    int numToFind;
    std::cout << "Number to find: ", std::cin >> numToFind;
    if (std::find(std::begin(nums), std::end(nums), numToFind) != std::end(nums))
        std::cout << "Found\n";
    else
        std::cout << "Not found\n";
    return 0;
}