#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    string expr;
    cout << "Expression: ", getline(cin, expr);
    expr += ' ';
    int length = expr.size();
    int action = 0;
    int result = 0;
    string word;
    for (int i = 0; i < length; i++)
    {
        if (string(" +-*/").find(expr[i]) == -1)
            word += expr[i];
        else
        {
            if (!word.empty())
            {
                int value = stoi(word);
                switch (action)
                {
                case 0:
                    result = value;
                    break;
                case 1:
                    result += value;
                    break;
                case 2:
                    result -= value;
                    break;
                case 3:
                    result *= value;
                    break;
                case 4:
                    result /= value;
                    break;
                }
                word.clear();
            }
            switch (expr[i])
            {
            case '+':
                action = 1;
                break;
            case '-':
                action = 2;
                break;
            case '*':
                action = 3;
                break;
            case '/':
                action = 4;
                break;
            }
        }
    }
    cout << "Result: " << result << endl;
}