#ifndef _Billing_H_
#define _Billing_H_

#include <ctime>
#include <iostream>

class Billing
{
    friend std::ostream& operator<<(std::ostream& os, const Billing& b);

protected:
    // Vehicle time of entry, exit, total time occupied, total fees and tax rate
    // tax rate is static since it doesn't change for each object
    time_t entry_t;
    time_t exit_t;
    time_t total_t;
    double p_fee;
    static double tax_rate;

public:
    static double charge_ph;
    // no args constructor
    Billing();
    // sets the entry time of the vehicle
    Billing(time_t);
    // sets the exit time of the vehicle
    void set_exit(time_t);
    // calculates the total time occupied
    time_t calculate_tt();
    // calculates the bill
    void calculate_bill(int);
    /* Displays the charges per hour, 4 hrs and per day using the static variables from the Billing class. */
    static void price_display();
    ~Billing() = default;
};

#endif // _Billing_H_
