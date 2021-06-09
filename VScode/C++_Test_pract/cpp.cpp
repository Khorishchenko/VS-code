#include<iostream>
using namespace std;
 
struct books
{
  char nazvanie[30];
  char autor[30];
  char izdatelstvo[30];
  char janr[30];
  char anot[70];
};

void sozd_knig(books Obj[], const int size_book)
{
  for (int i = 0; i < size_book; i++)
  {
    cout << "Введите 5 книг, это " << i + 1 << " \n";
    cout << "Введите название: ", cin >> Obj[i].nazvanie, cin.ignore(100, '\n');
    cout << "Введите автора: ", cin >> Obj[i].autor, cin.ignore(100, '\n');
    cout << "Введите издательство: ", cin >> Obj[i].izdatelstvo, cin.ignore(100, '\n');
    cout << "Введите жанр: ", cin >> Obj[i].janr, cin.ignore(100, '\n');
    cout << "Введите аннотацию: ", cin >> Obj[i].anot, cin.ignore(100, '\n');
  }
}

void show_books(books object[], const int size_book)
{
  for (int i = 0; i < size_book; i++)
  {
    cout << "Книга номер " << i + 1 << ": \n";
    cout << "Название: " << object[i].nazvanie << endl;
    cout << "Автор: " << object[i].autor << endl;
    cout << "Издательство: " << object[i].izdatelstvo << endl;
    cout << "Жанр: " << object[i].janr << endl;
  }
}

void search_book_autor(books object[], const int size_book)
 {
    string stroka;     
    cout << "Введите автора, по которому хотите совершить поиск: ";
    getline(cin, stroka);
    for(int i = 0; i < size_book; i++) 
    {
       if(stroka == object[i].autor)
       {
          cout << "Название: " << object[i].nazvanie << endl;
          cout << "Автор: " << object[i].autor << endl;
          cout << "Издательство: " << object[i].izdatelstvo << endl;
          cout << "Жанр: " << object[i].janr << endl;
       }
    }
 }

void search_book_nazvanie(books object[], const int size_book)
 {
    string stroka;      
    cout << "Введите название, по которому хотите совершить поиск: ";
    getline(cin, stroka);
    for(int i = 0; i < size_book; i++) 
    {
       if(stroka == object[i].nazvanie)
       {
          cout << "Название: " << object[i].nazvanie << endl;
          cout << "Автор: " << object[i].autor << endl;
          cout << "Издательство: " << object[i].izdatelstvo << endl;
          cout << "Жанр: " << object[i].janr << endl;
          cout << "Аннотация: " << object[i].anot << endl;
       }
    }
 }

void search_book_anot(books object[], const int size_book)
 {
    string stroka;      
    cout << "Введите название, по которому хотите совершить поиск: ";
    getline(cin, stroka);
    for(int i = 0; i < size_book; i++) 
    {
       if(stroka == object[i].nazvanie)
       {
          cout << "Аннотация: " << object[i].anot << endl;
       }
    }
 }

void sort_nazvanie(books objekt[], const int size_book)
 {
    cout << "\nСортировка...\n";
    for (int i = 0; i < size_book; i++)
    {
      for (int k = i + 1; k < size_book; k++)
      {
        if (objekt[i].nazvanie > objekt[k].nazvanie)
        {
          swap(objekt[i], objekt[k]);
        }
      }
    }
    for (int i = 0; i < size_book; i++)
    {
    cout << "Название: " << objekt[i].nazvanie << endl;
    cout << "Автор: " << objekt[i].autor << endl;
    cout << "Издательство: " << objekt[i].izdatelstvo << endl;
    cout << "Жанр: " << objekt[i].janr << endl;
    }
 }

void sort_autor(books objekt[], const int size_book)
 {
    cout << "\nСортировка...\n";
    for (int i = 0; i < size_book; i++)
    {
      for (int k = i + 1; k < size_book; k++)
      {
        if (objekt[i].autor > objekt[k].autor)
        {
          swap(objekt[i], objekt[k]);
        }
      }
    }
    for (int i = 0; i < size_book; i++)
    {
    cout << "Название: " << objekt[i].nazvanie << endl;
    cout << "Автор: " << objekt[i].autor << endl;
    cout << "Издательство: " << objekt[i].izdatelstvo << endl;
    cout << "Жанр: " << objekt[i].janr << endl;
    }
 }

int main()
{
  int l;
  const int size_book = 2;
  books t[size_book] = {};
  sozd_knig(t, size_book);
  int vibor;
  do{
  cout << "\n 1. Показать книги.\n 2. Поиск книги по автору.\n 3. Поиск книги по названию.\n 4. Сортировка по названию.\n 5. Сортировка по автору.\n 6. Аннотация по названию книги. \n 7. Выход.\n" ;
  cin >> l;
  switch(l)
  {
  case 1:
     show_books(t, size_book);
     break;
  case 2:
     search_book_autor(t, size_book);
     break;
  case 3:
     search_book_nazvanie(t, size_book);
     break;
  case 4:
     sort_nazvanie(t, size_book);
     break;
  case 5:
     sort_autor(t, size_book);
     break;
  case 6:
     search_book_anot(t, size_book);
  default:
     break;
  }
  }while(l != 7);
}