#include <iostream>
using namespace std;

string InvertStr(string Text)
{
    int Size = Text.size();
    for (int i = 0; i < Size / 2; i++)
        swap(Text[i], Text[Size - i - 1]);
    return Text;
}

bool IsPalindrome(string Text)
{
    string Inverted = InvertStr(Text);
    return Text.compare(Inverted) == 0;
}

int main()
{
    string Text;
    cout << "Text\n> ";
    getline(cin, Text);
    if (IsPalindrome(Text))
        cout << Text << " is palindrome.\n";
    else
        cout << Text << " is not palindrome.\n";
}