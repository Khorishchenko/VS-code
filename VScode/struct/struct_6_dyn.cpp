#include <iostream>
#include <string>
using namespace std;
#define tab '\t'

// Динамический массив структур C++

struct Sponsor
{
    char name[20];
    char surname[20];
    double sum;
};

Sponsor *AddStruct(Sponsor *Obj, const int am);
void setData(Sponsor *Obj, const int count);
void ShowData(const Sponsor *Obj, const int coutn);

int main()
{
    Sponsor *OurSponsors = nullptr;
    int countAmount = 0;
    int YesOrNot = 0;

    do
    {
        OurSponsors = AddStruct(OurSponsors, countAmount);
        setData(OurSponsors, countAmount);
        countAmount++;

        cout << "Продолжить ввод данных (1 - да, 0 - нет): ";
        cin >> YesOrNot;
        cin.get();
    }
    while (YesOrNot != 0);


    ShowData(OurSponsors, countAmount);
    cout << "Для продолжения нажмте на Enter...";
	getchar();

    delete[] OurSponsors;
    return 0;
}

Sponsor *AddStruct(Sponsor *Obj, const int am)
{
    if (am == 0)
        Obj = new Sponsor[am + 1];
    else
    {
        Sponsor *tmpObj = new Sponsor[am + 1];

        for (int i = 0; i < am; i++)
        {
            tmpObj[i] = Obj[i];
        }
        delete[] Obj;

        Obj = tmpObj;
        
    }

    return Obj;
}

void setData(Sponsor *Obj, const int count)
{
    cout << "Enter Your name: ";
    cin.getline(Obj[count].name, 20);
    cout << "Enter Your surname: ";
    cin.getline(Obj[count].surname, 20);
    cout << "Sun our Sponsor: ";
    cin >> Obj[count].sum;
    cout << endl;
    cin.get();
}

void ShowData(const Sponsor *Obj, const int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << i + 1 << "  " << Obj[i].name << tab << Obj[i].surname << tab << Obj[i].sum << endl;
    }
    cout << endl;
}

