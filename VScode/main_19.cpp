#include <iostream>
using namespace std;


// 5. Операторы выделения памяти new и delete


// указатель_на_тип_= new имя_типа (инициализатор)

int main()
{
    
    int *ptr = new int; // int x;
    
    // При выделении памяти объект можно инициализировать:
    int *ip = new int(3); // int x = 42;

    int *other = ptr;

    *ptr = 78;
    cout << *ptr;


    int *const ptr = new int;
    int i = 0;
    ptr = &i;

    
    //3
    cout << *ip;


    // Вторая форма new используется для динамического выделения памяти под массив:

    int size = 0;
    cout << "Enter please size array: ";
    cin >> size;

    double *mas = new double[size]; // int arr[size];


    // Далее с этой динамически выделенной памятью можно работать, как с обычным массивом:


     srand(time(NULL));
     int size;
     int* dar = nullptr;
    
     // запрос размера массива с клавиатуры
     cout<<"Enter size:\n";
     cin >> size;
    
     /* выделение памяти под массив с количеством
     элементов size
      */
     dar = new int[size];
    
     // заполнение массива и показ на экран
     for (int i = 0; i < size; i++)
         cout << (dar[i] = rand() % 100) << ' ';
    cout << "\n\n";
  




    //=====================================================//




    // Операция освобождения памяти delete


    // Удаляет динамический объект типа int
        // если было ip = new int;
 delete ip;

 /* удаляет динамический массив длиной 50, если было
    double *mas = new double[50]; */
 delete [] mas;


    // В наш, вышеописанный пример, мы теперь можем добавить освобождение памяти.

  
    int size = 0;
     //    запрос размера массива с клавиатуры
     cout<<"Enter size:\n";
     cin >> size;
    
     /* выделение памяти под массив с количеством
      элементов size
      */
     int *dar = new int[size];
    
     // заполнение массива и показ на экран
     for (int i = 0; i < size; i++)
     {
         *(dar + i) = rand() % 100;
         cout << dar[i] << "\t";
     }
     cout << "\n\n";
     delete[] dar;
    
     return 0;
}



//=====================================================//


// 4. Ссылки в качестве результатов функций
    
    
    
int & rf(int index); // Прототип функции.
int a[10][2];

int main ()
 {
     int b;
     cout << "Fill array.\n";
     for (int i = 0; i < 10; i++)
     {
         cout << i + 1 << " element:";
         cin >> b;
         a[i][0] = b;
         rf(i) = b;
     }
     cout << "Show array.\n";
     cout << "1-st column 2-nd column" << "\n";
     for (int i=0; i<10; i++)
            cout << a[i][0] << "\t\t" << rf(i) << "\n";
     return 0;
}

int &rf(int index)
{
    return a[index][1]; // Возврат ссылки на элемент
}
 
 

 //===================================================================//



// // Функция определяет ссылку на элемент
// // массива с максимальным значением.
// int& rmax(int n, int d[])
// {
//      int im = 0;
//      for (int i = 1; i < n; i++)
//          im = d[im] > d[i] ? im : i;
//      return d[im];
// }

// int main ()
// {
//      int x[]={10, 20, 30, 14};
//      int n = 4;
//      cout << "\nrmax(n,x) = " << rmax(n,x)
//      cout << "\n";
     
//      // заменяем максимум на ноль
//      rmax(n,x) = 0;
//      for (int i = 0; i < n; i++)
//          cout << "x[" << i << "]=" << x[i] << " ";
//      cout << "\n";
//      return 0;
     
// }




//=====================================================//



