#include <iostream>
#include <cassert>

// Задание №3
// Напишите свой собственный класс-массив целых чисел IntArray (не используйте std::array или std::vector). 
// Пользователи должны передавать размер массива при создании объекта этого класса, а сам массив (переменная-член) должен выделяться динамически. 
// Используйте стейтменты assert для проверки передаваемых значений, а также свой конструктор копирования и перегрузку оператора присваивания, 
// если это необходимо, чтобы следующий код:


class IntArray
{
    private:
        int *array;
        int size;
    public:
        IntArray(int size) : size(size), array(nullptr)
        {
            assert(size != 0);

            this->array = new int[this->size]{0};
        }

        IntArray(const IntArray &array) : size(array.size)
	    {
            // Выделяем новый массив
            this->array = new int[size];
    
            // Копируем элементы из исходного массива в наш только что выделенный массив
            for (int count = 0; count < array.size; ++count)
                this->array[count] = array.array[count];
	    }

        ~IntArray(){
            delete [] array;
            array = nullptr;
        }

        int& operator[] (const int index);
        IntArray& operator= (const IntArray &intarray);
        friend std::ostream& operator<< (std::ostream &out, const IntArray &intarray);

};

int& IntArray::operator[] (const int index){
    assert(index >= 0);
	assert(index < size);
    return array[index];
}

IntArray& IntArray::operator= (const IntArray &intarray){
    // Проверка на самоприсваивание
    if (this == &intarray)
        return *this;

    if (array) delete [] array;

    size = intarray.size;

    array = new int[intarray.size];
    for (int i = 0; i < intarray.size; i++)
        array[i] = intarray.array[i];

    return *this;

}

std::ostream& operator<< (std::ostream &out, const IntArray &intarray){
    for (int i = 0; i < intarray.size; i++){
        out << intarray.array[i] << ' ';
    }
    return out;
}



IntArray fillArray()
{
	IntArray a(6);
	a[0] = 6;
	a[1] = 7;
	a[2] = 3;
	a[3] = 4;
	a[4] = 5;
    a[5] = 8;
 
	return a;
}
 
int main()
{
	IntArray a = fillArray();
	std::cout << a << '\n';
 
	IntArray b(1);
	a = a;
	b = a;
 
	std::cout << b << '\n';
 
	return 0;
}