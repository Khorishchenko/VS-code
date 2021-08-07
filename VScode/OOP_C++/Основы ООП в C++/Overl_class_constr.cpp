#include <iostream>
#include <string>

class Tinan
{
    public:
        std::string m_name;
        int m_data;
    void print() {
        std::cout << m_name << '|' << m_data << std::endl;
    }
};

int main()
{
    Tinan MyName{"Sergey", 100};
    MyName.print();
    return 0;
}