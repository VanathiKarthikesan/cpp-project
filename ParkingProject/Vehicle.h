#ifndef _Vehicle_H_
#define _Vehicle_H_

#include <iomanip>
#include <map>
#include <string>
#include <iostream>

class Vehicle // Abstract class
{
protected:
    // The vehicle number, type of vehicle and number of spots it can occupy
    const std::string vehicle_no;
    static std::map<int, int> no_of_spots;

public:
    static std::map<int, std::string> v_type;
    // no args constructor
    Vehicle() noexcept = default;
    // Constructor which initialises the vehicle number
    Vehicle(std::string);

    // Displays the vehicle type (v_type) variable for user to select
    static void vehicletype_disp();
    // Get size of the map variable v_type
    static int get_size();

    // Pure virtual function which will be overridden in the derived class
    virtual bool compare_vehicle(std::string vno) = 0;
    virtual ~Vehicle() = default;
};

#endif // _Vehicle_H_
