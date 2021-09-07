#include <iostream>

// Множественное наследование

#include <string>
 
class Human
{
private:
    std::string m_name;
    int m_age;
 
public:
    Human(std::string name, int age)
        : m_name(name), m_age(age)
    {
    }
 
    std::string getName() { return m_name; }
    int getAge() { return m_age; }
};
 
class Employee
{
private:
    std::string m_employer;
    double m_wage;
 
public:
    Employee(std::string employer, double wage)
        : m_employer(employer), m_wage(wage)
    {
    }
 
    std::string getEmployer() { return m_employer; }
    double getWage() { return m_wage; }
};
 
// Класс Teacher открыто наследует свойства классов Human и Employee
class Teacher: public Human, public Employee
{
private:
     int m_teachesGrade;
 
public:
    Teacher(std::string name, int age, std::string employer, double wage, int teachesGrade)
        : Human(name, age), Employee(employer, wage), m_teachesGrade(teachesGrade)
    {
    }
};


//-----------------------------------------------------------------------------------------------------------//

class USBDevice
{
private:
    long m_id;
 
public:
    USBDevice(long id)
        : m_id(id)
    {
    }
 
    long getID() { return m_id; }
};
 
class NetworkDevice
{
private:
    long m_id;
 
public:
    NetworkDevice(long id)
        : m_id(id)
    {
    }
 
    long getID() { return m_id; }
};
 
class WirelessAdapter: public USBDevice, public NetworkDevice
{
public:
    WirelessAdapter(long usbId, long networkId)
        : USBDevice(usbId), NetworkDevice(networkId)
    {
    }
};
 
int main()
{
    WirelessAdapter c54G(6334, 292651);
    std::cout << c54G.getID(); // какую версию getID() здесь следует вызывать?
 
    return 0;
}