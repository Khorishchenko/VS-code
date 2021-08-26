#include <iostream>

// Перегрузка операций преобразования типов данных

// before 

class Dollars
{
private:
    int m_dollars;
public:
    Dollars(int dollars=0)
    {
        m_dollars = dollars;
    }
 
    int getDollars() { return m_dollars; }
    void setDollars(int dollars) { m_dollars = dollars; }
};


void printInt(int value)
{
    std::cout << value;
}
 
int main()
{
    Dollars dollars(9);
    printInt(dollars.getDollars()); // выведется 9
 
    return 0;
}




