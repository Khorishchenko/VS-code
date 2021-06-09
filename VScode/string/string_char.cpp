#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define ig cin.ignore(100, '\n')
#define get(name) getline(cin, name)

int main()
{
    char name[6] {'H', 'e', 'l', 'l', 'o'};

    int i = 0;
    while(name[i] != '\0')
        cout << name[i++] << endl;

    char name2[] = "hello";

    cout << name2 << endl;



    char name2[6];
    char nameAndsurname[11];

    cin.getline(nameAndsurname, 11);

    cout << nameAndsurname << endl;

    cin >> name2;

    cout << name2 << endl;





    string name3;
    
    getline(cin, name3);

    cout << name3 << endl;

    strlen(name);

    for (int i = 0, k = name3.length(); i < k; i++)
        cout << name3[i] << endl;




    cout << "Pick 1 or 2: ";
	int choice;
	cin >> choice;
    
    ig;                                 // cin.ignore(100, '\n')
    
	cout << "Now enter your name: ";
	string myName;
	getline(cin, myName);
 
	cout << "Hello, " << myName << ", you picked " << choice << '\n';
    

    string name4;
    string name5;
    get(name4);
    get(name5);

    name4 += name5;

    cout << name2 << endl;


    




    
}