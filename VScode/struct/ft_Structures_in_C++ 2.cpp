#include <iostream>
using namespace std;
 

struct	building     		//Создаем структуру!
{                  
	char const	*owner;       	//здесь будет храниться имя владельца
	char const	*city;        	//название города
	int		amountRooms;   	//количество комнат
	float		price;       	//цена
};                 
 
int	main()
{
	setlocale (LC_ALL, "rus");
 
	building apartment1;   			//это объект структуры с типом данных, именем структуры, building
 
	apartment1.owner = "Денис"; 		//заполняем данные о владельце и т.д.
	apartment1.city = "Симферополь";      
	apartment1.amountRooms = 5;
	apartment1.price = 150000;
 
	cout << "Владелец квартиры: " << apartment1.owner << endl;
	cout << "Квартира находится в городе: " << apartment1.city << endl;
	cout << "Количество комнат: " << apartment1.amountRooms << endl;
	cout << "Стоимость: " << apartment1.price << " $" << endl;
	
	cout << "Для продолжения нажмите на Enter... ";
        getchar(); 
	return 0;
}







// ================================================================//



//создаем еще одну структуру, чтобы вложить ее в структуру building



struct	date 		 // дата постройки
{
	char const	*month; 	// Месяц постройки дома
	int 		year; 		// Год
};
 
struct	building
{
	char const	*owner;
	char const	*city;
	int		amountRooms;
	float		price;
 
	date built; 			//вкладываем одну структуру в определение второй
};
 
void	show(building &object)		//создаем функцию, которая принимает структуру, как параметр
{
	cout << "Владелец квартиры: " << object.owner << endl;
	cout << "Квартира находится в городе: " << object.city << endl;
	cout << "Количество комнат: " << object.amountRooms << endl;
	cout << "Стоимость: " << object.price << " $" << endl;
	cout << "Дата постройки: " << object.built.month << ' ' << object.built.year << endl;
}
 
int	main()
{
	setlocale (LC_ALL, "rus");
 
	building apartment1 = {}; 			// установит значения всех элементов структуры в 0;
 
	apartment1.owner = "Денис";
	apartment1.city = "Симферополь";
	apartment1.amountRooms = 5;
	apartment1.price = 150000;
	apartment1.built.month = "январь";
	apartment1.built.year = 2013;

	show(apartment1);

	return 0;
}



// ================================================================//



// Ініціалізація 


struct Human
{
	int age;
	const char *name;
};

int main()
{
	Human Student = {23, "sergey"};
	cout << Student.age << ' ' << Student.name << endl;

	return 0;
}

// ================================================================//


// Оголошення Обєктів 


// struct Human
// {
// 	int age;
// 	const char *name;
// }Student;

// int main()
// {
// 	Student = {23, "sergey"};
// 	cout << Student.age << ' ' << Student.name << endl;

// 	return 0;
// }


// ================================================================//


// Без дескриптора 

struct 					
{
	int age;
	const char *name;
}Student, Student2;

int main()
{
	Student = {23, "sergey"};
	cout << Student.age << ' ' << Student.name << endl;

	Student2 = Student;										// Присвоєння 

	cout << Student2.age << ' ' << Student2.name << endl;

	return 0;
}

