#include <iostream>
#include <string>

// Более сложный пример
// Рассмотрим класс Animal из предыдущего урока, добавив тестовый код:

class Animal
{
protected:
    std::string m_name;
 
    // Мы делаем этот конструктор protected так как не хотим, чтобы пользователи имели возможность создавать объекты класса Animal напрямую,
    // но хотим, чтобы в дочерних классах доступ был открыт
    Animal(std::string name)
        : m_name(name)
    {
    }
 
public:
    std::string getName() { return m_name; }
    const char* speak() { return "???"; }
};
 
class Cat: public Animal
{
public:
    Cat(std::string name)
        : Animal(name)
    {
    }
 
    const char* speak() { return "Meow"; }
};
 
class Dog: public Animal
{
public:
    Dog(std::string name)
        : Animal(name)
    {
    }
 
    const char* speak() { return "Woof"; }
};
 
void report(Animal &animal)
{
    std::cout << animal.getName() << " says " << animal.speak() << '\n';
}
 
int main()
{
    Cat cat("Matros");
    Dog dog("Barsik");
 
    report(cat);
    report(dog);
}
