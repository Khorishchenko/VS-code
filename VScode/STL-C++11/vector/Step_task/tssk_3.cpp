#include <iostream>
#include <array>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
int main()
{
    vector<int> arr;
    arr = { 1,1,6,9,5,3,46,7,9 };
    sort(arr.begin(), arr.end());

 

    for (int i = 0; i < arr.size();i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] == arr[i])
                arr.erase(arr.begin() + i);
        }
    }
    for (auto& element : arr)
        cout << element << endl;
    
}