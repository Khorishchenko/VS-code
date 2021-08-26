// Перегрузка оператора индексации []


//  Можно также просто возвращать весь массив (m_array) и использовать оператор [] для доступа к его элементам:


#include <iostream>
 
class IntArray
{
private:
    int m_array[10];
 
public:
    int* getArray() { return m_array; }
};
 
int main()
{
    IntArray array;
    array.getArray()[4] = 5;
 
    return 0;
}

// Но можно сделать еще проще, перегрузив оператор индексации.

class Array
{
private:
    int m_array[10];
 
public:
    int& operator[] (const int index);
};
 
int& Array::operator[] (const int index)
{
    return m_array[index];
}


int main()
{
	Array array;
	array[4] = 5; // присваиваем значение
	std::cout << array[4]; // выводим значение
 
	return 0;
}


//  Проверка ошибок

// int array[7];
// array[9] = 4; // индекс 9 является некорректным (вне допустимого диапазона)!


#include <cassert> // для assert()
 
class Arr
{
private:
    int m_array[10];
 
public:
    int& operator[] (const int index);
};
 
int& Arr::operator[] (const int index)
{
    assert(index >= 0 && index < 10);
 
    return m_array[index];
}


// Заключение
// Перегрузка оператора индексации обычно используется для обеспечения прямого доступа к элементам массива, который находится внутри класса
//  (в качестве переменной-члена). Поскольку строки часто используются в реализации массивов символов, 
// то оператор [] часто перегружают в классах со строками, чтобы иметь доступ к каждому символу строки отдельно.




