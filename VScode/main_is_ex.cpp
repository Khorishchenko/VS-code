#include <iostream>
using namespace std;
 
// https://youtu.be/guLK7Up6Kmc
// https://youtu.be/jCW2wRoRi0U



// int main()
// {
//     setlocale(LC_ALL, "rus");
    
//     int num1;
//     int num2;
    
//     int var = 3; // управляющая переменная для while
//     while (var != 0) 
//     {
//         cout << "Введите число num1: ";
//         cin >> num1;
//         cout << "Введите число num2: ";
//         cin >> num2;
        
//         cout << "num1 + num2 = " << num1 + num2 << endl;
//         cout << "num1 / num2 = " << num1 / num2 << endl;
//         cout << "num1 - num2 = " << num1 - num2 << endl;
//         cout << "=================================" << endl << endl;
        
//         var--;
//     }
    
//     cout << "Конец работы программы!" << endl << endl;
 
//  return 0;
// }







#include<iostream>
using namespace std;

int main()
{
setlocale(LC_ALL, "rus");
 
int num1;
int num2;
 
int var = 3;
while (var != 0)
{
 cout << "Введите число num1: ";
 cin >> num1;
 cout << "Введите число num2: ";
 cin >> num2;
 
 cout << "num1 + num2 = " << num1 + num2 << endl;
 cout << "num1 / num2 = ";
 
 try
 {
     /* code */
 }
 catch(const std::exception& e)
 {
     std::cerr << e.what() << '\n';
    
 }
 

 try // тут располагается код, который потенциально может вызвать ошибку 
 {
    if (num2 == 0) 
    {
        throw 999; // генерировать целое число 999
    }
    cout << num1 / num2 << endl;
 }
 
 catch (int thr)// сюда передастся число, которое сгенерировал throw 
 {
    cout << "Ошибка №" << thr << " - деление на 0!!!" << endl;
 }
 
 cout << "num1 - num2 = " << num1 - num2 << endl;
 cout << "=================================" << endl << endl;
 
 var--;
}
 
cout << "Программа завершила работу!" << endl << endl;
 
return 0;
}






//=============================================================//

    // try
    // {
    //     if (num2 == 0)
    //     {
    //         throw "Ошибка - деление на 0!!!!"; // генерируется строка
    //         cout << num1 / num2 << endl;   
    //     }
    // }
    // catch (const char *str) // строку перехватывает catch-блок
    // {
    //     cout << str << endl;
    // }





// //===============================================//
//     fun

// int delenie(int n1, int n2)
// {
//     if (n2 == 0)    
//     {
//         throw 99; 
//     }  
//     return n1 / n2;
// }

// try
// {
//  cout << delenie(7, 0);
//  cout << endl;
// }
// catch (int thr)
// {
//  cout << "Ошибка №" << thr << " Деление на 0!!!" << endl;
// }













