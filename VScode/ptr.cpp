#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

// двовимірний динамічний масив


// Шаблон Функції
template <typename T>
void show_arr(T **ptr_arr, int sz_rw, int sz_cl)
{
	for (int count_row = 0; count_row < sz_rw; count_row++)
	{
		for (int count_colum = 0; count_colum < sz_cl; count_colum++)
			cout << setw(4) << ptr_arr[count_row][count_colum];
		cout << endl;
	}
	cout << endl;
}

// двовимірний динамічний масив
int main()
{
	srand(time(NULL));
	int size_row = 0, size_colum = 0;
	cin >> size_row;
	cin >> size_colum;

	int **ptrint_arr = new int*[size_row];
	char **ptrchar_arr = new char*[size_row];

	for (int count = 0; count < size_row; count++)
	{
		ptrint_arr[count] = new int[size_colum];
		ptrchar_arr[count] = new char[size_colum]; 
	}

	for (int count_row = 0; count_row < size_row; count_row++)
	{
		for (int count_colum = 0; count_colum < size_colum; count_colum++)
		{
			ptrint_arr[count_row][count_colum] = rand() % 100;
			ptrchar_arr[count_row][count_colum] = rand() % 25 + 96;
		}		
	}
	
	show_arr(ptrint_arr, size_row, size_colum);
	show_arr(ptrchar_arr, size_row, size_colum);

	delete []ptrchar_arr;
	delete []ptrint_arr;

	ptrint_arr = nullptr;
	ptrchar_arr = nullptr;

	return 0;
}
