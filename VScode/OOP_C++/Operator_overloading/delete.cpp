// Ключевое слово delete

#include <iostream> 
#include <string>
 
class SomeString
{
private:
	std::string m_string;
 
public:
	SomeString(char) = delete; // любое использование этого конструктора приведет к ошибке
 
	// Ключевое слово explicit делает этот конструктор закрытым для выполнения любых неявных конвертаций
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
	// SomeString mystring('a'); // ошибка компиляции, поскольку SomeString(char) удален
    SomeString mystring_2("a");
	std::cout << mystring_2 << std::endl;
	return 0;
}