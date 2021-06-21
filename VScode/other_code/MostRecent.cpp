#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

void MostRecent(char* str, char* word);

int main() {
  char str[1000] = "hello ben how are ben";
//   cin.getline(str, 1000);

  //=Починається функція=//
  int i = 0, COUNT = 0;
  while (str[i] != '\0') {
    if (str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122)
      if (str[i + 1] < 65 || str[i + 1]>90 && str[i + 1] < 97 || str[i + 1]>122)
        COUNT++;
    i++;
  }
  
  //Знаходимо кількість слів у тексті, тут проблем немає
  cout << COUNT<< endl;//Перевірка кількості слів
  char** words = new char* [COUNT];
  for (i = 0; i < COUNT; i++)
    words[i] = new char[20];//Створюємо двовимірний динамічний масив

  i = 0;
  int j = 0, c = 0;
  while (str[i] != '\0') {
    if (str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122) 
	{
      words[j][c++] = (str[i] >= 97) ? str[i] - 32 : str[i];
      if (str[i + 1] < 65 || str[i + 1]>90 && str[i + 1] < 97 || str[i + 1]>122){
        j++;
        c = 0;
      }
    }
    i++;
  }
  //Цей цикл має розфасувати всі слова з тексту в масив і робити всі букви великими
  //І він це робить але після слів додається сміття якого немало б бути
  for (i = 0; i < COUNT; i++)
  {
    j = 0;
    while (words[i][j] != '\0')
      cout << words[i][j++];
    cout << endl;
  }
  //Перевірка масиву
  return 0;
}

//Функцію з основного тіла я потім перенесу і навіть зі сміттям я знаю як я міг би виконати завдання але без нього все буде набагато гарніше
void MostRecent(char* str, char* word) {
  //Тут буде функція
}