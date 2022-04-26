#include "Parking_lot.h"

// no args constructor
Parking_lot::Parking_lot()
    : v_in_parkin {}
{
}

// Overloaded function that accepts an integer as a parameter: adds a vehicle in the parking lot
void Parking_lot::update_lot(int remove)
{
    bool empty { true };
    // update the parking lot slots after a vehicle is entered
    // remove a slot from available slots
    for(int i = 1; i < 5 && empty; ++i) {
        if(this->level_n_cars[i] > remove) {
            this->level_n_cars[i] -= remove;
            empty = false;
        }
    }
}

// Overloaded function that accepts a string as a parameter: removes a vehicle from the parking lot
bool Parking_lot::update_lot(std::string v_no)
{
    bool fnd { false };
    int i { 0 };
    for(auto& v : v_in_parkin) {
        if(v->compare_vehicle(v_no)) {
            std::vector<std::unique_ptr<Automob>>::iterator it = v_in_parkin.begin() + i;
            // update the exit time in the Billing object
            v->update_b(time(NULL));
            //Get the number of spots the vehicle occupied before erasing object
            int spots = v->get_spots();
            // erase the Automob object
            it = v_in_parkin.erase(it);
            fnd = true;
            bool empty { true };
            // update the parking lot slots after a vehicle leaves
            // add a slot to the available parking slots
            for(int i = 1; i < 5 && empty; ++i) {
                if(this->level_n_cars[i] < (100-spots)) {
                    this->level_n_cars[i] += spots;
                    empty = false;
                }
            }
            break;
        }
        ++i;
    }
    if(!fnd)
        std::cout << "Enter your vehicle number correctly" << std::endl;
    return fnd;
}

bool Parking_lot::check_out()
{
    // Get user input: Vehicle number to be checked out
    std::cout << "\nPlease enter your vehicle number: ";
    std::string v_no {};
    std::cin >> v_no;
    bool fnd {false};
    // Call the update function which removes the Automob object, calculates bill and update parking lot
    fnd = this->update_lot(v_no);
    return fnd;
}

// Updating the vector of unique pointers through member method since its protected
// Using move since unique pointer doesn't allow copy
void Parking_lot::update_vec(std::unique_ptr<Automob> v1)
{
    this->v_in_parkin.push_back(std::move(v1));
}

// Operator << overloading function
// Displays the parking lot availability
std::ostream& operator<<(std::ostream& os, const Parking_lot& p1)
{
    os << std::setw(15) << std::setfill('~') << " " << std::endl;
    for(int i = 1; i < 5; i++)
        os << std::setfill(' ') << std::left << "level " << std::right << i << std::setw(5) << p1.level_n_cars.at(i)
           << std::endl;
    os << std::setw(15) << std::setfill('~') << " " << std::endl;
    return os;
}
