#include <iostream>
#include <string>

// a) Напишите класс Ball, который должен иметь следующие две закрытые переменные-члены со значениями по умолчанию:
//    m_color (Red);
//    m_radius (20.0).

// В классе Ball должны быть следующие конструкторы:
//    для установления значения только для m_color;
//    для установления значения только для m_radius;
//    для установления значений и для m_radius, и для m_color;
//    для установления значений, когда значения не предоставлены вообще.

// b) Теперь обновите ваш код из предыдущего задания с использованием конструкторов с параметрами по умолчанию. 
// Постарайтесь использовать как можно меньше конструкторов.

class Ball
{
    private:
        std::string m_color;
        double      m_radius;
    
    public:

        Ball(int radius){
            m_radius = radius;
            m_color = "Red";
        }

        Ball(const std::string &color = "red", int radius = 20.0) {
            m_color = color;
            m_radius = radius;
        }

        void print() {
            std::cout << "Color: " << m_color << ", radius: " << m_radius << std::endl;
        }

};

int main()
{
    Ball def;
    def.print();
 
	Ball black("black");
	black.print();
	
	Ball thirty(30.0);
	thirty.print();
	
	Ball blackThirty("black", 30.0);
	blackThirty.print();

    return 0;
}