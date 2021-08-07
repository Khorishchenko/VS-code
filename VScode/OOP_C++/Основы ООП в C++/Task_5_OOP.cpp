#include <iostream>
#include <cstdint>      // std::uint8_t

// Напишите класс с именем RGBA, который содержит 4 переменные-члены типа std::uint8_t (подключите заголовочный файл cstdint для доступа к типу std::uint8_t):
//    m_red;
//    m_green;
//    m_blue;
//    m_alpha.

// Присвойте 0 в качестве значения по умолчанию для m_red, m_green и m_blue, и 255 для m_alpha. 
// Создайте конструктор со списком инициализации членов, который позволит пользователю передавать значения для m_red,m_green, m_blue и m_alpha. 
// Напишите функцию print(), которая будет выводить значения переменных-членов.

class RGBA
{
    private:
        std::uint8_t m_red;
        std::uint8_t m_green;
        std::uint8_t m_blue;
        std::uint8_t m_alpha;
    
    public:
        RGBA(int red = 0, int green = 0, int blue = 0, int alpha = 255) 
            : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
        {

        }

        void print() {
            std::cout << "r = " << (int)m_red << " g = " << (int)m_green << " b = " << (int)m_blue << " a = " << (int)m_alpha << std::endl;

            std::cout << "r=" << static_cast<int>(m_red) <<     // Операция static_cast в языке C++ осуществляет явное допустимое приведение типа данных[1].
			" g=" << static_cast<int>(m_green) <<               // Синтаксис: static_cast < type_to > ( object_from )
			" b=" << static_cast<int>(m_blue) <<
			" a=" << static_cast<int>(m_alpha) << '\n';
        }
};

int main()
{
	RGBA color(0, 135, 135);
	color.print();
 
	return 0;
}