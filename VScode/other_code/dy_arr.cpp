#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

// Динамічний масив - розділення на масив позитивних, 
// негативних, ненульових елементів

void my_Func(int *ptr, const int SIZE);
void Show_arr(int *ptr_arr, int SIZE);

int main()
{
	srand(time(NULL));
	const int SIZE = 10;
	int arr[SIZE];

	cout << "Array_FULL: ";
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 10 - 5;
		cout << setw(4) << arr[i];
	}
	cout << endl;

	my_Func(arr, SIZE);

	return 0;
}

void my_Func(int *ptr, const int SIZE)
{
	int *ptr_zero = nullptr;
	int *ptr_min = nullptr;
	int *ptr_max = nullptr;
	int count_min = 0, count_max = 0, count_zero = 0;

	for (int i = 0; i < SIZE; i++)
	{
		if(ptr[i] < 0)
			count_min++;
		else if (ptr[i] > 0)
			count_max++;
		else if (ptr[i] == 0)
			count_zero++;
	}

	if(count_zero != 0)
		ptr_zero = new int[count_zero];
	if(count_max != 0)
		ptr_max = new int[count_max];
	if(count_min != 0)
		ptr_min = new int[count_min];

	int index_zero = 0, index_min = 0, index_max = 0;

	for (int count = 0; count < SIZE; count++)
	{
		if (ptr[count] < 0)
		{
			ptr_min[index_min] = ptr[count];
			index_min++;
		}
		else if (ptr[count] > 0)
		{
			ptr_max[index_max] = ptr[count];
			index_max++;
		}
		else if (ptr[count] == 0)
		{
			ptr_zero[index_zero] = ptr[count];
			index_zero++;
		}
	}

	if (ptr_zero != nullptr)
	{
		Show_arr(ptr_zero, index_zero);
		delete[]ptr_zero;
		ptr_zero = nullptr;
	}
	if (ptr_max != nullptr)
	{
		Show_arr(ptr_max, index_max);
		delete[]ptr_max;
		ptr_max = nullptr;
	}
	if (ptr_min != nullptr)
	{
		Show_arr(ptr_min, index_min);
		delete[]ptr_min;
		ptr_min = nullptr;
	}
}

void Show_arr(int *ptr_arr, int SIZE){
	cout << "Array_Next: ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << setw(4) << ptr_arr[i];
	}
	cout << endl;
}