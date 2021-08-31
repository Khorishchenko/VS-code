#include <iostream>

// Урок №159. Переопределение методов родительского класса

 
class Parent
{
protected:
    int m_value;
 
public:
    Parent(int value)
        : m_value(value)
    {
    }
 
    void identify() { std::cout << "I am a Parent!\n"; }
};
 
class Child : public Parent
{
public:
    Child(int value)
        : Parent(value)
    {
    }
};
 
// int main()
// {
//     Parent parent(6);
//     parent.identify();
 
//     Child child(8);
//     child.identify();
 
//     return 0;
// }


// Переопределение методов родительского класса



class Child_2 : public Parent
{
public:
    Child_2(int value)
        : Parent(value)
    {
    }
 
    int getValue() { return m_value; }
 
    // Вот наш изменяемый метод родительского класса
    void identify() { std::cout << "I am a Child_2!\n"; }
};

// int main()
// {
//     Parent parent(6);
//     parent.identify();
 
//     Child_2 child(8);
//     child.identify();
 
//     return 0;
// }



// Расширение функционала родительских методов


class Child_3 : public Parent
{
public:
    Child_3(int value)
        : Parent(value)
    {
    }
 
    int GetValue() { return m_value; }
 
    void identify()
    {
        Parent::identify(); // сначала выполняется вызов Parent::identify() 
        std::cout << "I am a Child_3!\n"; // затем уже вывод этого текста
    }
};

int main()
{
    Parent parent(6);
    parent.identify();
 
    Child_3 child(8);
    child.identify();
 
    return 0;
}


//  При выполнении child.identify() выполняется вызов Child::identify().
//  В Child::identify() мы сначала вызываем Parent::identify(), который выводит I am a Parent!. 
//  Когда Parent::identify() завершает свое выполнение, Child::identify() продолжает свое выполнение и выводит I am a Child!.

// без указания оператора разрешения области видимости привел бы к вызову identify() в текущем классе, т.е. Child::identify(). 
// Затем снова вызов Child::identify(), и ура — у нас получился бесконечный цикл.