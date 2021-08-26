#include <iostream>

// Напишите класс, переменной-членом которого является строка. Перегрузите оператор () для возврата подстроки, которая начинается с индекса, 
// указанного в значении первого параметра. Второй параметр должен указывать требуемую длину подстроки.

// Подсказки:

//    Вы можете использовать индекс массива [] для доступа к отдельным символам строки.

//    Вы можете использовать оператор += для добавления чего-либо к строке.

// Следующий фрагмент кода:

// int main()
// {
//     Mystring string("Hello, world!");
//     std::cout << string(7, 6); // начинаем с 7 символа (индекса) и возвращаем следующие 6 символов
 
//     return 0;

// Должен выдавать следующий результат:

// world!


class Mystring
{
    private:
        std::string my_string;
        // std::string new_name;   

    public:

        Mystring(std::string name) : my_string(name){
            std::cout << my_string << std::endl;
        }

        // std::string& operator()(int index, int lenght); 

        // or

        std::string operator()(int index, int lenght);
};

// std::string& Mystring::operator()(int index, int lenght){
//     for (int i = 0; i < lenght; i++){
//         this->new_name += this->my_string[index++];
//     }
//     return this->new_name;
// }

// or

std::string Mystring::operator()(int index, int lenght){
    std::string ref;

    for (int i = 0; i  < lenght; i++)
        ref += this->my_string[index++];
    return ref;
}

int main()
{
    Mystring string("Hello, world!");
    std::cout << string(7, 6) << std::endl; // начинаем с 7 символа (индекса) и возвращаем следующие 6 символов
 
    return 0;
}