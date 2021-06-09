#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int main(void)
{
    // объявление двумерного динамического массива на 10 элементов:

    int size_row = 0, size_colum = 0;
    cin >> size_row;
    cin >> size_colum;

    float **ptrarray = new float* [size_row]; // две строки в массиве

   


        for (int count = 0, size = 3; count < size_row; count++, size++)
            ptrarray[count] = new float[size]; // и пять столбцов

       


    //  где ptrarray  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа float


    // высвобождение памяти отводимой под двумерный динамический массив:

        for (int count = 0; count < 2; count++)
            delete [] ptrarray[count];
    //      где 2 – количество строк в массиве

}

int main(void)
{
    srand(time(0)); // генерация случайных чисел
    // динамическое создание двумерного массива вещественных чисел на десять элементов
    
    float **ptrarray = new float* [2]; // две строки в массиве
    
    for (int count = 0; count < 2; count++)
        ptrarray[count] = new float [5]; // и пять столбцов
    
    // заполнение массива
    for (int count_row = 0; count_row < 2; count_row++)
        for (int count_column = 0; count_column < 5; count_column++)
            ptrarray[count_row][count_column] = (rand() % 10 + 1) / float((rand() % 10 + 1)); //заполнение массива случайными числами с масштабированием от 1 до 10
    
    // вывод массива
    for (int count_row = 0; count_row < 2; count_row++)
    {
        for (int count_column = 0; count_column < 5; count_column++)
            cout << setw(4) << setprecision(2) << ptrarray[count_row][count_column] << "   ";
        cout << endl;
    }
    
    // удаление двумерного динамического массива
    for (int count = 0; count < 2; count++)
        delete []ptrarray[count];

    return 0;
}
