#include <iostream>
using namespace std;
#define tab '\t'
#define newline '\n'

// указателях на структуры  Obj->Age;

struct struct_5_ptr
{
    int Age;
    int Power;
    int Skil;
};

void SetSize(struct_5_ptr *Obj);
void ShowMyStruct(const struct_5_ptr *Obj);

int main()
{
    struct_5_ptr *ptrstruct = new struct_5_ptr;
    cout << "Entep Parametr: " << endl;

    SetSize(ptrstruct);
    ShowMyStruct(ptrstruct);
    cout << "Для продолжения нажмте на Enter...";
	getchar();

    return 0;
}

void SetSize(struct_5_ptr *Obj)
{
    cout << "Enter Age: ";
    cin >> Obj->Age;
    cout << "Enter Power: ";
    cin >> Obj->Power;
    cout << "Enter Skil: ";
    cin >> Obj->Skil;
    cout << endl;
} 

void ShowMyStruct(const struct_5_ptr *Obj)
{
    cout << "=============================================================================" << endl;
    cout << "My Power is: " << Obj->Power << tab << "My Age is: " 
                            << Obj->Age << tab << tab << "My Skil is: " << Obj->Skil << newline << endl;
}