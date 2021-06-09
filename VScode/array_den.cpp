
#include <iostream>
using namespace std;
#define newline '\n'

/*
 Видалення певного елемента з масиву.
 номер елементу вводить користувач !
 Масив динамічний !
*/

int *delete_char(int *ptr, int SIZE, int elem_d);

int main(void)
{
    int element_delete = 0;
    int SIZE = 0;
    cout << "Enter please size of aaray: ";
    cin >> SIZE;
    
    int *ptr = new int(SIZE);
    
    for (int i = 0; i < SIZE; i++)
    {
        *(ptr + i) = rand() % 100;
        cout << *(ptr + i) << ' ';
    }
    cout << newline;
    cout << newline;

    cout << "which element do you want to remove: ";
    cin >> element_delete;
    cout << newline;
    
    int *ptr_2 = delete_char(ptr, SIZE, element_delete);
    
    cout << "new Array: " << newline;
    for (int i = 0; i < SIZE - 1; i++)
    {
        cout << *(ptr_2 + i) << ' ';
    }
    cout << newline;
    cout << newline;
    
    delete[] ptr_2;
    ptr_2 = nullptr;
    
    return 0;
}

int *delete_char(int *ptr, int SIZE, int elem_d)
{
    int *ptr_2 = new int(SIZE - 1);
    
    for (int i = 0, j = 0; i < SIZE - 1;)
    {
        if (ptr[j] == elem_d)
        {
            j++;
            continue;
        }
        else{
            *(ptr_2 + i) = *(ptr + j);
            i++, j++;
        }
    }
    return ptr_2;
}
