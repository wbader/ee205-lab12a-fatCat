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

Weight::Weight() noexcept {
    bIsKnown     = false;
    bHasMax      = false;
    unitOfWeight = POUND;
    weight       = 0.0;
    maxWeight    = 0.0;
}

Weight::Weight(Weight::t_weight newWeight) {
    Weight();
    try {
        setWeight(newWeight);
    } catch (std::exception const& e) {
        std::cerr << e.what() << std::endl;
    }
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight) noexcept {
    Weight();
    unitOfWeight = newUnitOfWeight;
}

Weight::Weight(t_weight newWeight, UnitOfWeight newUnitOfWeight)
{
    Weight();

    unitOfWeight = newUnitOfWeight;
    try {
        setWeight(newWeight);
    } catch (std::exception const& e) {
        std::cerr << e.what() << std::endl;
    }
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, Weight::t_weight newWeight, Weight::t_weight newMaxWeight) {
    Weight();

    unitOfWeight = newUnitOfWeight;
    try {
        setMaxWeight(newMaxWeight);
        setWeight(newWeight);
    } catch (std::exception const& e) {
        std::cerr << e.what() << std::endl;
    }

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
        throw std::invalid_argument( PROGRAM_NAME  " Weight::setWeight(t_weight): newWeight must be > 0 and <= maxWeight" );
}


void Weight::setWeight(Weight::t_weight newWeight, Weight::UnitOfWeight newUnitOfWeight) {
    if ((newWeight > 0.0 && !bHasMax) || (newWeight > 0.0 && newWeight <= maxWeight)) {
        weight = newWeight;
        unitOfWeight = newUnitOfWeight;
        bIsKnown = true;
    } else
        throw std::invalid_argument( PROGRAM_NAME " Weight::setWeight(t_weight, UnitOfWeight): newWeight must be > 0 and <= maxWeight");
}

Weight::t_weight Weight::getMaxWeight() const {
    return maxWeight;
}

void Weight::setMaxWeight(Weight::t_weight newMaxWeight) {
    Weight::maxWeight = newMaxWeight;
}
