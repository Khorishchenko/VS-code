#include <iostream>
#include <vector>
 
// Если для инициализации вашей статической переменной-члена требуется выполнить код (например, цикл), 
// то есть несколько разных способов это сделать. 
// Следующий способ является лучшим из них:


class Something
{
private:
	static std::vector<char> s_mychars;
 
public:
	class _nested // определяем вложенный класс с именем _nested
	{
	public:
		_nested() // конструктор _nested() инициализирует нашу статическую переменную-член
		{
			s_mychars.push_back('o');
			s_mychars.push_back('a');
			s_mychars.push_back('u');
			s_mychars.push_back('i');
			s_mychars.push_back('e');
		}
	};
 
	// Статический метод для вывода s_mychars
	static void getSomething() {
		for (auto const &element : s_mychars)
			std::cout << element << ' ';
        std::cout << std::endl;
	}
private:
	static _nested s_initializer; // используем статический объект класса _nested для гарантии того, что конструктор _nested() выполнится
};
 
std::vector<char> Something::s_mychars; // определяем нашу статическую переменную-член
Something::_nested Something::s_initializer; // определяем наш статический s_initializer, который вызовет конструктор _nested() для инициализации s_mychars
 
int main() {
	Something::getSomething();
	return 0;
}