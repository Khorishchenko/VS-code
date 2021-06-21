#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
int main()
{
    int rombSize;
    cout << "Size of romb: ";
    cin >> rombSize;
    cout << "Symbol for romb: ";
    cin.ignore();
    char symb = getchar();
    int horCount;
    cout << "Count of rombs on horizontall axis: ";
    cin >> horCount;
    int verCount = 16;
    cout << "Count of rombs on verticall axis: ";
    cin >> verCount;
    int rombSizeHalf = rombSize / 2;
    int width = rombSize * horCount;
    int height = rombSize * verCount;
    string text;
    for (int y = 0; y <= height; y++) {
        for (int x = 0; x <= width; x++)
            if (abs(x % rombSize - rombSizeHalf) + abs(y % rombSize - rombSizeHalf) == rombSizeHalf)
                text += symb;
            else
                text += " ";
        text += "\n";
    }
    //cout << text;
    ofstream file;
    file.open("/Users/sergejhorisenko/Desktop/example.txt", ofstream::out | ofstream::trunc);
    file << text;
    file.close();
    cout << "Done!!!";
    return 0;
}