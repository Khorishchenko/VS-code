// Урок №144. Перегрузка оператора присваивания


#include <iostream>
 
class SomeString
{
private:
    char *m_data;
    int m_length;
 
public:
    SomeString(const char *data="", int length=0) :
        m_length(length)
    {
        if (!length)
            m_data = nullptr;
        else 
            m_data = new char[length];
 
        for (int i=0; i < length; ++i)
            m_data[i] = data[i];
    }
 
    
    SomeString& operator= (const SomeString &str);
 
    friend std::ostream& operator<<(std::ostream& out, const SomeString &s);
};
 
std::ostream& operator<<(std::ostream& out, const SomeString &s)
{
    out << s.m_data;
    return out;
}
 
// Перегрузка оператора присваивания (плохой вариант перегрузки)
SomeString& SomeString::operator= (const SomeString &str)
{
    // Если m_data уже имеет значение, то удаляем это значение
    if (m_data) delete[] m_data;
 
    m_length = str.m_length;
 
    // Копируем значение из str в m_data неявного объекта
    m_data = new char[str.m_length];
    for (int i=0; i < str.m_length; ++i)
        m_data[i] = str.m_data[i];
 
    // Возвращаем текущий объект
    return *this;
}
 
int main()
{
    SomeString anton("Anton", 7); 
    SomeString employee;
    employee = anton; 
    std::cout << employee;
 
    return 0;
}