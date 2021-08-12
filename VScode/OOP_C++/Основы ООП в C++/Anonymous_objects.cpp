#include <iostream>

// Anonymous objects

// Анонимные объекты в языке C++ используются для передачи или возврата значений 
// без необходимости создавать большое количество временных переменных.

// before

#include <iostream>
 
class Dollars
{
private:
    int m_dollars;
 
public:
    Dollars(int dollars) { m_dollars = dollars; }
 
    int getDollars() const { return m_dollars; }
};
 
Dollars add(const Dollars &d1, const Dollars &d2)
{
    Dollars sum = Dollars(d1.getDollars() + d2.getDollars());
    return sum;
}
 
int main()
{
    Dollars dollars1(7);
    Dollars dollars2(9);
    Dollars sum = add(dollars1, dollars2);
    std::cout << "I have " << sum.getDollars() << " dollars." << std::endl;
 
    return 0;
}


// after

 
class Dollars
{
private:
    int m_dollars;
 
public:
    Dollars(int dollars) { m_dollars = dollars; }
 
    int getDollars() const { return m_dollars; }
};
 
Dollars add(const Dollars &d1, const Dollars &d2)
{
    return Dollars(d1.getDollars() + d2.getDollars()); // возвращаем анонимный объект класса Dollars
}
 
int main()
{
    std::cout << "I have " << add(Dollars(7), Dollars(9)).getDollars() << " dollars." << std::endl; // выводим анонимный объект класса Dollars
 
    return 0;
}




//==================================================================================//

// before

class Dollars
{
private:
    int m_dollars;
 
public:
    Dollars(int dollars) { m_dollars = dollars; }
 
    int getDollars() const { return m_dollars; }
};
 
void print(const Dollars &dollars)
{
   std::cout << dollars.getDollars() << " dollars.";
}
 
int main()
{
    Dollars dollars(7);
    print(dollars);
 
    return 0;
}


// after 

#include <iostream>
 
class Dollars
{
private:
    int m_dollars;
 
public:
    Dollars(int dollars) { m_dollars = dollars; }
 
    int getDollars() const { return m_dollars; }
};
 
void print(const Dollars &dollars)
{
   std::cout << dollars.getDollars() << " dollars.";
}
 
int main()
{
    print(Dollars(7)); // здесь мы передаем анонимный объект класса Dollars
 
    return 0;
}