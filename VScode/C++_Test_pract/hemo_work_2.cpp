#include <iostream>
#include <string>
using namespace std;

struct animal
{
    string      name;
    string     _class;
    string      say;
};

void get(animal *Obj, int _st_size){
    for (int i = 0; i < _st_size; i++){
        cout << "\nEnter animal [" << i + 1 << "] name: ", getline(cin, Obj->name); 
        cout << "Enter animal class: ", getline(cin, Obj->_class);
        cout << "Enter animal say: ", getline(cin, Obj->say);
    }
}

void show(animal *Obj, int _st_size){
    for (int i = 0; i < _st_size; i++){
        cout << "\nName animal [" << i + 1 << "] is: " << Obj->name << endl;
        cout << "Class animal is: " << Obj->_class << endl;
    }
}

void Say_Animal(animal *Obj, int size){
    for (int i = 0; i < size; i++){
        cout << "\nSay animal[" << Obj->name <<"] is: " << Obj->say << endl;
    }
}

int main()
{
    animal *animals;
    int size = 0; cout << "Enter count Animals: "; cin >> size; cin.ignore(100, '\n');

    // size != 0 ? animals = new animal[size] : return 1;           // : expected primary-expression before 'return'  return 1; 
                                                                    // : return 1; - Утверждения нельзя использовать в выражениях.
    if (size != 0)
        animals = new animal[size];
    else
        return 1;

    get(animals, size);
    show(animals, size);
    Say_Animal(animals, size);

    return 0;
}