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

    Weight *weight = nullptr;
    Weight weight1;
    Weight weight2 = Weight(Weight::KILO);
    Weight weight3;
    Weight weight4;
    Weight weight5;
    Weight weight6 = Weight();
    try {
        weight = new Weight(Weight::POUND, 10.0, 40.0);
        weight1 = Weight(5.1);
        weight3 = Weight(5, 15);
        weight4 = Weight( 5, Weight::SLUG);
        weight5 = Weight(Weight::KILO, 50);
    } catch (std::exception const& e) {
        cerr << e.what() << endl;
    }


    cout << endl << *weight << endl;
    cout << weight1 << endl;
    cout << boolalpha;
    cout << *weight << " < " << weight1 << "? " << (*weight < weight1) << endl;
    cout << weight1 << " += 5.1 -> " << (weight1 += 5.1) << endl;
    cout << *weight << " < " << weight1 << "? " << (*weight < weight1) << endl;
    weight5.setWeight(5, Weight::POUND);
    cout << weight3 << " == " << weight5 << " ? " << (weight3 == weight5) << endl;

    weight2.setWeight(9.9, Weight::POUND);

    cout << weight2 << " < " << weight1 << "? " << (weight2 < weight1) << endl;
    weight1.setWeight(1);
    cout << weight1 << endl;

    weight->dump();
    weight1.dump();
    weight2.dump();
    weight3.dump();
    weight4.dump();
    weight5.dump();
    weight6.dump();


    delete weight;

    cout << PROGRAM_NAME << " Ending" << endl;
}