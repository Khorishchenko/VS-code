#include <iostream>
#include <iomanip>
using namespace std;


class Tiles
{
    public:
        int brand;
        int size_h;
        int size_w;
        int price;
        void getData();
};

void Tiles::getData()
{
     cout << brand << ' ' << size_h << ' ' << size_w << ' ' << price << endl;
}

int main()
{
    Tiles Obj;
    Obj.brand = 10;
    Obj.price =10000;
    Obj.size_h = 10000;
    Obj.size_w = 100;
    Obj.getData();
}