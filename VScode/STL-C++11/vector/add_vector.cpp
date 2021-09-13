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
void sort(std::vector<int> &arr)
{
    std::sort(std::begin(arr), std::end(arr));
}
void coutNums(std::vector<int> arr)
{
    for (int n : arr)
        std::cout << n << ' ';
    std::cout << '\n';
}
void addArr(std::vector<int> &from, std::vector<int> &to)
{
    for (int n : from)
        to.push_back(n);
}
int main()
{
    std::vector<int> nums1 = inputArray();
    sort(nums1);
    coutNums(nums1);
    std::vector<int> nums2 = inputArray();
    sort(nums2);
    coutNums(nums2);
    std::vector<int> numsSum;
    addArr(nums1, numsSum);
    addArr(nums2, numsSum);
    sort(numsSum);
    coutNums(numsSum);
    return 0;
}