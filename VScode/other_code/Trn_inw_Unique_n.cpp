#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

// Унікальний елемент масива 

// program one Slow execution !

void f(int arr[], int SIZE)
{
    bool Unical = true;
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if(arr[i] == arr[j] && j != i){
                Unical = false;
                break;
            }
        }
        if (Unical)
            cout << "this is unikal element: " << arr[i] << endl;
        Unical = true;
    }
}

int main()
{
    srand(time(NULL));
    const int SIZE = 10;
    int aray[SIZE];

    for (int i = 0; i < SIZE; i++)
        cout << setw(4) << (aray[i] = rand() % 10);
    cout << endl;

    f(aray, SIZE);

    cout << "Для продолжения нажмите на Enter...";
	getchar();

    return 0;
}

// program two Fast execution !!! 

void f(int Arr[], int Size)
{
    int B[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < Size; i++)
        B[Arr[i]]++;
    for (int i = 0; i < Size; i++)
        if (B[i] == 1)
            cout << "Unique element: " << i << endl;
}

int main()
{
    srand(time(0));
    const int Size = 10;
    int Arr[Size];

    for (int i = 0; i < Size; i++)
        cout << setw(4) << (Arr[i] = rand() % 10);
    cout << endl;

    f(Arr, Size);

    system("pause");
    return 0;
}
