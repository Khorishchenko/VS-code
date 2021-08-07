#include <iostream>
 
class Humidity;
 
class Temperature
{
private:
    int m_temp;
public:
    Temperature(int temp=0) { m_temp = temp; }
 
    friend void outWeather(const Temperature &temperature, const Humidity &humidity);
};
 
class Humidity
{
private:
    int m_humidity;
public:
    Humidity(int humidity=0) { m_humidity = humidity; }
 
    friend void outWeather(const Temperature &temperature, const Humidity &humidity);
};
 
void outWeather(const Temperature &temperature, const Humidity &humidity)
{
    std::cout << "The temperature is " << temperature.m_temp <<
       " and the humidity is " << humidity.m_humidity << '\n';
}
 
int main()
{
    Temperature temp(15);
    Humidity hum(11);
 
    outWeather(temp, hum);
 
    return 0;
}