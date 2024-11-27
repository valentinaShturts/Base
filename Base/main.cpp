#include "Base.h"
#include "Vehicles.h"
#include <iostream>

using namespace std;

int Base::people_on_base = 0;      
int Base::vehicles_on_base = 0;    
double Base::petrol_on_base = 500.0; 
double Base::goods_on_base = 0;

int main()
{
	Base base;
	base.ShowBaseStatus();
    cout << endl;

    Bus bus1(0, 20, 50, 120);
    bus1.arrive();
    base.ShowBaseStatus();
    cout << endl;

    Bus bus2(0, 20, 100, 120);
    bus2.arrive();
    base.ShowBaseStatus();
    cout << endl;

    bus1.leave();
    base.ShowBaseStatus();
    cout << endl;

    Truck truck1(20, 100, 10, 200);
    truck1.arrive();
    base.ShowBaseStatus();
    cout << endl;

    bus2.leave();
    base.ShowBaseStatus();
    cout << endl;

    truck1.leave();
    base.ShowBaseStatus();
    cout << endl;

}