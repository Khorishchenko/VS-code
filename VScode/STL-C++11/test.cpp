#include <iostream>
#include <string>

#define value(value_1, value_2) value_1 * value_2;

template <typename T>
void sum(T &array)
{      
    std::cout << sizeof(T) << ' ' << sizeof(int) << std::endl;
        if (sizeof(T) != sizeof(int)){
            for (int i = 0; i < sizeof(array)/sizeof(int); i++){
                std::cout << array[i] << std::endl;
            }
        }
        else if (sizeof(std::string) == sizeof(T)){
            for (int i = 0; i < sizeof(array); i++){
                std::cout << array[i] << std::endl;
            }
        }
 
}

int main()
{
   int array[]{1,2,3,4,56,7,8};

   std::string array_2("hello world;");
   

   sum(array);

   sum(array_2);

    return 0;

}