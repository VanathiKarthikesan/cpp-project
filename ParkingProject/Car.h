#ifndef _CAR_H_
#define _CAR_H_

#include "Vehicle.h"

class Car : public Vehicle
{
friend std::ostream& operator<<(std::ostream& os, const Car& v1);
private:
    std::string vehicle_no;
    std::string vehicle_type;
    int reserve_hours;
    double total_fee;

public:
    Car();
    Car(std::string vehicle_no, int type);
    ~Car();
};

#endif // _CAR_H_
