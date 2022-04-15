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

Weight::Weight() {
    bIsKnown     = false;
    bHasMax      = false;
    unitOfWeight = POUND;
    weight       = 0.0;
    maxWeight    = 0.0;
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, Weight::t_weight newWeight, Weight::t_weight    newMaxWeight)
{
    Weight();

    unitOfWeight = newUnitOfWeight;
    setWeight(newWeight);
    setMaxWeight(newMaxWeight);

}

Weight::~Weight() {

}

Weight::t_weight Weight::getWeight() const {
    if(bIsKnown)
        return weight;
    else
        return UNKNOWN_WEIGHT;
}

void Weight::setWeight(Weight::t_weight newWeight) {
    Weight::weight = newWeight;
}


void Weight::setWeight(Weight::t_weight newWeight, Weight::UnitOfWeight newUnitOfWeight)
{
    if(bHasMax)
    {
        std::cerr << PROGRAM_NAME << " setWeight(float, UnitOfWeight): bHasMax is true" << std::endl;
    }
}

Weight::t_weight Weight::getMaxWeight() const {
    return maxWeight;
}

void Weight::setMaxWeight(Weight::t_weight newMaxWeight) {
    Weight::maxWeight = newMaxWeight;
}
