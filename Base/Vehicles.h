#pragma once
#include "Base.h"
#include <iostream>

using namespace std;


class Vehicle 
{
protected:
    double petrol_amount; 
    double tank_volume;   

public:
    Vehicle(double petrol_a, double tank_v) : petrol_amount(petrol_a), tank_volume(tank_v) {}

    double getTankVolume() const 
    {
        return tank_volume;
    }

    double getPetrolAmount() const
    {
        return petrol_amount;
    }

    virtual void arrive()
    {
        if (Base::GetPeopleOnBase() >= 0) 
        {
            Base::SetVehiclesOnBase(Base::GetVehiclesOnBase() + 1);
            Base::SetPeopleOnBase(Base::GetPeopleOnBase() + 1);  
        }
    }

    virtual bool leave()
    {
        double needed_fuel = tank_volume - petrol_amount;
        if (Base::GetPetrolOnBase() >= needed_fuel && Base::GetPeopleOnBase() > 0) 
        {
            Base::SetPetrolOnBase(Base::GetPetrolOnBase() - needed_fuel);
            petrol_amount = tank_volume;
            Base::SetVehiclesOnBase(Base::GetVehiclesOnBase() - 1);
            Base::SetPeopleOnBase(Base::GetPeopleOnBase() - 1);
            cout << "Vehicle refueled and left the base!" << endl;
            return true;
        }
        else 
        {
            cout << "Not enough fuel or no people available to drive!" << endl;
            return false;
        }
    }
};

class Bus : public Vehicle 
{
private:
    int people_count; 
    int max_people;  

public:
    Bus(int people, int max, double petrol, double max_petrol) : Vehicle(petrol, max_petrol), people_count(people), max_people(max) {}

    int getPeopleCount() const 
    {
        return people_count;
    }

    int getMaxPeople() const 
    {
        return max_people;
    }

    void arrive() override 
    {
        if (Base::GetPeopleOnBase() >= 0) 
        {
            if (people_count <= 0) people_count = 1;
            Base::SetVehiclesOnBase(Base::GetVehiclesOnBase() + 1);
            Base::SetPeopleOnBase(Base::GetPeopleOnBase() + people_count); 
            cout << "Bus arrived on base! +" << people_count << " people!" << endl;
        }
    }

    bool leave() override 
    {
        double needed_fuel = tank_volume - petrol_amount;
        people_count = min(max_people, Base::GetPeopleOnBase()); 

        if (Base::GetPetrolOnBase() >= needed_fuel && people_count >0)
        {
            Base::SetPetrolOnBase(Base::GetPetrolOnBase() - needed_fuel);
            Base::SetPeopleOnBase(Base::GetPeopleOnBase() - people_count); 
            petrol_amount = tank_volume;
            Base::SetVehiclesOnBase(Base::GetVehiclesOnBase() - 1);
            cout << "Bus refueled and left the base with " << people_count << " passengers!" << endl;
            return true;
        }
        else 
        {
            cout << "Not enough fuel or no people available to drive!" << endl;
            return false;
        }
    }
};

class Truck : public Vehicle 
{
private:
    double current_load; 
    double max_load; 

public:
    Truck(double load, double max_load, double petrol, double max_petrol) : Vehicle(petrol, max_petrol), current_load(load), max_load(max_load) {}

    double getCurrentLoad() const 
    {
        return current_load;
    }

    double getMaxLoad() const 
    {
        return max_load;
    }

    void arrive() override 
    {
        if (Base::GetPeopleOnBase() >= 0) 
        {
            Base::SetVehiclesOnBase(Base::GetVehiclesOnBase() + 1);
            Base::SetGoodsOnBase(Base::GetGoodsOnBase() + current_load);  
            Base::SetPeopleOnBase(Base::GetPeopleOnBase() + 1);  
            cout << "Truck arrived on base! +1 person! +" <<current_load << " load!" << endl;
        }
    }

    bool leave() override 
    {
        double needed_fuel = tank_volume - petrol_amount;
        current_load = min(max_load, Base::GetGoodsOnBase());
        if (Base::GetPetrolOnBase() >= needed_fuel && current_load >0 && Base::GetPeopleOnBase() >0)
        {
            Base::SetPetrolOnBase(Base::GetPetrolOnBase() - needed_fuel);
            Base::SetGoodsOnBase(Base::GetGoodsOnBase() - current_load);
            petrol_amount = tank_volume;
            Base::SetVehiclesOnBase(Base::GetVehiclesOnBase() - 1);
            Base::SetPeopleOnBase(Base::GetPeopleOnBase() - 1);
            cout << "Truck refueled and left the base with " << current_load << " tons of goods!" << endl;
            return true;
        }
        else 
        {
            cout << "Not enough fuel, or goods, or people on the base!" << endl;
            return false;
        }
    }
};