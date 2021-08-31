#include <iostream>

class Parent
{
protected:
    bool flag{ false };
 
public:
    void setFlag(){}
 
    void doSomething()
    {
        setFlag();
    }
 
    void printFlag() {
        std::cout << "STATE: " << flag <<std::endl;
    }
 
};
 
class Child : public Parent
{
public:
    void setFlag() {
        flag = true;
    }
 
};
 
int main()
{
    Child object;
    object.doSomething();
    object.printFlag();
}