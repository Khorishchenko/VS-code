#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

 

int main()
{
    int n = 5, m = 3;
    vector < vector <int> > arr(n, vector <int>(m));
    arr = { {6, 7, 8}, { 7, 8, 9 }, { 6, 9, 10 }, { 6, 9, 8 }, {7, 6, 10} };
   
    int r = rand() % 6;
    
    cout << "Enter three numbers " << endl;
    int a, b, c;
    cin >> a >> b >> c;
    
    int sum_us = a + b + c;
    int sum_c = 0;
    
    for (int j = 0; j < m; j++) {
        sum_c += arr[r - 1][j];
    }
    cout << sum_c << endl;
    if (sum_us == sum_c)
        cout << "You are WIN" << endl;
    else
        cout << "You are lose" << endl;
}