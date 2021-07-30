#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;

template <typename T>
T* addone(T* arr, int& size, T a)
{
	if (size == 0)
	{
		T* temp = new T[++size];
		temp[0] = a;
		return temp;
	}
	else
	{
		T* temp = new T[size + 1];
		for (int i = 0; i < size; i++) temp[i] = arr[i];
		temp[size++] = a;
		delete[]arr;
		return temp;
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");

	ifstream file;
	ofstream fileo;

	file.open("/Users/sergejhorisenko/Desktop/VS-code/VScode/fstream/myfile.txt");

	fileo.open("/Users/sergejhorisenko/Desktop/VS-code/VScode/fstream/ofstream/mytext.txt");
	if (fileo.is_open() && file.is_open()) cout << "good" << endl; 

	string str, *strp = nullptr;
	int size = 0;

	while (getline(file, str)) strp = addone(strp, size, str);
	// Я пробовал много способов, но поскольку seekp плохо работает, это единственный способ, который у меня работает
	for (int i = size - 1; i > -1; i--)
	{
		fileo << strp[i] << endl;
	}

	delete[]strp;
	file.close();
	fileo.close();
}