// Ключевое слово explicit

// Иногда выполнение неявных преобразований может иметь смысл, а иногда может быть крайне нежелательным и генерировать неожиданные результаты:


#include <iostream> 
#include <string>
 
class SomeString
{
private:
	std::string m_string;
public:
	// Ключевое слово explicit делает этот конструктор закрытым для выполнения любых неявных преобразований
	explicit SomeString(int a) // выделяем строку размером a
	{
		m_string.resize(a);
	}
 
	SomeString(const char *string) // выделяем строку для хранения значения типа string
	{
		m_string = string;
	}
 
	friend std::ostream& operator<<(std::ostream& out, const SomeString &s);
 
};
 
std::ostream& operator<<(std::ostream& out, const SomeString &s)
{
	out << s.m_string;
	return out;
}
 
int main()
{
	// SomeString mystring = 'a'; // ошибка компиляции, поскольку SomeString(int) теперь является explicit и, соответственно, недоступен, а другого 
                                // подходящего конструктора для преобразования компилятор не видит

    SomeString mystring_2 = "a"; // Vse Ok !!!!
	std::cout << mystring_2 << std::endl;
	return 0;
}


// Однако использование явного конструктора только предотвращает выполнение неявных преобразований. Явные конвертации (через операторы явного преобразования) по-прежнему разрешены:

// std::cout << static_cast<SomeString>(7); // разрешено: явное преобразование 7 в SomeString через оператор static_cast
// 1
// std::cout << static_cast<SomeString>(7); // разрешено: явное преобразование 7 в SomeString через оператор static_cast
// При прямой- или uniform-инициализации неявная конвертация также будет выполняться:

// SomeString str('a'); // разрешено
// 1
// SomeString str('a'); // разрешено
// Правило: Для предотвращения возникновения ошибок с неявными конвертациями делайте ваши конструкторы явными, используя ключевое слово explicit.