#include <iostream> 
struct visual { char const* firm; char const* color; float length; float longer; float high; };
struct robot { float power; float speed; float temp; };struct characteristics {visual viisual;robot roobot;}Washer;
int main() {Washer = { {" SAMSUNG ", " Grey ",65.7,53.6,89} , 0.86, 1200, 60.8};std::cout << Washer.viisual.firm << " = Washer firm  "<<Washer.viisual.color
<< " = Washer color "<< Washer.viisual.length<<" = Washer length "<< Washer.viisual.longer<<" = Washer long "<<Washer.viisual.high<<" = Washer high "
<<Washer.roobot.power<<" = Washer power "<<Washer.roobot.speed<<" = Washer speed"<<Washer.roobot.temp<< " = Washer temperature";}