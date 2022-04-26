#include <ctime>
#include <iomanip>
#include "Automob.h"

// no args constructor
Automob::Automob()
    : Vehicle { "None" }
    , vehicle_type { "N/A" }
    , reserve_hours { 0 }
    , total_fee { 0 }
    , spots { 0 }
    , b {}
{
}
// constructor connects with vehicle class to update vehicle number, vehicle_type and spots
// creates a billing object with the time of entry into the parking lot
Automob::Automob(std::string vehicle_no, int type)
    : Vehicle { vehicle_no }
    , vehicle_type { v_type.at(type) }
    , reserve_hours { 0 }
    , total_fee { 0 }
    , spots { no_of_spots.at(type) }
    , b { time(NULL) }
{
}
/*overloaded operators < and == for comparing vehicle numbers
    to select the right vehicle during check out */
bool Automob::operator<(const Automob& c1) const
{
    if(this->vehicle_no < c1.vehicle_no)
        return true;
    else
        return false;
}

bool Automob::operator==(const Automob& c1) const
{
    if(this->vehicle_no == c1.vehicle_no)
        return true;
    else
        return false;
}
/* Compares the vehicle numbers and returns true or false using the overloaded operators < and == for comparing vehicle
   numbers to select the right vehicle during check out */
bool Automob::compare_vehicle(std::string vno)
{
    if(this->vehicle_no == vno)
        return true;
    else
        return false;
}

// Updates the exit time
// calculates bill using the entry and exit time in the Billing object
void Automob::update_b(time_t et)
{
    b.set_exit(et);
    b.calculate_bill(spots);
    std::cout << b;
}

/* Return spots variable value */
int Automob::get_spots()const {
    return spots;
}
// print the vehicle details
std::ostream& operator<<(std::ostream& os, const Automob& v1)
{
    os << std::endl
       << std::setw(15) << std::setfill(' ') << std::left << "Vehicle no" << std::setw(10) << std::right << "Type"
       << std::endl;
    os << std::setw(15) << std::left << v1.vehicle_no << std::setw(10) << std::right << v1.vehicle_type << std::endl;
    return os;
}
