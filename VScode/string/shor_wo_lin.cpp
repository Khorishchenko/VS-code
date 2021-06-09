#include <iostream>
#include <string>
using namespace std;

// Shortest word in a line

string f(string str)
{
    int size = str.size();
    string word = "";
    string smallword;
    for (int i = 0; i < size; i++)
    {
        if (str[i] != ' ')
            word += str[i];
        else {
            if (word.size() > 0 && (smallword.size() == 0 || smallword.size() > word.size()))
                smallword = word;
            word = "";
        }
    }
    return smallword;
}

int main()
{
    string str;
    cout << "Text\n> ";
    getline(cin, str);
    str = str + " ";
    cout << "Smallest word: " << f(str);
}