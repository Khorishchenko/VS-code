#include <iostream>

// Функции доступа обычно бывают двух типов:

//    геттеры — это функции, которые возвращают значения закрытых переменных-членов класса;

//    сеттеры — это функции, которые позволяют присваивать значения закрытым переменным-членам класса.

// Правило: Предоставляйте функции доступа только в том случае, когда нужно, 
// чтобы пользователь имел возможность получать или присваивать значения членам класса.

// Правило: Геттеры должны использовать тип возврата по значению или по константной ссылке. 
// Не используйте для геттеров тип возврата по неконстантной ссылке.

class Values
{   
    private:
        int m_data;
        int m_year;

    public:

        int get_data(){
            return m_data;
        }
        void set_data(int data){
            m_data = data;
        }

        int get_year(){
            return m_year;
        }

        void set_year(int year){
            m_year = year;
        }
};

int main()
{
    Values point1;
    point1.set_data(28);
    point1.set_year(1996);

    std::cout << point1.get_data() << std::endl;
    std::cout << point1.get_year() << std::endl;

    return 0;
}