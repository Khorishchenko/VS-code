#ifndef MyClass_H
#define MyClass_H

#include <iostream>
using namespace std;

// Керування чергами


// Ваш клас черги працює і працює у компанії з обслуговування клієнтів. Компанія відкриває нову філію та просить створити для них іншу версію Черги. 
// Єдина відмінність - це спосіб відображення черги: кожен номер у новому рядку.

// Ви вирішуєте створити новий клас під назвою Queue2, який походить від класу Queue і замінює метод print (), виводячи кожен елемент черги в новий рядок.
// Не забудьте змінити специфікатор доступу учасників черги, оскільки вони не будуть успадковані, якщо вони є приватними.


class Queue { 
    private:
        int size; 
        int* queue; 
	
	public:
        Queue() : size(0), queue(new int[100]) { }
        void add(int data);
        void remove();
        void print();

	//your code goes here
        Queue operator+(Queue &Obj);
        ~Queue()
        {
                delete [] queue;
                queue = nullptr;
        }
}; 



#endif