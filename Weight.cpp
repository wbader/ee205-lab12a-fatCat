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
#include <cassert>

const Weight::t_weight Weight::UNKNOWN_WEIGHT   = (0.0);
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

    assert(validate());
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

    assert(validate());
}

Weight::Weight(Weight::t_weight newWeight, Weight::t_weight newMaxWeight){
    Weight();

    try{
        setWeight(newWeight);
        setMaxWeight(newMaxWeight);
    } catch (std::exception const& e) {
        throw std::invalid_argument (e.what());
    }

    assert(validate());
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, Weight::t_weight newMaxWeight){
    Weight();

    try{
        setMaxWeight(newMaxWeight);
    } catch (std::exception const& e) {
        throw std::invalid_argument (e.what());
    }

    unitOfWeight = newUnitOfWeight;

    assert(validate());
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, Weight::t_weight newWeight, Weight::t_weight newMaxWeight) {
    Weight();

    unitOfWeight = newUnitOfWeight;
    try {
        setMaxWeight(newMaxWeight);
        setWeight(newWeight);
    } catch (std::exception const& e) {
        throw std::invalid_argument(e.what());
    }

    assert(validate());
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

Weight::UnitOfWeight Weight::getWeightUnit() const noexcept{
    return unitOfWeight;
}

bool Weight::isWeightValid(Weight::t_weight checkWeight) const noexcept {
    if ((checkWeight > 0.0 && !bHasMax) || (checkWeight > 0.0 && checkWeight <= maxWeight))
        return true;
    else
        return false;
}

bool Weight::validate() const noexcept {
    if(isWeightKnown()) {
        if ((weight > 0.0 && !bHasMax) || (weight > 0.0 && weight <= maxWeight))
            return true;
        else
            return false;
    } else
        return false;
}

bool Weight::operator==(const Weight &rhs_Weight) const {
    t_weight lhs_weight = (bIsKnown) ? getWeight(UnitOfWeight::POUND) : 0.0;
    t_weight rhs_weight = (rhs_Weight.isWeightKnown()) ? rhs_Weight.getWeight(UnitOfWeight::POUND) : 0.0;

    return lhs_weight == rhs_weight;
}

bool Weight::operator<(const Weight &rhs_Weight) const {
    t_weight lhs_weight = (bIsKnown) ? getWeight(UnitOfWeight::POUND) : 0.0;
    t_weight rhs_weight = (rhs_Weight.isWeightKnown()) ? rhs_Weight.getWeight(UnitOfWeight::POUND) : 0.0;

    return lhs_weight < rhs_weight;
}

Weight& Weight::operator+=(Weight::t_weight rhs_addToWeight) {
    t_weight newWeight = getWeight() +rhs_addToWeight;
    if(isWeightValid(newWeight))
        setWeight(newWeight);
    else
        throw std::invalid_argument( PROGRAM_NAME " Weight::operator+= exceeded maxWeight" );

    assert(validate());

    return *this;
}

Weight::t_weight Weight::convertWeight(Weight::t_weight fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) noexcept
{
    switch (toUnit) {
        case UnitOfWeight::POUND:
            if (fromUnit == UnitOfWeight::KILO)
                return fromKilogramToPound(fromWeight);
            else if (fromUnit == UnitOfWeight::SLUG)
                return fromSlugToPound(fromWeight);
            else
                return fromWeight;
            break;
        case UnitOfWeight::KILO:
            if(fromUnit == UnitOfWeight::POUND)
                return fromPoundToKilogram(fromWeight);
             else if (fromUnit == UnitOfWeight::SLUG)
                return fromPoundToKilogram(fromSlugToPound(fromWeight));
             else
                return fromWeight;
            break;
        case UnitOfWeight::SLUG:
            if(fromUnit == UnitOfWeight::POUND)
                return fromPoundToSlug(fromWeight);
            else if (fromUnit == UnitOfWeight::KILO)
                return fromPoundToSlug(fromKilogramToPound(fromWeight));
            else
                return fromWeight;
            break;
        default:
            std::cerr << "convertWeight() went to default! this should never happen, but if it does I can't throw an exception" <<std::endl;
            return UNKNOWN_WEIGHT;
    }
}

Weight::t_weight Weight::getWeight(Weight::UnitOfWeight weightUnits) const noexcept {
    if(bIsKnown)
        return convertWeight(weight, unitOfWeight, weightUnits);
    else
        return UNKNOWN_WEIGHT;
}

Weight::t_weight Weight::fromKilogramToPound(Weight::t_weight kilogram) noexcept {
    return kilogram / KILOS_IN_A_POUND;
}

Weight::t_weight Weight::fromPoundToKilogram(Weight::t_weight pound) noexcept {
    return pound * KILOS_IN_A_POUND;
}

Weight::t_weight Weight::fromSlugToPound(Weight::t_weight slug) noexcept {
    return slug / SLUGS_IN_A_POUND;
}

Weight::t_weight Weight::fromPoundToSlug(Weight::t_weight pound) noexcept {
    return pound * SLUGS_IN_A_POUND;
}

std::ostream &operator<<(std::ostream &os, const Weight &weight) {
    os << weight.weight << " " << weight.unitOfWeight;
    if(weight.weight == 1.0)
        os << "S";
    return os;
}

std::ostream &operator<<(std::ostream &os, Weight::UnitOfWeight rhs_UnitOfWeight) {
    switch ( rhs_UnitOfWeight ) {
        case Weight::UnitOfWeight::POUND:
            return os << Weight::POUND_LABEL;
        case Weight::UnitOfWeight::KILO:
            return os << Weight::KILO_LABEL;
        case Weight::UnitOfWeight::SLUG:
            return os << Weight::SLUG_LABEL;
        default:
            throw std::out_of_range("The unit can't be mapped to a string");
    }
}
