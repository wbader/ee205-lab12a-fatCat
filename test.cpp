///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  fatCat - EE 205 - Spr 2022
///
/// @file test.cpp
/// @version 1.0
///
/// @author Waylon Bader <wbader@hawaii.edu>
/// @date   17_Apr_2022
///////////////////////////////////////////////////////////////////////////////

/// Test harness for the class Weight

#include "Weight.h"
#include "config.h"

#include <iostream>

using namespace std;
int main()
{
    cout << PROGRAM_NAME << " Starting" << endl;

    Weight *weight;

    try {
        weight = new Weight(Weight::POUND, 10.0, 40.0);
    } catch (std::exception const& e) {
        cout << e.what() << endl;
    }



    delete weight;

    cout << PROGRAM_NAME << " Ending" << endl;
}