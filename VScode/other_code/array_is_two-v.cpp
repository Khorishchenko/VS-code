#include <iostream>
#include <iomanip>
using namespace std;

// Динамічний масив двохвимірний


int main()
{
    int size_row = 0;
    int size_colum = 0;

    cout << "Please Enter size row of array: ";
    cin >> size_row;
    cout << "Please Enter size colum of array: ";
    cin >> size_colum;

    int **ptrarray = new int*[size_row];

    for (int count = 0; count < size_row; count++)
        ptrarray[count] = new int[size_colum];
    
    for (int count_row = 0; count_row < size_row; count_row++)
    {
        for (int count_colum = 0; count_colum < size_colum; count_colum++)
            cout << setw(4) << (ptrarray[count_row][count_colum] = rand() % 100);
        cout << endl;
    }
    cout << endl;

    for (int count = 0; count < size_row; count++)
        delete[]ptrarray[count];
    
    cin.ignore();
    cout << "Для продолжения нажмте на Enter...";
	getchar();
    
    return 0;
}

