#include <iostream>
#include <time.h>
using namespace std;

// Сума елементів масивів через Шаблонну функцію

template <typename T1, typename T2>
T2 sumElement(T1 array[], T2 array_d[], T1 size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
        sum += array_d[i];
    }
    return sum;
}

int main()
{
    srand(time(NULL));
    const int SIZE = 10;
    double array[SIZE];
    int arr[SIZE];
    
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = 10 + rand() % 10;
        cout << arr[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = 1.01 * (rand() % 20);
        cout << array[i] << " ";
    }
    cout << endl;
    
    cout << " Sum Elements Array : " << sumElement(arr, array, SIZE) << endl;
    return 0;
}


