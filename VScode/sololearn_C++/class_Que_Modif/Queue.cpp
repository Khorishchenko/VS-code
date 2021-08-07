#include "MyClass.h"

void Queue::add(int data){
    queue[size] = data; 
	size++;
}

void Queue::remove(){
        if (size == 0) { 
			cout << "Queue is empty"<< endl; 
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