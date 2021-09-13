#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
 

// Дан текстовый файл. Необходимо переписать его строки в другой файл. 
// Порядок строк во втором файле должен быть обратным по отношению к порядку строк в заданном файле.

int main()
{
    ifstream fin("mytext.txt");
    ofstream fout("s2.txt");

    string a;
    vector<string>x;

    while (getline(fin, a))
    {
         x.push_back(a);
    }

    for (int i = x.size(); i--;)
    {
        fout << x[i] << endl;
    }

    fin.close();
    fout.close();
    
    system("pause");
    return 0;
}