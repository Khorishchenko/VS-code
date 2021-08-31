#include <iostream>
#include <string>

// Тест

// Реализуем наш пример с Фруктом, о котором мы говорили на уроке №153. Создайте родительский класс Fruit,
//  который имеет два закрытых члена: name (std::string) и color (std::string). Создайте класс Apple, который наследует свойства Fruit. 
//  У Apple должен быть дополнительный закрытый член: fiber (тип double). 
// Создайте класс Banana, который также наследует класс Fruit. Banana не имеет дополнительных членов.


class Fruit
{
    private:
        std::string name;
        std::string color;
    public:
        Fruit(std::string name = "", std::string color = "") :
            name(name), color(color)
            {

            }
        std::string getName() const {return name;}
        std::string getColor()const {return color;}
        
};

class Apple : public Fruit
{
    private:
        double fiber;
    public:
        Apple(std::string name, std::string color, double fib)
           : Fruit(name, color), fiber(fib)
           {

           }
        friend std::ostream& operator<< (std::ostream &out, const Apple &apple);
};

std::ostream& operator<< (std::ostream &out, const Apple &apple){
    out << "Apple("apple.fiber << ',' << apple.getColor() << ' ' << apple.getName() << std::endl;
    return out;
}

class Banana : public Fruit
{
    public:
        Banana(std::string name, std::string color)
            : Fruit(name, color)
            {

            }
        friend std::ostream& operator<<(std::ostream &out, const Banana &banana){
            out << banana.getColor() << banana.getName() << std::endl;
            return out;
        }
};


int main()
{
    Fruit f("Apple", "red");
    std::cout << f.getColor() << ' ' << f.getName() << std::endl;

	const Apple a("Red delicious", "red", 7.3);
	std::cout << a;
 
	const Banana b("Cavendish", "yellow");
	std::cout << b;
 
	return 0;
}

// Должен выдавать следующий результат:

// Apple(Red delicious, red, 7.3)
// Banana(Cavendish, yellow)