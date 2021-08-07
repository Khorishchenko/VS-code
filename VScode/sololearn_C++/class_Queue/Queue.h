#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

// Керування чергами


// Ми продовжуємо розвивати нашу систему управління чергами, яку ми створили в попередньому модулі.
// Вас просять додати новий функціонал: додавання двох черг разом. В результаті повинна вийти нова черга, де перші стоять елементи першої черги,
//  а потім - елементи другої черги.

// Враховуючи клас Queue, перевантажте оператор +, щоб код у main працював і успішно додавав дві черги.
// Перевантажений оператор повинен повернути новий об'єкт "Черга", який містить елементи першої черги, а потім елементи другої черги.


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