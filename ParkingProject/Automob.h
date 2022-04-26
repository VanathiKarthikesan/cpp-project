#ifndef _Automob_H_
#define _Automob_H_

#include <iostream>
#include "Billing.h"
#include "Vehicle.h"

class Automob : public Vehicle
{
    friend std::ostream& operator<<(std::ostream& os, const Automob& v1);

private:
    /*vehicle type is the type of the vehicle (car,bus, etc.,). Getting the data from vehicle class*/
    const std::string vehicle_type;
    /* the total number of hours a vehicle remains in the parking lot */
    int reserve_hours;
    /* Total fee the customer has to pay after check out */
    double total_fee;
    /* spots is the number of spots it can occupy. Getting the data from vehicle class*/
    int spots;
    // the hours the vehicle is in the parking lot calculated using Billing classs
    Billing b;

public:
    Automob();
    Automob(std::string vehicle_no, int type);
    /*overloaded operators < and == for comparing vehicle numbers
    to select the right vehicle during check out */
    bool operator<(const Automob& c1) const;
    bool operator==(const Automob& c1) const;
    
    //compare the vehicle number to select the vehicle for check out
    virtual bool compare_vehicle(std::string vno) override;
    
    /* updates the exit time of the vehicle and 
    calculates billing after checking out using the Billing class*/
    void update_b(time_t);
    
    /* Return spots variable value */
    int get_spots()const;
    virtual ~Automob() = default;
};

#endif // _Automob_H_
