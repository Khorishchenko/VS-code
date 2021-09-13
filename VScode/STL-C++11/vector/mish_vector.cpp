#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
inline bool space(char c)
{
    return std::isspace(c);
}
inline bool notspace(char c)
{
    return !std::isspace(c);
}
std::vector<std::string> split(const std::string &s)
{
    typedef std::string::const_iterator iter;
    std::vector<std::string> ret;
    iter i = s.begin();
    while (i != s.end())
    {
        i = std::find_if(i, s.end(), notspace);
        iter j = std::find_if(i, s.end(), space);
        if (i != s.end())
        {
            ret.push_back(std::string(i, j));
            i = j;
        }
    }
    return ret;
}
std::vector<int> inputArray()
{
    std::vector<int> nums;
    std::string input;
    std::cout << "Input array elements\n> ", std::getline(std::cin, input);
    std::vector<std::string> strings = split(input);
    for (std::string str : strings)
        nums.push_back(stoi(str));
    return nums;
}
void coutNums(std::vector<int> arr)
{
    for (int n : arr)
        std::cout << n << ' ';
    std::cout << '\n';
}
int main()
{
    std::vector<int> nums = inputArray();
    std::vector<int> newNums;
    for (int i : nums)
    {
        int count = 0;
        for (int j : nums)
            count += i == j;
        if (count < 2)
            newNums.push_back(i);
    }
    coutNums(newNums);
    return 0;
}