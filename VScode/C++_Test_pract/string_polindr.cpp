#include <iostream>
#include <string>
using namespace std;

#define get(name) getline(cin, name)

string InvertStr(string Text)
{
    for (int i = 0, size = (Text.size() / 2); i < size; i++)
        swap(Text[i], Text[size - i - 1]);
    return Text;
}

bool IsPalindrom(string Text)
{
    string invert_text = InvertStr(Text);
    return Text.compare(invert_text) == 0;
}

int main()
{
    string Text;
    cout << "Print your text\n> ";
    get(Text);
    if (IsPalindrom(Text))
        cout << "Your Text is polindrom !" << endl;
    else 
        cout << "Your Text is not polindrom !" << endl;
}