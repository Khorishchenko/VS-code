#include "lib.h"
using namespace std;

#define SIZE 3


LIB *addBook(LIB *lib, const int count_books);
void show_Boks(LIB *str, const int counBooks);
void find_Autor(LIB *str, const int countBooks);
void find_Name_Book(LIB *str, const int countBooks);
void sort_Book_Name(LIB *str, const int countBooks);
void sort_Aut_name(LIB *str, const int countBooks);
void BOOKS(LIB *str);
void Ops();


int main()
{
    setlocale(LC_ALL, "rus");

    LIB *library;
    LIB Library[SIZE];

    BOOKS(Library);
    show_Boks(Library, SIZE);

    
    int YesOrNot = 0;
    int countBooks = 0;

    do 
    {   
        int ran = 0;
        cout << "Яку книгу хочете добавить !: номер: ", cin >> ran, cin.ignore(1, '\n');

        library = addBook(library, countBooks);
        library[countBooks] = Library[ran - 1];

        show_Boks(library, countBooks + 1);
        
        countBooks++;

        cout << "\nDo you want to add BOOK:(YES/1, NO/0): "; cin >> YesOrNot, cin.ignore(100, '\n');

    }while(YesOrNot != 0);

    int Yes_orNot;

    while(true)
    {
        cout << "\n\tMENU\n "<< endl;
        cout << "1. Печать всех книг\n" << "2. Поиск книг по автору\n" << "3. Поиск книги по названию\n";
        cout << "4. Сортировка массива по названию книг\n" << "5. Сортировка массива по автору\n6. Аннотация на книгу \n" 
             << "\nexit ENTER: 0\n> ", cin >> YesOrNot, cin.ignore(100, '\n');

        switch(YesOrNot)
        {
            case 1:
                show_Boks(library, countBooks);
                break;
            case 2:
                find_Autor(library, countBooks);
                break;
            case 3:
                find_Name_Book(library, countBooks);
                break;
            case 4:
                sort_Book_Name(library, countBooks);
                break;
            case 5:
                sort_Aut_name(library, countBooks);
                break;
            case 6:
                Ops();
                break;
            default:
                break;
        }

        if (Yes_orNot == 0)
            break;

    }

    delete [] library;

    return 0;
}

LIB *addBook(LIB *lib, const int count_books){

    if (count_books == 0) {
        lib = new LIB[count_books + 1];
    }
    else {
        LIB *tmp_lib = new LIB[count_books + 1];

        for (int i = 0; i < count_books; i++){
            tmp_lib[i] = lib[i];
        }
        delete[] lib;

        lib = tmp_lib;
    }
    return lib;
}

void show_Boks(LIB *str, const int count_books){
    for (int i = 0; i < count_books; i++){
        cout << "\nBOOK [" << i + 1 << "] library:" << endl;
        cout << "NAME: " << str[i].name << endl;
        cout << "AUTHOR: " << str[i].author << endl;
        cout << "PUBL: " << str[i].publishing << endl;
        cout << "GENER: " << str[i].genre << endl;
    }
}

void find_Autor(LIB *str, const int countBooks){
    bool book;
    cout << "\nWhat do you want find Author: "; string nameAutor; getline(cin, nameAutor);
    for (int i = 0; i < countBooks; i++){
        if (str[i].author == nameAutor){
            cout << "BOOK [" << i + 1 << "] library:" << endl;
            cout << "NAME: " << str[i].name << endl;
            cout << "AUTHOR: " << str[i].author << endl;
            cout << "PUBL: " << str[i].publishing << endl;
            cout << "GENER: " << str[i].genre << endl;
            book = true;
        }
    }
    if (book != true)
        cout << "\nNot find Author this Book " << endl;
}

void find_Name_Book(LIB *str, const int countBooks){
    int author = 0;
    cout << "What do you want find Name Book: "; string nameBook; getline(cin, nameBook);
    for (int i = 0; i < countBooks; i++){
        if (str[i].name == nameBook){
            cout << "BOOK [" << i + 1 << "] library:" << endl;
            cout << "NAME: " << str[i].name << endl;
            cout << "AUTHOR: " << str[i].author << endl;
            cout << "PUBL: " << str[i].publishing << endl;
            cout << "GENER: " << str[i].genre << endl;
        }
        else 
            author++;

    }
    if (author != 0)
        cout << "\nNot find Author this Book " << endl;
}

void sort_Book_Name(LIB *str, const int countBooks){
    for (int i = 0; i < countBooks; i++){
        for (int k = i + 1; k < countBooks; k++){
            if(str[i].name > str[k].name)
                swap(str[i], str[k]);
        }
    }
    show_Boks(str, countBooks);
}


void sort_Aut_name(LIB *str, const int countBooks){
    for (int i = 0; i < countBooks; i++){
        for (int k = i + 1; k < countBooks; k++){
            if(str[i].author > str[k].author)
                swap(str[i], str[k]);
        }
    }
    show_Boks(str, countBooks);
}

void Ops(){
    cout << "Аннотация на книгу !\nEnter name BOOK: "; string count; getline(cin, count);
    Book_abstract(count);
}
