///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-lab12a-fatCat - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// This is a test harness for the fatCat lab to test the Weight Class.
/// I ended up making a second one, and never used this one.
///
/// @author Waylon Bader <wbader@hawaii.edu>
/// @date   17_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <iostream>

#include "config.h"
#include "Weight.h"

// Actual testing done in test.cpp, use the fatCat_test executable

int main(){
    std::cout << PROGRAM_NAME << " starting" << std::endl;
    Weight* weight;
    try {
        weight = new Weight(Weight::POUND, 1, 5);
    }
    catch (std::exception const& e) {
        std::cerr << e.what();
    }

    weight->dump();


    std::cout << PROGRAM_NAME << " ending" << std::endl;
}