#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Преобразовать строки двумерного массива в столбцы. Например было: 
// Класс будет содержать два метода: один заполнит массив значениями, 
// второй произведет замену значений строк на значения столбцов.


class mass
{
    private:
        int row;
        int col;
        int **ptrarray;
    public:
        void setInt(int row, int col)
        {
            this->row = row;
            this->col = col;
        }
        void setMas();
        void getmas();
        ~mass();
};

void mass::setMas()
{
    ptrarray = new int*[row];
    for (int i = 0; i < row; i++)
        ptrarray[i] = new int[col];

    for (int i = 0; i < row; i++){
        for(int k = 0; k < col; k++)
            cout << setw(4) << (ptrarray[i][k] = (int)rand() % 25 + 65);
        cout << endl;
    }
}

void mass::getmas()
{
    int **ptr = new int*[col];
    for (int i = 0; i < col; i++)
        ptr[i] = new int[row];

    for (int i = 0; i < col; i++){
        for (int k = 0; k < row; k++){
            ptr[i][k] = ptrarray[k][i];
        }
        cout << endl;
    }
    for(int i = 0; i < row; i++)
        delete[] ptrarray[i];
    delete [] ptrarray;

    ptrarray = new int*[col];
    for (int i = 0; i < col; i++)
        ptrarray[i] = new int[row];

    for(int i = 0; i < col; i++){
        for (int k = 0; k < row; k++){
            cout << setw(4) << (ptrarray[i][k] = ptr[i][k]);
        }
        cout << endl;
    }

     for(int i = 0; i < col; i++)
        delete[] ptr[i];
    delete [] ptr;
}

mass::~mass()
{
    for(int i = 0; i < col; i++)
        delete [] ptrarray[i];
    delete [] ptrarray;
    cout << "Destructor is start" << endl;
}

int main()
{
    mass Obj;
    int row, col;
    cout << "Enter row array2D and coll: " << endl, cin >> row >> col;

    Obj.setInt(row, col);
    Obj.setMas();

    cout << "new mass" << endl;

    Obj.getmas();
}