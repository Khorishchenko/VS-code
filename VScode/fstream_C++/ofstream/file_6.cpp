#include<iostream>
#include <string>
#include <fstream> 
using namespace std;


#define get(name) getline(cin, name)
#define len(name) name.size()


// Дан текстовый файл. Необходимо переписать его строки в другой файл. 
// Порядок строк во втором файле должен быть обратным по отношению к порядку строк в заданном файле.


int main() 
{
    ifstream file;
    ofstream file_2;


    file.open("C:/Users/sapun/Desktop/myfile.txt");

    file_2.open("C:/Users/sapun/Desktop/myfile2.txt");


    if (file.is_open())
        cout << "True\n" << endl;
    else {
        cout << "False\n\n" << endl;
    }
    int stro = 0;
    string str;
    while (!file.eof()) {
        getline(file, str);
        stro++;
    }
    string* stre = new string[stro];
    file.seekg(0);
    for(int i = 0; i < stro; i++){
        getline(file, str);
        stre[i] = str;
    }

    for (int g = 0; g < stro; g++) {
        int plan = 1;
        for (int i = 0; i < len(stre[stro - g - 1]); i++) {
            if (stre[stro - g - 1][i] != ' ') {
                continue;
            }
            plan++;
        }
        string* sharaga = new string[plan];
        for (int i = 0, j = 0; i < len(stre[stro - g - 1]); i++) {
            if (stre[stro - g - 1][i] != ' ') {
                sharaga[j] += stre[stro - g - 1][i];
                continue;
            }
            j++;
        }
        for (int i = 0; i < plan; i++) {
            file_2 << sharaga[plan - i - 1] << " ";
        }
        file_2 << endl;
    }
    file_2.flush();
    file.close();
}