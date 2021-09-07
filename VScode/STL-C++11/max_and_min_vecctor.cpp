#include <iostream>
#include <vector>
#include <algorithm> 
 
int main()
{
    std::vector<int> li;
    for (int nCount=0; nCount < 5; ++nCount)
        li.push_back(nCount);
 
    // std::vector<int>::const_iterator it; // объявляем итератор
    int it = *min_element(li.begin(), li.end());
        std::cout << it << ' ';
    int ait = *max_element(li.begin(), li.end());
        std::cout << ait << ' ';
	
    std::cout << '\n';
}