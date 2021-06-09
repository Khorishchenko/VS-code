#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <math.h>
#include <list>
using namespace std;

#define BOOL_TYPE 1
#define INT_TYPE 2
#define FLOAT_TYPE 3
#define STRING_TYPE 4

class O
{
public:
    short int Type = 1;
    // All possible types
    bool Bool;
    long Int;
    double Num;
    wstring Str;
    // All possible types

    // Starts
    O(int Integer)
    {
        Type = INT_TYPE;
        Int = Integer;
    }
    O(long Long)
    {
        Type = INT_TYPE;
        Int = Long;
    }
    O(size_t Long)
    {
        Type = INT_TYPE;
        Int = Long;
    }
    O(double Float)
    {
        Type = FLOAT_TYPE;
        Num = Float;
    }
    O(bool Boolean)
    {
        Type = BOOL_TYPE;
        Bool = Boolean;
    }
    O(const wchar_t *String)
    {
        Type = STRING_TYPE;
        Str = wstring(String);
    }
    O(wstring String)
    {
        Type = STRING_TYPE;
        Str = String;
    }
    // Starts

    // Conversions
    O ToString()
    {
        switch (Type)
        {
        case INT_TYPE:
            return O(to_wstring(Int));
            break;
        case FLOAT_TYPE:
            return O(to_wstring(Num));
            break;
        case BOOL_TYPE:
            return O(Bool ? L"True" : L"False");
            break;
        case STRING_TYPE:
            return Clone();
            break;
        default:
            return O(L"NaN");
            break;
        }
    }
    O ToInt()
    {
        switch (Type)
        {
        case INT_TYPE:
            return Clone();
            break;
        case FLOAT_TYPE:
            return O((int)Num);
            break;
        case BOOL_TYPE:
            return O((int)Bool);
            break;
        case STRING_TYPE:
            return O(stol(Str));
            break;
        default:
            return O(0);
            break;
        }
    }
    O ToFloat()
    {
        switch (Type)
        {
        case INT_TYPE:
            return O((double)Int);
            break;
        case FLOAT_TYPE:
            return Clone();
            break;
        case BOOL_TYPE:
            return O((double)Bool);
            break;
        case STRING_TYPE:
            return O(stod(Str));
            break;
        default:
            return O(0.0);
            break;
        }
    }
    O ToBoolean()
    {
        switch (Type)
        {
        case INT_TYPE:
            return (bool)Int;
            break;
        case FLOAT_TYPE:
            return (bool)Num;
            break;
        case BOOL_TYPE:
            return Clone();
            break;
        case STRING_TYPE:
            return O(Str.compare(L"True") == 0 ? true : false);
            break;
        default:
            return O(false);
            break;
        }
    }
    // Conversions

    O operator+(O b)
    {
        short TypeTo = max(Type, b.Type);
        switch (TypeTo)
        {
        case INT_TYPE:
            return O(Int + b.Int);
            break;
        case FLOAT_TYPE:
            return O(ToFloat().Num + b.ToFloat().Num);
            break;
        case BOOL_TYPE:
            return O(ToInt().Str + b.ToInt().Str);
            break;
        case STRING_TYPE:
            return O(ToString().Str + b.ToString().Str);
            break;
        default:
            return O(0);
            break;
        }
    }
    bool operator<(O b)
    {
        short TypeTo = max(Type, b.Type);
        switch (TypeTo)
        {
        case INT_TYPE:
            return Int < b.Int;
            break;
        case FLOAT_TYPE:
            return ToFloat().Num < b.ToFloat().Num;
            break;
        case BOOL_TYPE:
            return ToInt().Str < b.ToInt().Str;
            break;
        case STRING_TYPE:
            return ToFloat().Str < b.ToFloat().Str;
            break;
        default:
            return 0;
            break;
        }
    }
    bool operator>(O b)
    {
        short TypeTo = max(Type, b.Type);
        switch (TypeTo)
        {
        case INT_TYPE:
            return Int > b.Int;
            break;
        case FLOAT_TYPE:
            return ToFloat().Num > b.ToFloat().Num;
            break;
        case BOOL_TYPE:
            return ToInt().Str > b.ToInt().Str;
            break;
        case STRING_TYPE:
            return ToFloat().Str > b.ToFloat().Str;
            break;
        default:
            return false;
            break;
        }
    }
    O operator==(O b)
    {
        short TypeTo = max(Type, b.Type);
        switch (TypeTo)
        {
        case INT_TYPE:
            return O(Int == b.Int);
            break;
        case FLOAT_TYPE:
            return O(Num == b.Num);
            break;
        case BOOL_TYPE:
            return O(Bool == b.Bool);
            break;
        case STRING_TYPE:
            return O(Str == b.Str);
            break;
        default:
            return O(false);
            break;
        }
    }
    operator bool()
    {
        return ToBoolean().Bool;
    }
    O operator!=(O b)
    {
        short TypeTo = max(Type, b.Type);
        switch (TypeTo)
        {
        case INT_TYPE:
            return O(Int != b.Int);
            break;
        case FLOAT_TYPE:
            return O(Num != b.Num);
            break;
        case BOOL_TYPE:
            return O(Bool != b.Bool);
            break;
        case STRING_TYPE:
            return O(Str != b.Str);
            break;
        default:
            return O(false);
            break;
        }
    }
    void operator+=(O b)
    {
        short TypeTo = max(Type, b.Type);
        switch (TypeTo)
        {
        case INT_TYPE:
            Int += b.Int;
            break;
        case FLOAT_TYPE:
            Num += b.Num;
            break;
        case STRING_TYPE:
            Str += b.Str;
            break;
        default:
            break;
        }
    }
    void operator++(int i)
    {
        switch (Type)
        {
        case INT_TYPE:
            Int++;
            break;
        case FLOAT_TYPE:
            Num++;
            break;
        default:
            break;
        }
    }
    O operator-(O b)
    {
        short TypeTo = max(Type, b.Type);
        switch (TypeTo)
        {
        case INT_TYPE:
            return O(Int - b.Int);
            break;
        case FLOAT_TYPE:
            return O(ToFloat().Num - b.ToFloat().Num);
            break;
        case STRING_TYPE:
            return O(0);
            break;
        default:
            return O(0);
            break;
        }
    }
    O operator/(O b)
    {
        short TypeTo = max(Type, b.Type);
        switch (TypeTo)
        {
        case INT_TYPE:
            return O(Int / b.Int);
            break;
        case FLOAT_TYPE:
            return O(ToFloat().Num / b.ToFloat().Num);
            break;
        case STRING_TYPE:
            return O(0);
            break;
        default:
            return O(0);
            break;
        }
    }
    O operator*(O b)
    {
        short TypeTo = max(Type, b.Type);
        switch (TypeTo)
        {
        case INT_TYPE:
            return O(Int * b.Int);
            break;
        case FLOAT_TYPE:
            return O(ToFloat().Num * b.ToFloat().Num);
            break;
        case BOOL_TYPE:
            return O(ToInt() * b.ToInt());
            break;
        case STRING_TYPE:
            return O(0);
            break;
        default:
            return O(0);
            break;
        }
    }
    O operator^(O b)
    {
        short TypeTo = max(Type, b.Type);
        switch (TypeTo)
        {
        case INT_TYPE:
            return O(pow(Int, b.Int));
            break;
        case FLOAT_TYPE:
            return O(pow(ToFloat().Num, b.ToFloat().Num));
            break;
        case STRING_TYPE:
            return O(0);
            break;
        default:
            return O(0);
            break;
        }
    }
    O operator&&(O b)
    {
        short TypeTo = max(Type, b.Type);
        switch (TypeTo)
        {
        case BOOL_TYPE:
            return O(ToBoolean().Bool && b.ToBoolean().Bool);
            break;
        default:
            return O(0);
            break;
        }
    }
    O Length()
    {
        if (Type == STRING_TYPE)
            return O(Str.length());
        return O(0);
    }
    O Find(O o)
    {
        if (Type == STRING_TYPE)
            return O(Str.find(o.ToString().Str));
        return O(0);
    }
    O operator[](O b)
    {
        if (b.Type == INT_TYPE)
        {
            wstring a;
            a += Str[b.Int];
            return O(a);
        }
        return O(0);
    }

    O Clone()
    {
        switch (Type)
        {
        case INT_TYPE:
            return O(Int);
            break;
        case FLOAT_TYPE:
            return O(Num);
            break;
        case BOOL_TYPE:
            return O(Bool);
            break;
        case STRING_TYPE:
            return O(Str);
            break;
        default:
            return O(0);
            break;
        }
    }
};
O Str(O o)
{
    return o.ToString();
}
O Int(O o)
{
    return o.ToInt();
}
O Float(O o)
{
    return o.ToFloat();
}
O Len(O o)
{
    return o.Length();
}
O Bool(O o)
{
    return o.ToBoolean();
}

void LogOldLine(O o)
{
    setlocale(LC_ALL, "");
    wcout << Str(o).Str;
}
void Log(O o)
{
    setlocale(LC_ALL, "");
    wcout << Str(o).Str << "\n";
}
O Input(O o)
{
    LogOldLine(o);
    O Result(L"");
    getline(wcin, Result.Str); 
    return Result;
}

#endif