#include <iostream>
#include <iomanip> 
#include <cassert>

// Теперь попробуем что-то посложнее. Напишите класс, который реализует функционал стека. Класс Stack должен иметь:

//    закрытый целочисленный фиксированный массив длиной 10 элементов;

//    закрытое целочисленное значение для отслеживания длины стека;

//    открытый метод с именем reset(), который будет инициализировать значением 0 длину и все значения элементов;

//    открытый метод с именем push(), который будет добавлять значение в стек. Метод push() должен возвращать значение false, если массив уже заполнен, в противном случае — true;

//    открытый метод с именем pop() для возврата значений из стека. Если в стеке нет значений, то должен выводиться стейтмент assert;

//    открытый метод с именем print(), который будет выводить все значения стека.




// И это правильно! Так работают все массивы и контейнеры в STL.
// Затирание данных, это лишняя трата ресурсов процессора, потому как указатель на данную область вернется ТОЛЬКО в том случае когда будут добавляться данные. 
// А добавления данных в любом случае ПЕРЕЗАПИСЫВАЕТ содержимое ячейки. Так что любое удаление данных в контейнерах это просто смещение указателя, никто не затирает данные.
class Stack
{
    private:
        int m_arr[10];
        int size_stack;

    public:
        void reset(){
            size_stack = 0;
            for (int i = 0; i < 10; i++)
                m_arr[i] = 0;
        }

        bool push(int values){
            if(size_stack < 10){
                m_arr[size_stack++] = values;
                return true;
            }
            else
                return false;
        }

        int pop(){
            assert (size_stack > 0);
            // m_arr[size_stack--] = 0;    -- Wrong^ ERROR) - 

            return m_arr[--size_stack];
        }

        void print()
        {
            std::cout << '(';

            for (int i = 0; i < size_stack; i++)
                std::cout << std::setw(2) << m_arr[i];

            std::cout << ')' << std::endl;
        }
};

int main()
{
    Stack stack;
	stack.reset();
 
	stack.print();
 
	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();
 
	stack.pop();
	stack.print();
 
	stack.pop();
	stack.pop();
 
	stack.print();

    // stack.pop();     

    return 0;
}