#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// struct in struct

struct power
{
    int speed;
    char schar;
    bool ativ_power;

};

struct myHuman
{
    string clas;
    int age;
    string rasa;
    power sila;
};

void Show_myPers(const myHuman &Obj);

int main()
{
    myHuman Pers;

    Pers.clas = "Mag";
    Pers.age = 23;
    Pers.rasa = "Alone";
    Pers.sila.speed = 100;
    Pers.sila.ativ_power = true;
    Pers.sila.schar = 'G';

    Show_myPers(Pers);
    cout << "Для продолжения нажмте на Enter...";
	getchar();


    return 0;
}

void Show_myPers(const myHuman &Obj)
{
    cout << "My pers is: " << Obj.clas << endl;
    cout << "My pers year old is: " << Obj.age << endl;
    cout << "My Pers rasa is: " << Obj.rasa << endl;
    cout << "My Pers scil'speed': " << Obj.sila.speed << " and your activ.paver is: "; 
    (Obj.sila.ativ_power) ? cout << "true" << endl : cout << "false" << endl; 
    cout << " and your char is: " << Obj.sila.schar << endl; 
}
