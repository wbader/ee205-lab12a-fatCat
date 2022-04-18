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
#include <string>

const Weight::t_weight Weight::UNKNOWN_WEIGHT   = (-1.0);
const Weight::t_weight Weight::KILOS_IN_A_POUND = (1.0 / 2.205);
const Weight::t_weight Weight::SLUGS_IN_A_POUND = (1.0 / 32.174);

const std::string Weight::POUND_LABEL = "pound";
const std::string Weight::KILO_LABEL  = "kilogram";
const std::string Weight::SLUG_LABEL  = "slug";

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
        throw std::invalid_argument(e.what());
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
        throw std::invalid_argument (e.what());
    }
}

Weight::Weight(Weight::t_weight newWeight, Weight::t_weight newMaxWeight){
    Weight();

    try{
        setWeight(newWeight);
        setMaxWeight(newMaxWeight);
    } catch (std::exception const& e) {
        throw std::invalid_argument (e.what());
    }
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, Weight::t_weight newMaxWeight){
    Weight();

    try{
        setMaxWeight(newMaxWeight);
    } catch (std::exception const& e) {
        throw std::invalid_argument (e.what());
    }

    unitOfWeight = newUnitOfWeight;
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, Weight::t_weight newWeight, Weight::t_weight newMaxWeight) {
    Weight();

    unitOfWeight = newUnitOfWeight;
    try {
        setMaxWeight(newMaxWeight);
        setWeight(newWeight);
    } catch (std::exception const& e) {
        throw std::invalid_argument (e.what());
    }

}

Weight::~Weight() {
    bIsKnown     = false;
    bHasMax      = false;
    unitOfWeight = POUND;
    weight       = 0.0;
    maxWeight    = 0.0;
}

Weight::t_weight Weight::getWeight() const noexcept {
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


void Weight::setWeight(Weight::t_weight newWeight, Weight::UnitOfWeight weightUnits) {
    if ((newWeight > 0.0 && !bHasMax) || (newWeight > 0.0 && newWeight <= maxWeight)) {
        weight = newWeight;
        unitOfWeight = weightUnits;
        bIsKnown = true;
    } else
        throw std::invalid_argument( PROGRAM_NAME " Weight::setWeight(t_weight, UnitOfWeight): newWeight must be > 0 and <= maxWeight");
}

Weight::t_weight Weight::getMaxWeight() const noexcept {
    return maxWeight;
}

void Weight::setMaxWeight(Weight::t_weight newMaxWeight) {
    if(!bHasMax)
        Weight::maxWeight = newMaxWeight;
    else
        throw std::invalid_argument( PROGRAM_NAME " Weight::setMaxWeight(t_weight): max weight already set");
}

bool Weight::isWeightKnown() const noexcept{
    return bIsKnown;
}

bool Weight::hasMaxWeight() const noexcept{
    return bHasMax;
}

