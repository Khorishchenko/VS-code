#include <iostream>

// Конструкторы и инициализация дочерних классов

// К счастью, язык C++ предоставляет нам возможность явно выбирать конструктор класса Parent для выполнения инициализации части Parent!

// Рассмотрим детально, что происходит:

//    Выделяется память для объекта child.

//    Вызывается конструктор Child(double, int), где value = 1.5, а id = 7.

//    Компилятор смотрит, запрашиваем ли мы какой-нибудь конкретный конструктор класса Parent. И видит, что запрашиваем! Поэтому вызывается Parent(int) с параметром id, которому мы до этого присвоили значение 7.

//    Список инициализации конструктора класса Parent присваивает для m_id значение 7.

//    Выполняется тело конструктора класса Parent, которое ничего не делает.

//    Завершается выполнения конструктора класса Parent.

//    Список инициализации конструктора класса Child присваивает для m_value значение 1.5.

//    Выполняется тело конструктора класса Child, которое ничего не делает.

//    Завершается выполнения конструктора класса Child.

class Parent
{
private: // наш m_id теперь закрытый
    int m_id;
 
public:
    Parent(int id=0)
        : m_id(id)
    {
    }
 
    int getId() const { return m_id; }
};
class Child: public Parent
{
private: // наш m_value теперь закрытый
    double m_value;
 
public:
    Child(double value=0.0, int id=0)
        : Parent(id), // вызывается конструктор Parent(int) со значением id!
            m_value(value)
    {
    }
 
    double getValue() const { return m_value; }
};
 
int main()
{
    Child child(1.5, 7); // вызывается конструктор Child(double, int)
    std::cout << "ID: " << child.getId() << '\n';
    std::cout << "Value: " << child.getValue() << '\n';
 
    return 0;
}



// Еще один пример



#include <string>
 
class Human
{
private:
    std::string m_name;
    int m_age;
 
public:
    Human(std::string name = "", int age = 0)
        : m_name(name), m_age(age )
    {
    }
 
    std::string getName() const { return m_name; }
    int getAge() const { return m_age; }
 
};
// BasketballPlayer открыто наследует класс Human
class BasketballPlayer: public Human
{
private:
    double m_gameAverage;
    int m_points;
 
public:
    BasketballPlayer(std::string name = "", int age = 0,
        double gameAverage = 0.0, int points = 0)
        : Human(name, age), // вызывается Human(std::string, int) для инициализации членов name и age
            m_gameAverage(gameAverage), m_points(points)
    {
    }
 
    double getGameAverage() const { return m_gameAverage; }
    int getPoints() const { return m_points; }
};


// Цепочки наследований

class A
{
public:
    A(int a)
    {
        std::cout << "A: " << a << '\n';
    }
};
 
class B: public A
{
public:
    B(int a, double b)
    : A(a)
    {
        std::cout << "B: " << b << '\n';
    }
};
 
class C: public B
{
public:
    C(int a , double b , char c)
    : B(a, b)
    {
        std::cout << "C: " << c << '\n';
    }
};
 
int main()
{
    C c(7, 5.4, 'D');
 
    return 0;
}


//    функция main() вызовет C(int, double, char);

//    конструктор класса C вызовет B(int, double);

//    конструктор класса B вызовет A(int);

//    поскольку A не наследует никакой класс, то построение начнется именно с этого класса;

//    построение A выполнено, выводится значение 7 и выполнение переходит в B;

//    класс B построен, выводится значение 5.4 и выполнение переходит в C;

//    класс C построен, выводится D и выполнение возвращается обратно в main();

//    Финиш!

// Таким образом, результат выполнения программы:

// A: 7
// B: 5.4
// C: D