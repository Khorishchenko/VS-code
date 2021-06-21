#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


// Дан массив строк. Записать их в файл, рас- положив каждый элемент массива на отдельной строке с сохранением порядка.

int main()
{
    ofstream file;              // Об'єкт для запису в файл
    // ifstream file_2;

    // file_2.open("/Users/sergejhorisenko/Desktop/VS-code/VScode/fstream/myfile.txt");
    file.open("/Users/sergejhorisenko/Desktop/VS-code/VScode/fstream/ofstream/mytext.txt", ofstream::app);      //Створення файлу за допомогою опен 
                                                                                                                // + ofstream::app - додати в кінець файлу запис 

    if(file.is_open())
        cout << "Good file is open!" << endl;
    else 
        cout << "Don't goot, file is not open!" << endl;


    char arr[10];
    for (int i = 0; i < 9; i++)
    {
        cout << setw(4) << (arr[i] = (char)(rand() % 26 + 65)); 
    }
    cout << endl;

    arr[9] = '\0';

    int i = 0;
    while(arr[i] != '\0')
        file << '\n' << arr[i++];

    file.close();
    return 0;
}
