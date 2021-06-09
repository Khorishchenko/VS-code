#include <iostream>
#define newline '\n';
using namespace std;


// Передача параметрів, за допомогою силок, і вказівників 

// Силки
void sw(int &pch, int &ptr)
{
 int c = ptr;
 ptr = pch;
 pch = c;
}

//Вказівник 
void swap(int *pch, int *ptr)
{
 int t;
 t = *pch;
 *pch = *ptr;
 *ptr = t;
}

int main()
{
 int pch = 10, ptr = 13;
 cout << "Ssylkami!";
 sw(pch,ptr);
 cout << pch << ' ' << ptr << newline;
 cout << "Ukazateliami!";
 swap(pch,ptr);
 cout << pch << ' ' << ptr << newline;
}
