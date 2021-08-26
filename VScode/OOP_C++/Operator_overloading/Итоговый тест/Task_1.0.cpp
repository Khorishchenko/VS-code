#include <iostream>
#include <cstdint>


// Задание №2
// Напишите класс Average, который будет вычислять среднее значение всех передаваемых ему целых чисел. 
// Используйте два члена: первый должен быть типа int32_t и использоваться для вычисления суммы всех передаваемых чисел, 
// второй должен быть типа int8_t и использоваться для вычисления количества передаваемых чисел. 
// Чтобы найти среднее значение, нужно разделить сумму на количество.

class Average
{
    private:
        std::int32_t sum_values;
        std::int8_t  number_values;
    public:
        Average() : number_values(0), sum_values(0){}

        // friend void operator+= (Average &average, const int value);                  // I wrote this
        friend std::ostream& operator<< (std::ostream &out, const Average &average);

    // Поскольку operator+=() изменяет свой левый операнд, то перегрузку следует выполнять через метод класса
	Average& operator+=(int num);
};

std::ostream& operator<< (std::ostream &out, const Average &average){
    out << average.sum_values/average.number_values;
    return out;
}

Average& Average::operator+=(int num){
    sum_values += num;
    ++number_values;

		// Возвращаем текущий объект, чтобы иметь возможность выполнять цепочку операций с +=
    return *this;       
}

  // I wrote this

// void operator+= (Average &average, const int value){
//     average.sum_values += value;
//     average.number_values++;
// }

int main()
{
	Average avg;
	
	avg += 5;
	std::cout << avg << '\n'; // 5 / 1 = 5
	
	avg += 9;
	std::cout << avg << '\n'; // (5 + 9) / 2 = 7
 
	avg += 19;
	std::cout << avg << '\n'; // (5 + 9 + 19) / 3 = 11
 
	avg += -9;
	std::cout << avg << '\n'; // (5 + 9 + 19 - 9) / 4 = 6
 
	(avg += 7) += 11; // выполнение цепочки операций
	std::cout << avg << '\n'; // (5 + 9 + 19 - 9 + 7 + 11) / 6 = 7
 
	Average copy = avg;
	std::cout << copy << '\n';
 
	return 0;
}