#include <iostream>
#include <cstring>
using namespace std;

struct	date 		 // дата постройки
{
	string		month; 	// Месяц постройки дома
	int 		year; 		// Год
};
 
struct	building
{
	string		owner;
	string		city;
	int		amountRooms;
	int		price;
 
	date built; 			//вкладываем одну структуру в определение второй
};

#define name(_st) cout << "Введите Владелец квартиры: "; getline(cin, _st.owner)
#define name_city(_st) cout << "Введите Квартира находится в городе: "; getline(cin, _st.city)
#define count_room(_st) cout << "Введите Количество комнат:  "; cin >> _st.amountRooms; cin.ignore(100, '\n')
#define price(_st) cout << "Введите Стоимость:  "; cin >> _st.price; cin.ignore(100, '\n')
#define month(_st) cout << "Введите Дата постройки month: "; getline(cin, _st.built.month)
#define year(_st) cout << "Введите Дата постройки year: "; cin >> _st.built.year; cin.ignore(100, '\n')

// or you can make a function

void    get(building Obj[], const int size_st){
    for (int i = 0; i < size_st; i++){
        cout << "Введите Владелец квартиры: "; getline(cin, Obj[i].owner);
        cout << "Введите Квартира находится в городе: "; getline(cin, Obj[i].city);
        cout << "Введите Количество комнат:  "; cin >> Obj[i].amountRooms; cin.ignore(100, '\n');
        cout << "Введите Стоимость:  "; cin >> Obj[i].price; cin.ignore(100, '\n');
        cout << "Введите Дата постройки month: "; getline(cin, Obj[i].built.month);
        cout << "Введите Дата постройки year: "; cin >> Obj[i].built.year; cin.ignore(100, '\n');
    }
}
 
void	show(building object[], const int size_st){		//создаем функцию, которая принимает структуру, как параметр
	for (int i = 0; i < size_st; i++){
        cout << "\napartment[ " << i + 1 <<" ]" << endl;
		cout << "Владелец квартиры: " << object[i].owner << endl;
		cout << "Квартира находится в городе: " << object[i].city << endl;
		cout << "Количество комнат: " << object[i].amountRooms << endl;
		cout << "Стоимость: " << object[i].price << " $" << endl;
		cout << "Дата постройки: " << object[i].built.month << '.' << object[i].built.year << endl << endl;
	}
}
 
int	main()
{
	setlocale (LC_ALL, "rus");
 
 	const int size_st = 1;
	building apartment1[size_st]; 			// установит значения всех элементов структуры в 0;
 
 	for (int i = 0; i < size_st; i++)
 	{
        // cout << "\napartment[ " << i + 1 <<" ]" << endl;
		// name(apartment1[i]);
		// name_city(apartment1[i]);
		// count_room(apartment1[i]);
		// price(apartment1[i]);
		// month(apartment1[i]);
		// year(apartment1[i]);

        cout << "\napartment[ " << i + 1 <<" ]" << endl;
		get(apartment1, size_st);
	}

	show(apartment1, size_st);

	return 0;
}