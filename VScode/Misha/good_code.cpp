#include <iostream>
#include <cstring>
//#include <string>
//#include <fcntl.h>
using namespace std;
​



string Inpute(string Text) {​
    cout << Text;
    string Result;
    cin >> Result;
    return Result;
}
​
void Print(string Text) {​
    wcout << Text << endl;
}
​
int main()
{​
   // _setmode(_fileno(stdout), _O_U16TEXT);
   // _setmode(_fileno(stdin), _O_U16TEXT);

    string Answer = Inpute("Текст\n> ");
    string Symb = Inpute("Символ который удалить> ");
    string New;
    for (size_t i = 0; i < Answer.size(); i++)
        if (Symb != Answer[i])
            New += Answer[i];
    Print("Новый текст: " + New);
}​