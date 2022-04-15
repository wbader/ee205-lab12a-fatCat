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

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, Weight::t_weight newWeight, Weight::t_weight newMaxWeight) {
    Weight();

    unitOfWeight = newUnitOfWeight;
    setMaxWeight(newMaxWeight);
    setWeight(newWeight);

}

Weight::~Weight() {
    bIsKnown     = false;
    bHasMax      = false;
    unitOfWeight = POUND;
    weight       = 0.0;
    maxWeight    = 0.0;
}

Weight::t_weight Weight::getWeight() const {
    if(bIsKnown)
        return weight;
    else
        return UNKNOWN_WEIGHT;
}

void Weight::setWeight(Weight::t_weight newWeight) {
    if((newWeight > 0.0 && !bHasMax) || (newWeight > 0.0 && newWeight <= maxWeight) ) {
        weight = newWeight;
        bIsKnown = true;
    } else
        std::cerr << PROGRAM_NAME << " Weight::setWeight(t_weight): newWeight must be > 0 and <= maxWeight" << std::endl;
}


void Weight::setWeight(Weight::t_weight newWeight, Weight::UnitOfWeight newUnitOfWeight) {
    if((newWeight > 0.0 && !bHasMax) || (newWeight > 0.0 && newWeight <= maxWeight) ) {
        weight = newWeight;
        unitOfWeight = newUnitOfWeight;
        bIsKnown = true;
    } else {
        std::cerr << PROGRAM_NAME << " Weight::setWeight(t_weight, UnitOfWeight): newWeight must be > 0 and <= maxWeight" << std::endl;
        return;
    }
}

Weight::t_weight Weight::getMaxWeight() const {
    return maxWeight;
}

void Weight::setMaxWeight(Weight::t_weight newMaxWeight) {
    Weight::maxWeight = newMaxWeight;
}
