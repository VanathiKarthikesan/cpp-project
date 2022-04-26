/**************************************************************************************************/
/* File Name: Parking.cpp
 * Created by: Vanathi Karthikesan
 * Created date: 4/8/2022
 * Last Edited: 4/25/2022
 **************************************************************************************************/

/********************* Parking Reservation System*************************************************/
/* The purpose of this project is to manage and maintain the multi level parking garage.
 * It allows the customer to reserve an available spot, check availability and price, and
 * check out of the garage. Parking Reservation System is done using Object Oriented Programming
 * concepts Inheritance, Data Encapsulation, Abstraction and Polymorphism. The customer data
 * (the vehicle number and vehicle type) is secured using Data Encapsulation. The Vehicle class
 * is an abstract class from which the Automobile class inherits.
 **************************************************************************************************/

#include "Automob.h"
#include "Parking_lot.h"
#include <sstream>

/* Declaration of functions used in the main.*/
/* Displays the user menu */
void display_menu();

/* Gets user input.
 * Vehicle number and Vehicle type from the display menu.
 * And creates a Automob object with user input which again is
 * assigned to a unique pointer. */
std::unique_ptr<Automob> get_reserve_ip();

int main()
{
    // Variable to get user choice for the main menu
    int choice { 0 };
    /* A boolean variable used to loop back to the main menu unless the user exits.
     * When the user exits the menu this variable is change to false to exit out of menu. */
    bool q { true };
    std::unique_ptr<Parking_lot> park_lot = std::make_unique<Parking_lot>();

    /* Main loop for the display menu.
     * Loop runs until the user exits the menu or checks out
     * Enters an invalid input causing the exception to throw. */
    while(q) {
        // Display main user menu
        display_menu();
        try {
            /* Get user input in a string variable and use string stream to validate user input.
             * if the input is not an integer then throw exception and exit the program.
             * The user have to run the program again with valid integer. */
            std::string ch {};
            std::cin >> ch;
            std::stringstream ss { ch };
            if(ss >> choice)
                ;
            else
                throw 0;
            /* Using Switch case statements to check the option the user entered and
             * execute code corresponding to the menu option selected.
             * Using Switch instead of if else to save execution time. */
            switch(choice) {
            case 1: {
                /* Reserves a spot for the vehicle.
                 * Asks the user input - vehicle number and vehicle_type
                 * Creates a Automob object:
                 *       1. Calls Vehicle constructor with Vehicle number
                 *       2. Selects the Vehicle type from Vehicle::v_type depending on the user input
                 *       3. Selects the number of spots the vehicle can occupy from Vehicle::no_of_spots
                 *       4. Call the Billing object constructor with the entry time
                 *    and assign it to a unique pointer.
                 * Update the Parking lot object:
                 *    By Updating the number of available lots
                 *    And update the vector in Parking_lot with the newly created unique pointer to the Automob
                 * object.*/
                std::cout << "\nReserve parking" << std::endl;
                std::unique_ptr<Automob> v1 = std::move(get_reserve_ip());
                std::cout << *v1;
                // update the parking lot
                // Get the number of spots before the object gets moved
                int spots = v1->get_spots();
                // Move the unique_ptr to the vector
                park_lot->update_vec(std::move(v1));
                // Update the available spots
                park_lot->update_lot(spots);
                std::cout << "\nThank you!!! Reservation complete. Have a nice day!!!\n";
                break;
            }
            case 2: {
                /* Check how many slots are available/filled by accessing the parking lot object
                 * Display the parking lot object using the overloaded << operator */
                std::cout << "\nParking lot availability\n\n";
                std::cout << *park_lot << std::endl;
                break;
            }
            case 3: {
                /* Call the check out method in the Parking lot class which does the following tasks
                 * 1. Get system time and update the exit time of the Automob in the Billing class
                 * 2. Calculate the total time occupied using the Billing class method calculate time
                 * 3. Calculate the total bill in the Billing class method calculate fees
                 * 4. Delete the Automob object from the vector in the Parking lot class so the vehicle details are
                 * removed.
                 * 5. Update the parking lot availability - since a slot becomes open during check out.
                 * 6. Display the bill amount. */
                // Change q to false once successfully checked out
                q = !(park_lot->check_out());
                break;
            }
            case 4: {
                // Displays the charges per hour, 4 hrs and per day using the static variables from the Billing class.
                Billing::price_display();
                break;
            }
            case 5:
                // Sign out of the menu
                q = false;
                break;
            default:
                std::cout << "Please enter a valid choice" << std::endl;
                break;
            }
        }

        /* Catch exception thrown when the user does not enter an integer */
        catch(int& ex) {
            std::cerr << "Try again! your choice is invalid!" << std::endl;
            q = false;
        }
    }
    return 0;
}

void display_menu()
{
    std::cout << "\n\n" << std::setw(70) << std::setfill('*') << " " << std::endl;
    std::cout << "          Welcome to Car parking reservation System" << std::endl;
    std::cout << std::setw(70) << std::setfill('*') << " " << std::endl;
    std::cout << "\n1. Reserve parking space" << std::endl;
    std::cout << "2. Check available slots" << std::endl;
    std::cout << "3. Check out" << std::endl;
    std::cout << "4. Check parking fee" << std::endl;
    std::cout << "5. Quit\n" << std::endl;
    std::cout << std::setw(70) << std::setfill('*') << " \n" << std::endl;

    std::cout << "Please enter your choice:  ";
}

std::unique_ptr<Automob> get_reserve_ip()
{
    /*Get user input for Vehicle number */
    std::cout << "Please enter your vehicle number: ";
    std::string vehicle_no;
    std::cin >> vehicle_no;

    /*Select an option to choose vehicle type */
    std::cout << "\nSelect an option number to choose your vehicle type" << std::endl;
    Vehicle::vehicletype_disp();
    std::cout << "\nOption: ";
    int vehicle_type;
    std::string ch1;
    /*Validate whether the input entered is an integer using string stream */
    std::cin >> ch1;
    std::stringstream ss1 { ch1 };
    if(ss1 >> vehicle_type)
        ;
    else
        throw 1;
    /*Validate the range of input before passing to the function
     * if the value is out of range of map size throws an exception.  */
    if(vehicle_type > Vehicle::get_size()) {
        std::cout << "Your value is out of range" << std::endl;
        throw 2;
    }

    /* Create a unique pointer for automobile class and create a new object*/
    std::unique_ptr<Automob> v1 = std::make_unique<Automob>(vehicle_no, vehicle_type);
    return v1;
}