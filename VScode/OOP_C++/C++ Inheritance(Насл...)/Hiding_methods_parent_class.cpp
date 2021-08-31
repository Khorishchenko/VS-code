#include <iostream>

// Скрытие методов родительского класса


class Parent
{
private:
    int m_value;
 
public:
    Parent(int value)
        : m_value(value)
    {
    }
 
protected:
    void printValue() { std::cout << m_value << std::endl; }
};

class Child: public Parent
{
public:
    Child(int value)
        : Parent(value)
    {
    }
 
    // Parent::printValue является protected, поэтому доступ к нему не является открытым для всех объектов.
    // Но мы можем это исправить с помощью "using-объявления"
    using Parent::printValue; // обратите внимание, нет никаких скобок
};

int main()
{
    Child child(9);
 
    // Метод printValue() является public в классе Child, поэтому всё хорошо
    child.printValue(); // выведется 9
    return 0;
}


// Сокрытие родительских методов в дочернем классе


class Parent_2
{
public:
	int m_value;
};
 
class Child_2 : public Parent_2
{
private:
	using Parent_2::m_value;
 
public:
	Child_2(int value)
	// Мы не можем инициализировать m_value, поскольку это член класса Parent (Parent должен инициализировать m_value)
	{
		// Но мы можем присвоить значение
		m_value = value;
	}
};
 
int main()
{
	Child_2 child(9);
 
	// Следующее не сработает, поскольку m_value был переопределен как private
	std::cout << child.m_value;
 
	return 0;
}


// Вы также можете закрыть родительские методы в дочернем классе, используя ключевое слово delete:

class Parent_3
{
private:
	int m_value;
 
public:
	Parent_3(int value)
		: m_value(value)
	{
	}
 
	int getValue() { return m_value; }
};
 
class Child_3 : public Parent_3
{
public:
	Child_3(int value)
		: Parent_3(value)
	{
	}
 
 
	int getValue() = delete; // делаем этот метод недоступным
};
 
int main()
{
	Child_3 child(9);
 
	// Следующее не сработает, поскольку getValue() удален
	std::cout << child.getValue();     // error
    child.Parent_3::getValue();        // this is good 
 
	return 0;
}
