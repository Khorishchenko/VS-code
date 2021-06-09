#include <iostream>
#include "lib.h"
using namespace std;

#define enter cout << "Для продолжения нажмите на Enter..."; getchar();

int main()
{
	char name[] = "hello";
	int size_name = mystrlen(name);

	cout << name << " size name is " << size_name << endl;

	enter;
	return 0;
}