#include <iostream>
using namespace std;


struct functional_characteristics{
    int     Power;
    int     spin_speed; 
    float   heating_temp;
};

struct Ob_active_characteristics{
    string  Firm;
    string  color;
    int     width;
    int     length;
    int     height;
    functional_characteristics fun_char;
};

void Show(Ob_active_characteristics &Obj){
    cout << "Firma washing_mach is " << Obj.Firm << endl;
    cout << "Color washing_mach is " << Obj.color << endl;
    cout << "washing_mach.width: " << Obj.width << endl;
    cout << "washing_mach.length: " << Obj.length << endl;
    cout << "washing_mach.height: " << Obj.height << endl;
    cout << "washing_mach.fun_char.Power: " << Obj.fun_char.Power << endl;
    cout << "washing_mach.fun_char.spin_speed: " << Obj.fun_char.spin_speed << endl;
    cout << "washing_mach.fun_char.heating_temp: " << Obj.fun_char.heating_temp << endl;

}

int main()
{
    Ob_active_characteristics washing_mach = {};

    washing_mach.Firm = "Samsung";
    washing_mach.color = "Red";
    washing_mach.width = 40;
    washing_mach.length = 70;
    washing_mach.height = 90;
    washing_mach.fun_char.Power = 1400;
    washing_mach.fun_char.spin_speed = 700;
    washing_mach.fun_char.heating_temp = 76.7;

    Show(washing_mach);

    return 0;

}