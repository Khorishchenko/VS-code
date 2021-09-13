#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <iomanip>
#include <fstream>
#define mno(a, b) a * b;
using namespace std;

 

int main()
{
    int num = 0;
    // 1 - Kamen
    // 2 - Nozhnicy
    // 3 - Bumaga

 

    int choose, botChoose;
    string you, bot;
    for (int i = 0; i < 5; i++)
    {
        cin >> choose;
        botChoose = rand() % 2;
        if (choose == 1)
        {
            you = "Kamen";
        }
        else if (choose == 2)
        {
            you = "Nozhnicy";
        }
        else if (choose == 3)
        {
            you = "Bumaga";
        }
        else
        {
            cout << "ENTER NUM FROM 1 TO 3";
        }
        cout << you << endl;

 

 

        if (botChoose == 0)
        {
            bot = "Kamen";
        }
        else if (botChoose == 1)
        {
            bot = "Nozhnicy";
        }
        else if (botChoose == 2)
        {
            bot = "Bumaga";
        }
        cout << bot << endl;

 

        if (you == "Kamen" && bot == "Nozhnicy")
        {
            cout << "You win" << endl;
        }
        else if (you == "Nozhnicy" && bot == "Bumaga")
        {
            cout << "You win" << endl;
        }
        else if (you == "Bumaga" && bot == "Kamen")
        {
            cout << "You win" << endl;
        }
        else
        {
            cout << "YOU LOSE" << endl;
        }
    }
}