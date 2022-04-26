#include "Vehicle.h"

/* Defining static variables from Vehicle class.
 * These variables are declared static because the value doesn't change
 * for each instance of Vehicle object.
 * The vehicle type is like a menu option to select
 * and the number of spots is a map variable to calculate the number of spots a Vehicle
 * can occupy based on its vehicle type.*/

std::map<int, std::string> Vehicle::v_type { { 1, "car" }, { 2, "compact_car" }, { 3, "motorcycle" }, { 4, "bus" },
    { 5, "electric_car" }, { 6, "truck" } };

std::map<int, int> Vehicle::no_of_spots { { 1, 1 }, { 2, 1 }, { 3, 1 }, { 4, 4 }, { 5, 1 }, { 6, 2 } };

// Constructor which initialises the vehicle number
Vehicle::Vehicle(std::string v_no)
    : vehicle_no { v_no } {};

// Displays the vehicle type (v_type) variable for user to select
void Vehicle::vehicletype_disp()
{
    for(auto& v : Vehicle::v_type)
        std::cout << std::endl
                  << std::setfill(' ') << std::setw(15) << std::left << v.second << " - " << std::setw(5) << std::right
                  << v.first << std::endl;
}

// Get size of the map variable v_type
int Vehicle::get_size()
{
    return Vehicle::v_type.size();
}
