///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-lab12a-fatCat - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 1.0
///
/// @author Waylon Bader <wbader@hawaii.edu>
/// @date   17_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Weight.h"
#include "config.h"

#include <iostream>

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, float newWeight, float newMaxWeight)
{

}

float Weight::getWeight() const {
    if(bIsKnown)
        return weight;
    else
        return -1; // @todo figure out what to return if weight is unknown
}

void Weight::setWeight(float newWeight) {
    Weight::weight = newWeight;
}


void Weight::setWeight(float newWeight, Weight::UnitOfWeight newUnitOfWeight)
{
    if(bHasMax)
    {
        std::cerr << PROGRAM_NAME << " setWeight(float, UnitOfWeight): bHasMax is true" << std::endl;
    }
}

float Weight::getMaxWeight() const {
    return maxWeight;
}

void Weight::setMaxWeight(float newMaxWeight) {
    Weight::maxWeight = newMaxWeight;
}
