#include <iostream>
#include <bitset>
int main()
{
    int a = 0x10;
    std::cout << std::bitset<8>(a) << ": " << a << '\n';
}