#include <iostream>

class MyClass
{
    private:
        int *data;
        int Size;
    public:

        MyClass(int size) : Size(size)
        {
            this->data = new int[Size];

            for (int i = 0; i < Size; i++)
            {
                this->data[i] = i + 1;
            }

            std::cout << " Constructor " << this << std::endl;
        }

        MyClass(const MyClass &other)                               // Конструктор копирования
        {
            this->Size = other.Size;

            this->data = new int[this->Size];

            for (int i = 0; i < this->Size; i++) {
                this->data[i] = other.data[i];
            }
            std::cout << "Constructor copy " << this << std::endl;
        }

        ~MyClass()
        {
            std::cout << " Destructor " << this << std::endl;
            delete [] data;
        }

};

int main()
{
    MyClass array(10);

    MyClass array2(array);          // Конструктор копирования
}