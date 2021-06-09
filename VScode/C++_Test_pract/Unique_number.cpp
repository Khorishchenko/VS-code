#include <iostream>
#include <iomanip>
#include <ratio>
#include <ctime>
#include <time.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

void f()
{
    cout << "hello" << endl;
}

#define Now high_resolution_clock::now
bool Out = false;

void FOld(int Arr[], int Size)
{
    int UniqueElement = -1;
    bool Unique = true;
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            if (Arr[i] == Arr[j] && j != i)
            {
                Unique = false;
                break;
            }
        }
        if (Unique)
        {
            UniqueElement = Arr[i];
            if (Out)
                cout << "Unique element: " << Arr[i] << endl;
        }
        Unique = true;
    }
}

void FNew(int Arr[], int Size)
{
    int UniqueElement = -1;
    int B[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < Size; i++)
        B[Arr[i]]++;
    for (int i = 0; i < Size; i++)
        if (B[i] == 1)
        {
            UniqueElement = i;
            if (Out)
                cout << "Unique element: " << i << endl;
        }
}


int main()
{
    srand(time(0));
    const int Size = 10;
    int Arr[Size];

    for (int i = 0; i < Size; i++)
        cout << (Arr[i] = rand() % 10) << setw(4);
    cout << endl;

    { // Old
        auto start = Now();
        for (int i = 0; i < 100000; i++)
            FOld(Arr, Size);

        cout << "Old time: " << ((duration<double>)(Now() - start)).count() << "s\n";
    }
    { // New
        auto start = Now();
        for (int i = 0; i < 100000; i++)
            FNew(Arr, Size);

        cout << "New time: " << ((duration<double>)(Now() - start)).count() << "s\n";
    }
    Out = true;
    cout << "Old\n";
    FNew(Arr, Size);
    cout << "New\n";
    FOld(Arr, Size);

  
  //  system("pause");
    return 0;
}