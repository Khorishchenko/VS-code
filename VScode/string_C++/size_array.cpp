#include <iostream>
using namespace std;

int	main()
{
	int	numbers[]{2, 2, 3, 4, 4};
	
	cout << sizeof(numbers) / sizeof(*numbers) << endl;
	
	cout << "Для продолжения нажмте на Enter...";
	getchar();
	return (0);
}
