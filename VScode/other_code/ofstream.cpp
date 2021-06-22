#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


int main()
{

	ofstream file;
	 
	// Создаем файл
	file.open("/Users/sergejhorisenko/Desktop/VS-code/VScode/fstream/myfile.txt");
	 
	// Открываем для дописывания
	file.open("/Users/sergejhorisenko/Desktop/VS-code/VScode/fstream/myfile.txt", ios_base::app);





// //===================================================================//
// 	// Или конструктором:

// 	// Создаем файл
// 	ofstream file("d:\\1\\Результат.txt");
	 
// 	// Открываем для дописывания
// 	ofstream file("d:\\1\\Результат.txt",ios_base::app);








//===================================================================//

	 if( file.is_open() ) 
	 	cout << "Файл создан" << endl;
	 else {
		cout << "Файл не создан";
	 	return -1;
	 }


//===================================================================//

	// Оператор <<	


	string s = "Привет мир";
	 
	// Вещественное
	double d = 123.456;

	file << s << endl;
	file << d << endl;

	file.flush();


//===================================================================//


	 // Метод write

	  // Запись побайтно
	 // Строки
	 char *sc = "И еще раз\n";
	 file.write(sc,strlen(sc));
	 
	 // Целого в машинном представлении
	 int k = 123;
	 file.write((char*)&k,sizeof(k));			//	Этот метод принимает два параметра: Указатель на 
	 											//  блок данных и количество байт, который этот блок занимает!
	 
	 // Вещественного в машинном представлении
	 double dd = 456.789;
	 file.write((char*)&dd,sizeof(dd));


//===================================================================//


	 file.flush();

	  file.seekp();
	  file.tellp();

}
