#include <iostream>

int main()
{
	// Объявление переменной std::array следующее

	std::array<int, 4> myarray; // объявляем массив типа int длиной 4

	// std::array можно инициализировать с использованием списка 
	// инициализаторов или uniform-инициализации:

	std::array<int, 4> myarray = { 8, 6, 4, 1 }; // список инициализаторов
	std::array<int, 4> myarray2 { 8, 6, 4, 1 }; // uniform-инициализация


	// Доступ к значениям массива через оператор индекса осуществляется как обычно:

	std::cout << myarray[1];
	myarray[2] = 7;


	// функция at()

	std::array<int, 4> myarray { 8, 6, 4, 1 };
	myarray.at(1) = 7; // элемент массива под номером 1 - корректный, присваиваем ему значение 7
	myarray.at(8) = 15; // элемент массива под номером 8 - некорректный, получим ошибку




	// Размер и сортировка

	// С помощью функции size() можно узнать длину массива:

	std::array<double, 4> myarray{ 8.0, 6.4, 4.3, 1.9 };
	std::cout << "length: " << myarray.size();
 






	return 0;
}

// Размер и сортировка

void printLength(const std::array<double, 4> &myarray)
{
    std::cout << "length: " << myarray.size();
}
 
int main()
{
    std::array<double, 4> myarray { 8.0, 6.4, 4.3, 1.9 };
 
    printLength(myarray);





    //  циклы foreach




    std::array<int, 4> myarray { 8, 6, 4, 1 };
 
	for (auto &element : myarray)
    	std::cout << element << ' ';

    return 0;
}



#include <iostream>
#include <array>
#include <algorithm> // для std::sort
 
int main()
{
    std::array<int, 5> myarray { 8, 4, 2, 7, 1 };
    std::sort(myarray.begin(), myarray.end()); // сортировка массива по возрастанию
//    std::sort(myarray.rbegin(), myarray.rend()); // сортировка массива по убыванию
 
    for (const auto &element : myarray)
        std::cout << element << ' ';
 
    return 0;
}