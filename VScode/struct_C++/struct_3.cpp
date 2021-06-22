#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

#define tab '\t'
// Массив структур. Указатель на структуру


struct size     // дескриптор
{
    int breast; 
    int waist;  
    int hips;  
};

struct volume   // дескриптор
{
    int age;
    char yourChar;
    string name;

    size best;
};

void ShoeMyCode(const volume Obj[], const int SIZE);

int main()
{
    const int SIZE = 2;
    volume MyCode[SIZE] = {};   // ініціалізація нулями '0'

    for (int i = 0; i < SIZE; i++)
    {
        cout << "name: ";
        getline(cin, MyCode[i].name);
        cout << "Age: ";
        cin >> MyCode[i].age;
        cin.ignore(3200, '\n');
        cout << "Your char: ";
        cin >> MyCode[i].yourChar;
        cout << "Объемы (грудь, талия, бедра): ";
        cin >> MyCode[i].best.breast;
        cin >> MyCode[i].best.hips;
        cin >> MyCode[i].best.waist;
        cin.get();
        cout << endl;
    }

    ShoeMyCode(MyCode, SIZE);
    cout << "Для продолжения нажмте на Enter...";
	getchar();

    return 0;
}

void ShoeMyCode(const volume Obj[], const int SIZE)
{
    cout << "№\t" << "Имя\t" << "Возраст\t" << "Рост\t" << "Вес\t" << "Объёмы\t\t" << "Английский" << endl;
    cout << "==================================================================" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << i + 1 << tab << Obj[i].age << tab << Obj[i].name << tab << Obj[i].yourChar << endl;
        cout << i + 1 << tab << Obj[i].best.breast << tab << Obj[i].best.hips << tab << Obj[i].best.waist << endl;
    }
}