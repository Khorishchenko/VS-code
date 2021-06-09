#include <iostream>
using namespace std;
#define N '\n'

// Арифметика вказівника

void mx_swap(int *ptr, const int SIZE);
void mx_rand(int *ptr, const int SIZE);
void mx_show(int *ptr, const int SIZE);

int main()
{
    const int SIZE = 10;
    int arr[SIZE]{1, 2, 3,4 ,5,6,7,8,9,0};
    int arr_2[SIZE];
    int i = 0;
    int *ptr = arr + i;
    
    cout << *ptr << endl;
    
    mx_rand(arr, SIZE);
    mx_rand(arr_2, SIZE);
    
    cout << "arr:  ";
    mx_show(arr, SIZE);
    cout << N;
    cout << "arr_2: ";
    mx_show(arr_2, SIZE);
    
    cout << N;
    mx_swap(&arr[0], SIZE);
    mx_swap(&arr_2[0], SIZE);
    cout << N;
    
    cout << "arr:  ";
    mx_show(&arr[0], SIZE);
    cout << N;
    cout << "arr_2: ";
    mx_show(&arr_2[0], SIZE);
   
    cout << N;
    
    return 0;
    
}

void mx_swap(int *ptr, const int SIZE)
{
    int buf = 0;
    for (int i = 0, j = SIZE -1; j > i; i++, j--)
    {
        buf = *(ptr + i);
        *(ptr + i) = *(ptr + j);
        *(ptr + j) = buf;
    }
}

void mx_rand(int *ptr, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        *(ptr + i) = rand() % 10;
    }
}

void mx_show(int *ptr, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << ptr + i << ' ';
    }
}
