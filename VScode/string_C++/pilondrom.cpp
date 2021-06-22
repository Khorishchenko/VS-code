#include <iostream>
#include <string>
//#include "Header.h"
#include <iomanip>
#define newline '\n'
using namespace std;

int main()
{
string str;
 
 cout << "Enter string: ";
 getline(cin, str);
 
 stringstream stroka(str);
 string result(str);
 
 while (stroka >> str)
 { 
   if (str.size() < result.size())
 { 
   result = str;
 }
 }
 cout << "Res: " << result << endl;
 
 return 0;
}