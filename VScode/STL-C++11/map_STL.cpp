#include <iostream>
#include <string>
using namespace std;

#include <map>

// Команда разработчиков работавших над этим проектом:
// Михаил
// Тимофей

string MostRepeatingWord(string str)
{
    map<string, int> WordsCount;
    int Size = str.size();
    string Word = "";
    for (int i = 0; i < Size; i++)
    {
        if (str[i] != ' ')
            Word += str[i];
        else
        {
            if (Word.size() > 0)
                if (WordsCount.find(Word) == WordsCount.end())
                    WordsCount.insert(make_pair(Word, 1));
                else
                    WordsCount[Word]++;
            Word = "";
        }
    }
    string MaxWord;
    int MaxSize = 0;
    for (pair<string, int> Elem : WordsCount)
        if (Elem.second > MaxSize)
        {
            MaxWord = Elem.first;
            MaxSize = Elem.second;
        }
    return MaxWord;
}

int main()
{
    string str;
    cout << "Text\n> ";
    getline(cin, str);
    str = str + " ";
    cout << "Most repeating word: " << MostRepeatingWord(str);
}