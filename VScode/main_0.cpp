#include <iostream>
using namespace std;

 int main()
 {
    int n = 5;
    // Инициализация строкового массива.
    char line[] = { 'C','a','t','!','\0' };

    cout << "Word: ";
    for (int i = 0; i < n; i++)
        cout << line[i];
    cout << endl;
 }

 int main()
 {
    int n = 5;
    char line[5];   // Инициализация строкового
                            // массива.
      cin >> line;   
    cout << "Word: " << line << endl;

    

    cout << line << endl;

    return 0;
 }

 //=======================================================//
//string C++

 #include <iostream>

int main()
{
    string name("Sasha");
    cout << "My name is " << name;
 
    return 0;
}

int main()
{
    cout << "Enter your full name: ";
    string myName;
    cin >> myName; // это будет работать не так, как ожидается, поскольку извлечение данных из потока std::cin останавливается на первом пробеле
 
    cout << "Enter your age: ";
    string myAge;
    cin >> myAge;
 
    cout << "Your name is " << myName << " and your age is " << myAge;

    // Результат выполнения программы:
    // Enter your full name: Sasha Mak
    // Enter your age: Your name is Sasha and your age is Mak
}

// Использование std::getline()


int main()
{
    cout << "Enter your full name: ";
    string myName;
    getline(cin, myName); // полностью извлекаем строку в переменную myName
 
    cout << "Enter your age: ";
    string myAge;
    getline(cin, myAge); // полностью извлекаем строку в переменную myAge
 
    cout << "Your name is " << myName << " and your age is " << myAge;
}

// Использование std::getline() c std::cin

// Pick 1 or 2: 2
// Now enter your name: Hello, , you picked 2


cin.ignore(32767, '\n'); // игнорируем символы перевода строки "\n" во входящем потоке длиной 32767 символов

int main()
{
	cout << "Pick 1 or 2: ";
	int choice;
	cin >> choice;
 
	
	cout << "Now enter your name: ";
	string myName;
	getline(cin, myName);
 
	cout << "Hello, " << myName << ", you picked " << choice << '\n';
 
	return 0;
}


// Добавление строк

nt main()
{
    string x("44");
    string y("12");
 
    cout << x + y << "\n"; // объединяем строки x и y (а не складываем числа)
    x += " cats";
    std::cout << x;
 
    return 0;
}
