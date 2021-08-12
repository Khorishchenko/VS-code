#include <iostream>
#include <vector>
#include <algorithm>

// Task vector 

int main()
{
    std::vector <int> array {2,2,3,4,4};
    std::vector<int>::iterator it;

    for (auto it = array.begin(); it != array.end(); it++){
        auto value = find(array.begin(), array.end(), *it);
        int value2 = *value;
        (value2) ? std::cout << value2 << std::endl : std::cout << "";
    }

    return 0;
}