#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Car
{
    static int const SIZE = 3;
    string i;
    string t;
    string c;
    string n;
    // вывод  
   static void Print(Car C)
    {
        if (C.i == to_string(1))
        {
            cout.width(7);
            cout << "ID |" << " Название\t|" << " Цвет\t\t|" << " Номер\t\t|" << endl;
            for (int i = 0; i < 57; i++)
            {
                cout << "-";
            }
            cout << endl;
        }
        cout.width(5);
        cout << C.i << " | ";
        cout << C.t << "\t\t| ";
        cout << C.c << "\t\t| ";
        cout << C.n << "\t\t| ";
        cout << endl;
    }
    // Редактирование 
    void EditCar()
    {
        cout << "Введите модель машины: "; cin >> t; cout << endl;
        this->t = t;
        cout << "Введите цвет машины: "; cin >> c; cout << endl;
        this->c = c;
        cout << "Введите номер: "; cin >> n; cout << endl;
        this->n = n;
    }
    //Поиск по номеру
    void Search(Car car[], string n)
    {
        bool flag = true;
        cout << "Машины с указанным номером:" << endl << endl;
        cout.width(7);
        cout << "ID |" << " Название\t|" << " Цвет\t\t|" << " Номер\t\t|" << endl;
        for (int i = 0; i < 57; i++)
        {
            cout << "-";
        }
        cout << endl;
        for (int i = 0; i < SIZE; i++)
        {
            if (car[i].n == n)
            {
                Print(car[i]);
                flag = false;
            }
        }
        if (flag)
        {
            cout << "Машины с указанным номером нет в базе." << endl;
        }
    }  
};
int main()
{
    setlocale(LC_ALL, "ru");
    Car C[Car::SIZE];
    Car cars;
    srand(time(0));
    bool yesNo = true;
    int numMenu = 0;
    int temp;
    string tempStr;
    // Заполнение массива 
    for (int i = 0; i < Car::SIZE; i++)
    {
        C[i].i = to_string(i + 1);
        C[i].t = to_string(rand() % 10);
        C[i].c = to_string(rand() % 10);
        C[i].n = to_string(rand() % 10);
    }
    do
    {
        cout << "\t\tМЕНЮ" << endl;
        cout << "\t1. Печать всех машин; " << endl; 
        cout << "\t2. Редактирование машины; " << endl;
        cout << "\t3. Поиск машины по номеру; " << endl;
        cout << "\t4. Выход." << endl; cout << endl;
        cout << "\tВведите номер меню: "; cin >> numMenu; cout << endl;
        if (numMenu == 1)
        {
            for (Car number : C)
            {
                Car::Print(number);
            }
            cout << endl;
            cout << "Нажми любую кнопку для возврата к меню.";
            continue;
        }
        if (numMenu == 2)
        {
            cout << "Машины в базе: " << endl;
            for (Car number : C)
            {
                Car::Print(number);
            }
            cout << endl;
            cout << "Введите номер id машины для изменения: "; cin >> temp;
            if (temp > 0 || temp <= 10)
            {
                C[temp - 1].EditCar();
            }
            else
            {
                cout << "Машины с таким Id нет в базе." << endl;
            }
            cout << endl;
            cout << "Нажми любую кнопку для возврата к меню.";
            continue;
        }
        if (numMenu == 3)
        {
            cout << "Введите номер для поиска: "; cin >> tempStr;
            cars.Search(C, tempStr);
            cout << endl;
            cout << "Нажми любую кнопку для возврата к меню.";
            continue;
        }      
        if (numMenu == 4)
        {
            yesNo = false;
        }
    } while (yesNo);
    cout << endl << endl;
}