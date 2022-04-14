///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-lab12a-fatCat - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// This is a test harness for the fatCat lab to test the Weight Class.
///
/// @author Waylon Bader <wbader@hawaii.edu>
/// @date   17_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <iostream>

#include "config.h"
#include "Weight.h"

int main(){
    std::cout << PROGRAM_NAME << " starting" << std::endl;
    Weight weight(Weight::POUND, 0, 0);



    std::cout << PROGRAM_NAME << " ending" << std::endl;
}