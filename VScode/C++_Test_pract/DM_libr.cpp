#include <string>
#include <iostream>
#include<stdlib.h>
using namespace std;
#define ign cin.ignore(100, '\n')
#define get(name) getline(cin, name)
const int size_bibliotek = 2;

 

struct student
{
    int     age;
    string     name;
};
struct Book {
    string name;
    string avtor;
    string anotation;
};

 

void set(student* obj)
{
    cout << "enter your age: "; cin >> obj->age; cin.ignore(100, '\n');
    cout << "enter your name: "; getline(cin, obj->name);
}

 

void definebook(Book* book, int booknumber) {
    cout << booknumber + 1 << " book" << endl;
    cout << "enter book name: "; get(book->name);
    cout << "enter book author: "; get(book->avtor);
    cout << "enter book anotation: "; get(book->anotation); ign;
}
void coutbook(Book* book, int booknumber) {
    cout << booknumber + 1 << " book" << endl;
    cout << "book name : " << book -> name << " \t";
    cout << "book author: " << book ->avtor << "\t";
    cout << "book anotation: " << book -> anotation << endl;
}
void search(Book *book, string name, int i) {
     if (book -> name == name) {
         coutbook(book, i);
         cout << "----------" << endl;   
     }
}
void search_auth(Book *book, string author, int i) {
    if (book->avtor == author) {
        coutbook(book, i);
        cout << "----------" << endl;
    }
}
int main() {
    Book bibliotek[size_bibliotek];

 

    for (int i = 0; i < size_bibliotek; i++) {
        definebook(&bibliotek[i], i);
    }
    for (int j = 0; j < size_bibliotek; j++) {
        coutbook(&bibliotek[j], j);
    }
    string answ;
    string answer_if;
    string answer_bool;
    bool answer = false;

 

    while (answer != true) {
        cout<<"what you want? (search by name; search by author; sort by name; sort by author;)"<<endl;
        get(answ);
        if (answ == "search by name") {
            cout << "enter name of book: ", get(answer_if);
            for (int k = 0; k < size_bibliotek; k++) {
                search(&bibliotek[k], answer_if, k);
            }
            cout << "you want to exit ? (yes;no)", get(answer_bool);
            if (answer_bool == "yes") answer = true;
        }
        else if (answ == "search by author") {
            cout << "enter author: ", get(answer_if);
            for (int l = 0; l < size_bibliotek; l++) {
                search_auth(&bibliotek[l], answer_if, l);
            }  
            cout << "you want to exit ? (yes;no)", get(answer_bool);
            if (answer_bool == "yes") answer = true;
        }
        else if (answ == "sort by name") {
            for (int i = 0; i < size_bibliotek; i++) {
                for (int j = i + 1; j < size_bibliotek; j++) {
                    if (bibliotek[i].name > bibliotek[j].name) {
                        swap(bibliotek[i], bibliotek[j]);
                    }
                }
            }
            for (int y = 0; y < size_bibliotek; y++) {
                coutbook(&bibliotek[y], y);
            }
            cout << "you want to exit ? (yes;no)", get(answer_bool);
            if (answer_bool == "yes") answer = true;
        }
        else if (answ == "sort by author") {
            for (int i = 0; i < size_bibliotek; i++) {
                for (int j = i + 1; j < size_bibliotek; j++) {
                    if (bibliotek[i].avtor > bibliotek[j].avtor) {
                        swap(bibliotek[i], bibliotek[j]);
                    }
                }
            }
            for (int y = 0; y < size_bibliotek; y++) {
                coutbook(&bibliotek[y], y);
            }
            cout << "you want to exit ? (yes;no)", get(answer_bool);
            if (answer_bool == "yes") answer = true;
        }

 

    }
}