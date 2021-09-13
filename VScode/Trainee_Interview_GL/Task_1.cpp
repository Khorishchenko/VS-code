#include <iostream>


// A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product of two 3-digit numbers.

int f(int n, int k)
{
	if(k <= 0)
	{
		return -1;
		
	}
	int y = 0, c = 0, r = 0;
	while(n > 0)
	{
		y = y  * 10 + n % 10;
		n = n / 10;
		r++;


	}
    // std::cout << y << std::endl;
	if(k > r)
	{
		k = r;

	}
	for(int i = 0; i < k; i++)
	{
		c = c * 10 + y % 10;
		y = y / 10;
	}
	return c;

}

int f2(int n, int k)
{
	if(k <= 0)
	{
		return -1;
		
	}
	int y = 0, c = 0, r = 0;
	while(n > 0 && r < 3)
	{
        // std::cout << y << std::endl;
		y = y  * 10 + n % 10;
		n = n / 10;
		r++;
        // std::cout << y << std::endl;

	}
    // std::cout << c << std::endl;
    return y;
}

void polin(int number1, int number2){
  
	int result = number1 * number2;

    std::cout << result << std::endl;
   

    if (f(result, 3) == f2(result, 3)){
        std::cout << "palindrome" <<std::endl;
    }
    else
        std::cout << "No  palindrome" << std::endl;
  
}

int main()
{
    int num = 999;
    int num2 = 999;
    polin(num, num2);

    return 0;
}

