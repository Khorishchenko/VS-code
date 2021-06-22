#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream file_r;                                                                             // Об'єкт для запису в файл
    ifstream file_2;
    ifstream file_b;

    file_r.open("/Users/sergejhorisenko/Desktop/VS-code/VScode/fstream/myfile.txt");
    //file_.open("/Users/sergejhorisenko/Desktop/VS-code/VScode/fstream/ofstream/mytext.txt");
    file_b.open("/Users/sergejhorisenko/Desktop/VS-code/VScode/fstream/bad_word.txt");


    if(file_r.is_open() && file_b.is_open())
        cout << "Good file is open!" << endl;
    else 
        cout << "Don't goot, file is not open!" << endl;

    string* str = new string[3];
    string text;
    string bad, text_2;
    int i = 0;
    while (!file_b.eof()) {
        file_b >> bad;
        str[i++] = bad;

 

    }
    //cout << *str << "\n";
    i = 0;
    //for (int i = 0; i < 3; i++)
        //cout << str[i];
    while(!file_r.eof()) {
        file_r >> text;
        cout << text << endl;
        if (text == str[i] || text == str[1] || text == str[2]) {
            text = ' ';
        }
        //cout << text << endl;
        text_2 += text + ' ';
    }
    cout << text_2 << endl;

 


}

    