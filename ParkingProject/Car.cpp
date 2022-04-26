#include <iostream>
#include "Car.h"


Car::Car()
    : vehicle_no { "None" }
    , vehicle_type { "N/A" }
    , reserve_hours { 0 }
    , total_fee { 0 }
{
}
Car::Car(std::string vehicle_no, int type)
    : vehicle_no { vehicle_no }
    , vehicle_type { v_type.at(type) }
    , reserve_hours { 0 }
    , total_fee { 0 }
{
}

Car::~Car(){
}

std::ostream& operator<<(std::ostream& os, const Car &v1)
{
    os<<"Your reservation for "<<v1.vehicle_no<<" of type "<<v1.vehicle_type<<" is successful\n";
    return os;
}

