#include <iostream>
using namespace std;

class Titan
{
    private:
        string name;
    public:
        void showName_Titan(string name);
};

void Titan :: showName_Titan(string name)
{
    this->name = name;
    cout << this->name << endl;
}


int main(){
    Titan b;
    b.showName_Titan("mark");
}