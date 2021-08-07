#include <iostream>
using namespace std; 

// Керування чергами


// Ми продовжуємо розвивати нашу систему управління чергами, яку ми створили в попередньому модулі.
// Вас просять додати новий функціонал: додавання двох черг разом. В результаті повинна вийти нова черга, де перші стоять елементи першої черги,
//  а потім - елементи другої черги.

// Враховуючи клас Queue, перевантажте оператор +, щоб код у main працював і успішно додавав дві черги.
// Перевантажений оператор повинен повернути новий об'єкт "Черга", який містить елементи першої черги, а потім елементи другої черги.



class Queue { 
	int size; 
	int* queue; 
	
	public:
	Queue() { 
		size = 0;
		queue = new int[100];
	}
	void add(int data);
	void remove();
	void print();
	//your code goes here
    Queue operator+(Queue &Obj);


	
}; 

void Queue::add(int data){
    queue[size] = data; 
	size++;
}

void Queue::remove(){
        if (size == 0) { 
			cout << "Queue is empty"<<endl; 
			return; 
		} 
		else { 
			for (int i = 0; i < size - 1; i++) { 
				queue[i] = queue[i + 1]; 
			} 
			size--; 
		} 
}

void Queue::print(){
        if (size == 0) { 
			cout << "Queue is empty"<<endl; 
			return; 
		} 
		for (int i = 0; i < size; i++) { 
			cout<<queue[i]<<" <- ";
		} 
		cout << endl;
}

Queue Queue::operator+(Queue &obj){
    Queue res;
    for (int i = 0; i < this->size; i++)
        res.add(this->queue[i]);
    for (int i = 0; i < obj.size; i++)
        res.add(obj.queue[i]);
    return res;
}


int main() { 
	Queue q1; 
	q1.add(42); q1.add(2); q1.add(8);  q1.add(1);
	Queue q2;
	q2.add(3); q2.add(66); q2.add(128);  q2.add(5);
	Queue q3 = q1 + q2;
	q3.print();

	return 0; 
} 