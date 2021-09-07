#include <iostream>
#include <string>

// Указатели, Ссылки и Наследование

class Animal
{
protected:
    std::string m_name;
 
    // Мы делаем этот конструктор protected так как не хотим, чтобы пользователи создавали объекты класса Animal напрямую,
    // но хотим, чтобы у дочерних классов доступ был открыт
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
 
int main()
{
    Cat cat("Matros");
    std::cout << "cat is named " << cat.getName() << ", and it says " << cat.speak() << '\n';
 
    Dog dog("Barsik");
    std::cout << "dog is named " << dog.getName() << ", and it says " << dog.speak() << '\n';
 
    Animal *pAnimal = &cat;
    std::cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';
 
    pAnimal = &dog;
    std::cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';
 
    return 0;
}


// Мы видим здесь ту же проблему. Поскольку pAnimal является указателем типа Animal, то он может видеть только часть Animal. 
// Следовательно, pAnimal->speak() вызывает Animal::speak(), а не Dog::Speak() или Cat::speak().