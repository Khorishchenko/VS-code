 #include<iostream>
#include <cmath>
using namespace std;
#define newline '\n'

bool prch(int o)
{ 
    bool result(true);
    if (o < 0)
        result = true;
    else{
     result = false;
            }
    
    return (result);
}
int* proverka(int* A, int size)
{
    int count = 0;
    for (int i = 0; i < size; ++i){
        if (!prch(A[i]))
            ++count;
    }
    int* B = new int[count];
    int j = 0;
    for (int i = 0; i < size; ++i)
        if (!prch(A[i]))
            B[j++] = A[i];
    for(int j = 0; j < count; j++)
        cout << B[j] << " ";
    return B;
}
int main()
{
    int size;
    cout << "Введите размер массива: ";
    cin >> size;
    int* A = new int[size];
    cout << "Заполните массив: " << newline;
    for(int i = 0; i<size; i++)
        cin >> A[i];
    int* res = proverka(A, size);
    delete []A;
    delete []res;
    return 0;
}