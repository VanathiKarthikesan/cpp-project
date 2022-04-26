#include <cmath>
#include <iomanip>
#include "Billing.h"

/* Defining static variables from Billing class.
 * tax rate and the hourly charge for parking doesn't change for every object
 * it remains the same for all objects so its declared static */
double Billing::tax_rate = 0.08;
double Billing::charge_ph = 10;

// no args constructor
Billing::Billing()
    : entry_t { 0 }
    , exit_t { 0 }
    , total_t { 0 }
    , p_fee { 0 }
{
}

// initialises the entry time of the vehicle from the input parameter, rest are set to 0
Billing::Billing(time_t ct)
    : entry_t { ct }
    , exit_t { 0 }
    , total_t { 0 }
    , p_fee { 0 }
{
}

// set the exit time of vehicle
void Billing::set_exit(time_t et)
{
    this->exit_t = et;
}

// Calculate the total time
time_t Billing::calculate_tt()
{
    return exit_t - entry_t;
}

// Calculate the bill
void Billing::calculate_bill(int spots)
{
    // calls the calculate total time function to get the amount of time the vehicle remained in the lot
    total_t = calculate_tt();

    /* The output from above call returns the answer in seconds. For testing/display purpose converted
     * the time to minutes instead of hours. */
    total_t = total_t / 60;
    double temp {};
    // If the vehicle occupies for 4 hrs apply discount for that time and calculate bill
    if(total_t > 3 && total_t < 4)
        temp = 30 * spots;
    // If the vehicle occupies for 12 hrs apply discount for that time and calculate bill
    else if(total_t > 11 && total_t < 12)
        temp = 100 * spots;
    else
        temp = total_t * charge_ph * spots;
    p_fee = temp + (temp * tax_rate);
}

/* Displays the charges per hour, 4 hrs and per day using the static variables from the Billing class. */
void Billing::price_display()
{
    std::cout << std::endl;
    std::cout << std::setw(70) << std::setfill('-') << " " << std::endl;
    std::cout << "          Parking charges per slot           " << std::endl;
    std::cout << "First hour: " << Billing::charge_ph << "$" << std::endl;
    std::cout << "Next 4 hours: " << Billing::charge_ph * 3 << "$" << std::endl;
    std::cout << "Per day: " << Billing::charge_ph * 10 << "$" << std::endl;
    std::cout << std::setw(70) << std::setfill('-') << " " << std::endl << std::endl;
}

// display the bill
std::ostream& operator<<(std::ostream& os, const Billing& b)
{
    os << "Total hours: " << b.total_t << std::endl;
    os << "Total fee: " << std::setprecision(2) << std::fixed << b.p_fee << "$" << std::endl;
    return os;
}
