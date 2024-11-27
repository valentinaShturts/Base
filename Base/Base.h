#pragma once
#include <iostream>
using namespace std;

class Base
{
private:
	static int people_on_base; 
    static int vehicles_on_base;
    static double petrol_on_base;
    static double goods_on_base;
public:
    static int GetPeopleOnBase() { return people_on_base; }
    static void SetPeopleOnBase(int people) 
    {
        if (people >= 0) people_on_base = people;
        else 
        {
            people_on_base = 0;
        }
    }

    static int GetVehiclesOnBase() { return vehicles_on_base; }
    static void SetVehiclesOnBase(int vehicles) 
    {
        if (vehicles >= 0) vehicles_on_base = vehicles;
        else 
        {
            vehicles_on_base = 0;
        }
    }

    static double GetPetrolOnBase() { return petrol_on_base; }
    static void SetPetrolOnBase(double petrol) 
    {
        if (petrol >= 0) petrol_on_base = petrol;
        else 
        {
            petrol_on_base = 0.0;
        }
    }

    static double GetGoodsOnBase() { return goods_on_base; }
    static void SetGoodsOnBase(double goods) 
    {
        if (goods >= 0) goods_on_base = goods;
        else 
        {
            goods_on_base = 0.0;
        }
    }

    static void ShowBaseStatus() 
    {
        cout << "Current Base Status:" << endl;
        cout << "People on base: " << people_on_base << endl;
        cout << "Vehicles on base: " << vehicles_on_base << endl;
        cout << "Petrol on base: " << petrol_on_base << " liters" << endl;
        cout << "Goods on base: " << goods_on_base << " tons" << endl;
    }
};


