#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
using namespace std;


// 1. Описать структуру с именем TRAIN, содержащую следующие поля:
// • название пункта назначения;
// • номер поезда;
// • время отправления.

// 2. Написать программу, выполняющую следующие действия:
// • ввод с клавиатуры данных в массив, состоящий из восьми элементов типа TRAIN; записи должны
// быть размещены в алфавитном порядке но названиям пунктов назначения;
// • вывод на экран информации о поездах, отправляющихся после введенного с
// клавиатуры времени;
// • если таких поездов нет, выдать па дисплей соответствующее сообщение.


struct Train{
    string    path;
    int     number;
    int     hour;
    int     min;
};

void set(Train Obj[], const int size_st){
    for (int i = 0; i < size_st; i++){
        cout << "\nВведите пункт назначения поезда [" << i + 1 <<"]", getline(cin, Obj[i].path);
        cout << "Введите номер для поезда: ", cin >> Obj[i].number, cin.ignore(100, '\n');
        cout << "Введите время отправления для поезда (часы): ", cin >> Obj[i].hour, cin.ignore(100, '\n');
        cout << "Введите время отправления для поезда (минуты): ", cin >> Obj[i].min, cin.ignore(100, '\n');
    }
}

int main()
{ 
    setlocale(LC_ALL, "Russian");  

    const int SIZE = 3; 
    Train trains[SIZE] = {};

    set(trains, SIZE);

    for (int i = 0; i < SIZE; i++){
        for (int k = i + 1; k < SIZE; k++){
            if (trains[i].path > trains[k].path)
                swap(trains[i], trains[k]);
        }
    }

    for (int i = 0; i < SIZE; i++) 
    {
         cout << " Пункт назначения: " << setw(10) << trains[i].path << "   номер: " << setw(6) << trains[i].number 
                << "   Время отправления: " << setw(5) << trains[i].hour << ":" << trains[i].min  << endl << endl;
    }

    cout << "Enter time_hour: "; int time_hour; cin >> time_hour, cin.ignore(1, ':'); int time_min; cin >> time_min, cin.ignore(10, '\n');

    int k = 0;
    for (int i = 0; i < SIZE; i++){
        if (trains[i].hour >= time_hour && trains[i].min >= time_min)
        {
            cout << " \nследующие поезда отправятся после вашего времени: " << endl;
            cout << " Пункт назначения: " << setw(10) << trains[ i ].path << "   номер: " << setw(6) << trains[ i ].number 
                    << "   Время отправления: " << setw(6) << trains[ i ].hour << ":" << trains[ i ].min  << endl << endl;
            k++;
        }
    }
    if (k == 0) cout << " Нет подходящих поездов" << endl;
    return 0;
}