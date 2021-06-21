#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

// https://www.youtube.com/watch?v=vpXLHVHr-xg&ab_channel=HanDi
// https://ravesli.com/urok-202-dlina-i-yomkost-std-string/

// 2. Взаимосвязь строк и указателей !!!

const char *month_name(int);
const int n = 15;

int main()
{
    const char *message;
    char prv[] = "and bye!";
    char *pr = prv;


	message = "Hello";
    cout << " " << message << " " << pr << "\n";
    int i = 0;
    while  (*(pr + i) != '\0')
    {
         cout << *(pr + i++) << " ";
	}
	cout << endl;



    /* ------------- */
    for (int i = 0; i < n; i++)
        cout << "Month number " << i << " - " <<
                month_name(i) << "\n";
}


const char *month_name (int k)  /* Название k-го месяца */
{
	const char *name[] = {
   					"none","January",
					"February","March","April",
					"May","June","July","August",
					"September","October","November",
					"December" };

	return (k < 1 || k > 12) ? name[0] : name[k];
  
}


//==============================================================//


// // Определение длины строк
// strlen();

// char *с = "Any old string....";
// int len;

// len = strlen(с);


// //==============================================================//

// // Копирование строк

// char*с1 = new char [10];
// char*с2 = new char [10];
// c1 = c2; 				// память выделенная под с1 - потерялась

// strcpy(с1, с2);


// //==============================================================//

// // Конкатенация строк

// char original[128] = "Test ";
// strcat(original, " one, two, three!");

// strcat(strcat(c1,c2),c3) 			// - может использоваться как каскад нескольких вызовов функций



// //==============================================================//



// // Поиск символов

// // Пример использования функции strchr().
// #define get_ch(name, size) cin.getline(name, size)

// char *filename = new char[128];
// cout << "Enter name of file: ";

// get_ch(filename, 128);
// cout << "\nName of file: " << filename << "\n";

// if (strchr (filename,'.'))
//     cout << "Name has extension" << "\n";
// else
//     strcat (filename,".TXT");
    
// cout << "Name of file: " << filename << "\n";
// delete [] filename;

// char *p;
//  char s[]="Abracadabra";
//  p = strchr(s,'a'); //присваивают указателю p адрес первой строчной буквы 
//  					// 'а' в строке «Abracadabra».




