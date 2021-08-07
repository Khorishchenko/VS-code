#include <iostream>
using namespace std; 



// Керування чергами


// Ви працюєте над системою управління чергою і вам потрібно створити клас для зберігання даних черги, які є ідентифікаторами клієнтів (цілими числами).
// Ви створюєте клас черги, який має атрибут розміру та масив для зберігання даних черги.
// Клас має метод remove () для видалення переднього елемента черги, метод print () для виведення черги.

// Вам потрібно створити метод add () для класу Queue, який візьме елемент і додасть його до кінця черги.
// Код повинен бути повністю робочим, щоб оголошення Queue і код маніпуляції в main () працювали.
// Не забудьте збільшити розмір після додавання елемента до масиву.
// Уважно прочитайте код, перш ніж вносити будь -які зміни.

class Queue { 
	int size; 
	int* queue; 
	
	public:
	Queue() {
		size = 0;
		queue = new int[100];
	}
	void remove() { 
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
	void print() { 
		if (size == 0) { 
			cout << "Queue is empty"<<endl; 
			return; 
		} 
		for (int i = 0; i < size; i++) { 
			cout<<queue[i]<<" <- ";
		} 
		cout <<endl;
	}
	//your code goes here
    void add(int value){
        queue[size++] = value;
    }

    ~Queue(){
        cout << "Move destructor " << endl;
        delete [] queue;
        queue = nullptr;
    }
	
}; 

int main() { 
	Queue q; 
	q.add(42); q.add(2); q.add(8); q.add(1); 
	q.print();
	q.remove(); 
	q.add(128); 
	q.print(); 
	q.remove(); 
	q.remove(); 
	q.print(); 

	return 0; 
} 