#include <iostream>

//  Перегрузка оператора ()

// Но следует помнить о двух вещах:

//    Во-первых, перегрузка круглых скобок должна осуществляться через метод класса.

//    Во-вторых, в не объектно-ориентированном C++ оператор () является оператором вызова функции. 
//    В случае с классами перегрузка круглых скобок выполняется в методе operator()(){} (в объявлении функции перегрузки находятся две пары круглых скобок).

#include <iostream>
#include <cassert> // для assert()
 
class Matrix
{
private:
    double data[5][5];
public:
    Matrix()
    {
        // Присваиваем всем элементам массива значение 0.0
        for (int row=0; row < 5; ++row)
            for (int col=0; col < 5; ++col)
                data[row][col] = 0.0;
    }
 
    double& operator()(int row, int col);
    const double& operator()(int row, int col) const; // для константных объектов
};
 
double& Matrix::operator()(int row, int col)
{
    assert(col >= 0 && col < 5);
    assert(row >= 0 && row < 5);
 
    return data[row][col];
}
 
const double& Matrix::operator()(int row, int col) const
{
    assert(col >= 0 && col < 5);
    assert(row >= 0 && row < 5);
 
    return data[row][col];
}
 
int main()
{
    Matrix matrix;
    matrix(2, 3) = 3.6;
    std::cout << matrix(2, 3) << std::endl;
 
    return 0;
}