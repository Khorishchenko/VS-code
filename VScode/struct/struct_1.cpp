#include <iostream>
using namespace std;

// struct Структуры в C++. Часть 1

struct MyWoman
{
    string name;
    int age;
    bool engKhowledge;

};

void ShowMyFirstoman(const MyWoman &Obj);

int main()
{
    MyWoman firstWoman = {};

    firstWoman.age = 35;
    firstWoman.name = "Alisa";
    firstWoman.engKhowledge = true;

    ShowMyFirstoman(firstWoman);

    cout << "Для продолжения нажмте на Enter...";
	getchar();

    return 0;
}

void ShowMyFirstoman(const MyWoman &Obj)
{
    cout << "Age my Woman:  " << Obj.age << endl;
    cout << "Name my Woman: " << Obj.name << endl;
    cout << "She khows English: "; (Obj.engKhowledge) ? cout << "yes" << endl : cout << "no" << endl;   
}

