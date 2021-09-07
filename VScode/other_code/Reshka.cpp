#include <iostream>
#include<iostream>
#include<fstream>
#include<ctime>
 

//  Hard: Задание №3
// Напишите программу, моделирующую бросание монеты с помощью генерации случайных чисел. 
// После каждого броска монеты программа должна записывать в файл результат: Орёл или Решка.
//  Выполните бросок монеты 100 раз и подсчитайте, сколько раз появилась каждая сторона монеты.


 
int main()
{
	srand(time(0));
	setlocale(0, "");
 
	std::ofstream ofs("Coin.txt");
 
	int front=0, back=0;
 
	for (int i = 1; i < 101; i++)
	{
		int rand_number = rand() % 2;
		if (rand_number)
		{
			ofs << "решка ";
			front++;
		}
		else
		{
			ofs << "орел ";
			back++;
		}
 
		if(i%10==0)
			ofs << "\n";
	}
 
 
	ofs << "\nВсего было " << front << " выпадений решки и " << back << " выпадений орла";
 
	ofs.close();
 
	return 0;
 
}
