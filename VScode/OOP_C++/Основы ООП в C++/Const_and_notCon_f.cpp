#include <iostream>
#include <string>


//константных и неконстантных функций

// Хотя это делается не очень часто, но функцию можно перегрузить таким образом, 
// чтобы иметь константную и неконстантную версии одной и той же функции:

// Константная версия функции будет вызываться для константных объектов, 
// а неконстантная версия будет вызываться для неконстантных объектов:

 
class Anything
{
private:
    std::string m_value;
 
public:
    Anything(const std::string &value="") { m_value = value; }
 
    const std::string& getValue() const { return m_value; } // getValue() для константных объектов
    std::string& getValue() { return m_value; } // getValue() для неконстантных объектов

	void print() {
		std::cout << this->m_value << std::endl;
	}

	void print () const {
		std::cout << this->m_value << std::endl;
	}
};

int main()
{
	Anything anything;
	anything.getValue() = "Hello!"; // вызывается неконстантный getValue()
	anything.print();
 
	const Anything anything2("hello");
	anything2.getValue(); 			// вызывается константный getValue()
	anything2.print();
 
	return 0;
}