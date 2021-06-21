#include "object.h"
int main()
{
    O Text = Input(L"Текст: ");
    O NewText = L"";
    for (O i = 0; i < Len(Text); i++)
    {
        O Symbol = Text[i];
        if (Symbol == L".")
            NewText += L"!";
        else
            NewText += Symbol;
    }
    Log(O(L"Новый текст: ") + NewText);
}