#include "MyClass.h"


int main() { 
	Queue q1; 
	q1.add(42); q1.add(2); q1.add(8);  q1.add(1);
    q1.print();
    
	Queue2 q2;
	q2.add(3); q2.add(66); q2.add(128);  q2.add(5);q2.add(111);q2.add(77890);
	q2.print();

	return 0; 
} 