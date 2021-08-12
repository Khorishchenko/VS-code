#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void myVector(const std::vector<T> &array){
    for(const auto &value : array){
        std::cout << value << std::endl;
    }
}

template <typename T>
void vector(const std::vector<std::vector<T>> &array){

}


int main()
{
    std::vector <int> array{6,5,2,3,4,1};
    myVector(array);


    std::vector <char> array2{'h', 'e', 'l', 'l', 'o'};
    myVector(array2);

    std::sort(array.begin(), array.end());
    myVector(array);

    std::vector <std::vector <int>> array3(10, std::vector<int> (10));   //  Объявление вектора на n строк по m элементов 
    
    // or

    std::vector<std::vector<int>> vec;
    // 3x5
    vec.reserve(3);
    for (int i=0, size = vec.size(); i < size; ++i)
        vec[i].reserve(5);


    vector(array3);


    // and Двумерный vector

    int n, m;       // Создание переменных отвечающих за размер вектора
    std::cin >> n >> m;  // Ввод размеров вектора

    std::vector < std::vector <int> > a(n, std::vector <int> (m) ); // Объявление вектора на n строк по m элементов 

    for (int i = 0; i < n; i++)     // Цикл, который идёт по строкам
        for (int j = 0; j < m; j++) // Цикл, который идёт по элементам
        {
            std::cin >> a[i][j]; // Заполнение вектора или массива (в данном случае ввод)
        }

    for (int i = 0; i < n; i++) // Цикл, который идёт по строкам
    {
        for (int j = 0; j < m; j++) // Цикл, который идёт по элементам
            std::cout << a[i][j] << ' '; // Вывод элементов i строки вектора
        std::cout << std::endl;
    }



    return 0;
}