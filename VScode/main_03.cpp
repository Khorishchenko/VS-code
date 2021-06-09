#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


// Пример 2. Организация трехмерного динамического массива

int main()
{
	int i, j;	
	// Переменные для описания характеристик массивов.
     int m1 = 5, m2 = 5, m3 = 2;

     // указатель на указатель на указатель :)
     int ***ppArr;

     // Создание массива
     ppArr = new int**[m1]; 	// создаются слои


     //  это просто обычный уже двумерный массив

     for (i = 0; i < m1; i++)
         ppArr[i] = new int*[m2];	//выделяем память на столбцы

     for (i = 0; i < m1; i++)
            for (j = 0; j < m2; j++)
                ppArr[i][j] = new int[m3];	//выделяем память на строки.
   
   	for (int i = 0; i < m1; i++)
   	{
   		for (int k = 0; k < m2; k++)
   		{
   			for (int v = 0; v < m3; v++)
   				cout << setw(4) << (ppArr[i][k][v] = rand() % 100);
   			cout << endl;
   		}
   		cout << endl;
   	}

	// Удаление в последовательности, обратной созданию
    for (i = 0; i < m1; i++)
        for (j = 0; j < m2; j++)
            delete[]ppArr[i][j];
    for (i = 0; i < m1; i++)
        delete[]ppArr[i];
    delete[] ppArr;
}


// http://cppstudio.com/post/437/ - Символы и строки в С++
// https://www.youtube.com/watch?v=_6eG9Q40lFM&ab_channel=%23SimpleCode - Указатель на функцию



// 4. Указатели на функции


тип_функции (*имя_указателя)(спецификация_параметров);
Например: int (*func1Ptr) (char)


#include <iostream>
using namespace std;

void f1(void)  // Определение f1.
{   
	cout << "Load f1()\n";
}
void f2(void) // Определение f2.
{
     cout << "Load f1()\n";
}

int main()
{
	void (*ptr)(void); 		// ptr - указатель на функцию
	ptr = f2;				// Присваивается адрес f2().
	(*ptr)();				// Вызов f2() по ее адресу.
	ptr = f1;				// Присваивается адрес f1().
	(*ptr)();				// Вызов f1() по ее адресу.
	ptr();					// Вызов эквивалентен (*ptr)();
	*ptr() 					// error

}

// Следующая программа отражает гибкость 
//механизма вызовов функций с помощью указателей.

int add(int n, int m) { return n + m; }
int division(int n, int m) { return n/m; }
int mult(int n, int m) { return n * m; }
int subt(int n, int m) { return n - m; }

int main()
{
     int (*par)(int, int); // Указатель на функцию.
     int a =  6, b = 2;
     char c = '+';
     while   (c != ' ')
     {
         cout << "\n Arguments: a = " << a <<",
                  b = " << b;
         cout << ". Result for c = \'" << c << "\':";
		switch (c)
		{
			case '+':
                 par = add;
                 c = '/';
                 break;
             case '-':
                 par = subt;
				c = ' ';
                 break;
             case '*':
                 par = mult;
                 c = '-';
                 break;
             case '/':
                 par = division;
                  c = '*';
				break; 
		}
		cout << (a = (*par)(a,b))<<"\n"; 		// Вызов по адресу 
	}
}


Результаты выполнения программы:
     Arguments: a = 6, b = 2. Result for c = '+':8
     Arguments: a = 8, b = 2. Result for c = '/':4
     Arguments: a = 4, b = 2. Result for c = '*':8
     Arguments: a = 8, b = 2. Result for c = '-':6
     Press any key to continue




	