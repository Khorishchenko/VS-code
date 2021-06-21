#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

//  Простое число

int prime_nums(int massiv[10], const int size);

int main()
{
	srand(time(NULL));
	const int size = 10;
	int aboba[size];
	for (int i = 0; i < size; i++) {
		aboba[i] = 20 + rand() % 21;
		cout << aboba[i] << " ";
	}
	cout << endl;
	int primes = prime_nums(aboba, size);
	cout << endl << primes << endl;
}

int prime_nums(int massiv[10], const int size) {
	int primes = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 2; j <= sqrt(massiv[i]); j++) {
			if (massiv[i] % j == 0 && massiv[i] != j) {
				massiv[i] = 0;
				break;
			}
		}
		if (massiv[i] != 0) {
			cout << massiv[i] << endl;
			primes++;
		}
	}
	return primes;
}
