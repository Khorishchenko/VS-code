#include <iostream>
#include <string>
using namespace std;

class Apple;

class eat
{
    private:
        string    name;
        float     mass;

    public:
        eat(string name, int mass)
        {
            this->mass = mass, cout << "class eat " << this->mass << endl;
            this->name = name, cout << "class eat " << this->name << endl;
        }
        void eats(Apple &apple);
};


class Apple
{
    friend  eat;            // friend class eat !!!
    private:
        string  color;
        float   mass;
    public:
        void Appl();

        // friend void eat::eats(Apple &apple);         // friend metod !!!

};


void eat::eats(Apple &apple){
    apple.color = this->name;
    apple.mass = this->mass;
}

void Apple::Appl(){
    cout << color << ' ' << mass << endl;
}

int main()
{
    eat b("Green", 15.0);
    Apple d;
    b.eats(d);
    d.Appl();
}