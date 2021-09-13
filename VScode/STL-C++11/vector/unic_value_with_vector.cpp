#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> 

const int g_arrayElements = 10000; // общее количество всех элементов массива
 
class Timer
{
private:
	// Псевдонимы типов используются для удобного доступа к вложенным типам
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;
 
	std::chrono::time_point<clock_t> m_beg;
 
public:
	Timer() : m_beg(clock_t::now())
	{
	}
 
	void reset()
	{
		m_beg = clock_t::now();
	}
 
	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};
 

void fun(std::vector<int> &array){
    int UniqueElement = -1;
    bool Unique = true;

    for (int i = 0; i < array.size(); i++)
    {
        for (int j = 0; j < array.size(); j++)
        {
            if (array[i] == array[j] && j != i)
            {
                Unique = false;
                break;
            }
        }
        if (Unique)
        {
            // UniqueElement = array[i];
                std::cout << "Unique element: " << array[i] << std::endl;
        }
        Unique = true;
    }
}

int main()
{

    std::vector<int> array{2,4,2,4,5,8,9,5,9};

    Timer t;

    fun(array);

    std::cout << "Time taken: " << t.elapsed() << '\n';

    Timer v;

    std::sort(array.begin(), array.end());
    fun(array);

    std::cout << "Time taken: " << v.elapsed() << '\n';

    return 0;

}