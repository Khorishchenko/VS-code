#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

// 3d Array + sorting

int main()
{
    int m1 = 2, m2 = 4, m3 = 4;

    int ***ptr3Darray = new int**[m1];

    for (int i = 0; i < m1; i++)
        ptr3Darray[i] = new int*[m2];
    
    for (int i = 0; i < m1; i++)
        for (int k = 0; k < m2; k++)
            ptr3Darray[i][k] = new int[m3];

    for (int i = 0; i < m1; i++){
        for(int k = 0; k < m2; k++){
            for (int v = 0; v < m3; v++)
                cout << setw(4) << (ptr3Darray[i][k][v] = rand() % 100);
            cout << endl;
        }
        cout << endl;
    }


    // sort 

    // for (int i = 0; i < m1; i++){
    //     for (int k = 0; k < m2; k++){
    //         for (int v = 0; v < m3 - 1; v++){
    //             for (int g = 0; g < m3 - 1 - v; g++){
    //                 if (ptr3Darray[i][k][g] > ptr3Darray[i][k][g + 1])
    //                 {
    //                     swap(ptr3Darray[i][k][g], ptr3Darray[i][k][g + 1]);
    //                 }
    //             }
    //         }
    //         cout << endl;
    //     }
    //    // cout << endl;
    // }
    // for (int i = 0; i < m1; i++)
    // {
    //     for (int k = 0; k < m2; k++)
    //     {
    //         for (int v = 0; v < m3; v++)
    //         {
    //             cout << setw(4) << ptr3Darray[i][k][v] << ' ';
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    return 0;
}