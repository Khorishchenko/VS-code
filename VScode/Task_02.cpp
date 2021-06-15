#include <iostream>
#include <string>
using namespace std;

void runCode();
int mx_strlen(string szStr);
string decode(string &s, int k);
string szString_2_2_1(int nNum, string szString, string szString_2, int k);

int main()
{
	runCode();
	return 0;
}

void runCode()
{
    // Entrypoint to debug your function
  
    int i = 0;
    int nKey = 5;
    string text = "hello2world3";

    string letter = decode(text, nKey);
    for (int i = 0; i < letter.size(); i++)
        cout << "Letter is : " << letter[i] << endl;
}

string decode(string &s, int k)
{
     // Write your code here...
    int nKey = 0;
    int nLen = s.size();
    int nNum = 0;
    string szLetter;
    string szString;
    string szString_2;

    for (int i = 0; i < nLen; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') ||
			(s[i] >= 'A' && s[i] <= 'Z'))
        {   
                szString[i] = s[i];
        }

        if (s[i] >= 48 && s[i] <= 58 && nKey == 0)
        {
            nNum *= 10;
            nNum += s[i] - 48;
            nNum -= 1;

            int count = i;
            int b = count;

            for (int a = 0; a < i; a++)
            {
                szString_2 = szString[a];
            }

            for (int i = 0; i < nNum; i++)
            {
                int a = 0;
                while (a < count)
                {
                    szString_2 = szString[a];
                    a++;
                    b++;
                }
                b += b;
            }
            nKey = 1;
        }

        else if (s[i] >= 48 && s[i] <= 58 && nKey == 1)
        {
            nNum = 0;
            nNum *= 10;
            nNum += s[i] - 48;
            nNum -= 1;

            szLetter = szString_2_2_1(nNum, szString, szString_2, k);
        }
   	}
    return szLetter;
}

string szString_2_2_1(int nNum, string szString, string szString_2, int k)
{
    int nA = szString_2.size();
    int nA_2 = (nA / 2) + 1;
    string szTest;
    string szLetter;

   for (int i = 0; i < szString.size(); i++)
    {
        szString_2[nA++] = szString[nA_2++];
    }

    int nArr = 0;
    int nSize = (nA * nNum) + nA;
    char *str = new char(nA);

    for (int i = 0; i <= nNum; i++)
    {
        for (int y = 0; y < szString_2.size(); y++)
        {
            str[nArr++] = szString_2[y];
        }
    }
   
    for (int i = 0, n = 1; i < k; i++, n++)
    {   
        if (n == k)
            szLetter = str[i];
    }
    delete str;
    str = NULL;

    return szLetter;
}
