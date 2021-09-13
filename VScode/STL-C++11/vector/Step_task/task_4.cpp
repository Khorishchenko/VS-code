#include <iostream>
#include <array>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
int main()
{
    vector<int> a, b;
    a = { 1,2,3,4,5 };
    b = { 6,7,8,9,10 };
    for (auto& element : b)
        a.push_back(element);
    for (auto& element : a)
        cout << element << endl;
    
}