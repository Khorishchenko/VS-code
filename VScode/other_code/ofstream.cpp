#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


int main()
{

	ofstream fileo;
	 
	// Создаем файл
	fileo.open("/Users/sergejhorisenko/Desktop/VS-code/VScode/fstream/myfile.txt", ios_base::app);
	 
	// Открываем для дописывания
	fileo.open("d:\\1\\Результат.txt"/*,ios_base::app*/);





//===================================================================//
	// Или конструктором:

	// Создаем файл
	ofstream fileo("d:\\1\\Результат.txt");
	 
	// Открываем для дописывания
	ofstream fileo("d:\\1\\Результат.txt",ios_base::app);








//===================================================================//

	 if( fileo.is_open() ) cout << "Файл создан" << endl;
	 else {
		 cout << "Файл не создан";
	 	return -1;
	 }


//===================================================================//

					// Оператор <<	


	 string s = "Привет мир";
	 
	        // Вещественное
	        double d = 123.456;
	 fileo << s << endl << d << endl;




//===================================================================//


	 // Метод write

	  // Запись побайтно
	 // Строки
	 char *sc = "И еще раз\n";
	 fileo.write(sc,strlen(sc));
	 
	 // Целого в машинном представлении
	 int k = 123;
	 fileo.write((char*)&k,sizeof(k));			//	Этот метод принимает два параметра: Указатель на 
	 											//  блок данных и количество байт, который этот блок занимает!
	 
	 // Вещественного в машинном представлении
	 double dd = 456.789;
	 fileo.write((char*)&dd,sizeof(dd));


//===================================================================//


	 fileo.flush();

	//  fileo.seekp();
	//  fileo.tellp();

}
