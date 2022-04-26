#ifndef _Parking_lot_H_
#define _Parking_lot_H_
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <memory>
#include <algorithm>
#include <iomanip>
#include "Automob.h"

class Parking_lot: public Automob
{
protected:
//The number of levels in the parking lot and the total number of spots on each level
    std::map<int,int> level_n_cars{{1,100},{2,100},{3,100},{4,100}};
//Automob object that contains details about the vehicle, within a vector
	std::vector<std::unique_ptr<Automob>> v_in_parkin;
    
public:
    friend std::ostream& operator<<(std::ostream& os, const Parking_lot& p1);
    //no args constructor
    Parking_lot();
    //Overloaded function that accepts an integer while adding a vehicle in the parking lot
    void update_lot(int);
    //Overloaded function that accepts a string while removing a vehicle from the parking lot
    bool update_lot(std::string);
    //calls the update_lot when the user chooses check out in the menu
	bool check_out();
    //Update the Automob object when adding or removing a vehicle from the lot
    void update_vec(std::unique_ptr<Automob> v1);
    ~Parking_lot() = default;
};


#endif // _Parking_lot_H_
