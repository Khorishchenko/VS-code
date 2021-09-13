#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector <string> array{
        " Stambul \n 9 \n Leo Lichshbin Markovich \n 7.01.2022 \n\n",
        " Ukraine \n 23 \n Sam Smith Ford \n 31.02.2055 \n\n",
        " Italia \n 14 \n Mark Dorn Volha \n 12.11.2023 \n\n",
        " The USA \n 1 \n Donald Tramp Yurevich \n 25.5.2025 \n\n",
        " Brazilia \n 18 \n Urban So Spinoo \n 16.8.2018 \n\n" };
    for (auto& element : array)
        cout << element;
    cout << "\n if you would like to delete application enter wich one, if not enter 0 \n" << endl;
    int us_del;
    cin >> us_del;
    cin.ignore(100, '\n');

    cout << endl;
    if (us_del > 0)
        array.erase(array.begin() + us_del - 1);
    else
        cout << "okey, all applications are saved!)\n" << endl;
    for (auto& element : array)
        cout << element;
    cout << "\n if you would like to app application enter this, if not enter - 'No' \n" << endl;
    string us_txt = "";
    getline(cin, us_txt);
    if (us_txt == "No") {
        cout << "okey, all applications are saved!)\n" << endl;
    }
    else {
        // for (int i = 0; i < us_txt.size(); i++)
        //     us_txt[0] += ('\n' + us_txt[i]);
        // cout << us_txt << endl;
        array.push_back(us_txt);
    }
    for (auto& element : array)
        cout << element;
    cout << endl;




}