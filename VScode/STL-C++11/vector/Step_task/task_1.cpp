#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

struct student {
    vector <string > name;
    int  year;
    int  rating;
};


int main()
{
    student s[4];
    for (int i = 0; i < 4; i++) {
        string us_name;
        cin >> us_name;
        s[i].name.push_back(us_name);
        int us_year;
        cin >> us_year;
        s[i].year = us_year;
        int us_rating;
        cin >> us_rating;
        s[i].rating = us_rating;
    }
    
    for (int i = 0; i < 4; i++) {
        sort(s[i].name.begin(), s[i].name.end());
    }
    int x = 0;
    x = (s[0].rating + s[1].rating + s[2].rating + s[3].rating) / 4;
    for (int i = 0; i < 4; i++) {
        if (x < s[i].rating) {
            x = s[i].rating;
            
        }
    }
    cout << x << endl;
}