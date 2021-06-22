#include <iostream>
#include <string>
#include <cstring>

#define ig cin.ignore(100, '\n')
#define get(name) getline(cin, name)
#define len(name) name.size()
using namespace std;

// Shortest word in a line


int main()
{
    string name;
    get(name);
    int new_size = 1;
    for (int i = 0, k = name.size(); i < k; i++) 
    {
        if (name[i] != ' ') {
            continue;
        }
        new_size++;
    }
    cout << new_size << endl;
    string* ptrchar = new string[new_size];
    for (int i = 0, v = 0, k = name.size(); i < k; i++) {
        if (name[i] != ' ') {
            ptrchar[v] += name[i];
            continue;
        }
        v++;
    }
    int min = 100;
    int word;
    for (int i = 0; i < new_size; i++) {
        if (min > ptrchar[i].size() && ptrchar[i] != ""){
            min = ptrchar[i].size();
            word = i;
        }
    }
    cout << ptrchar[word] << endl;
    ptrchar[word][1] = '!';

    int size_ptrchar_word = ptrchar[word].size();

    for (int i = 0; i < size_ptrchar_word; i++)
    {
        cout << ptrchar[word][i] << endl;
    }


    

}