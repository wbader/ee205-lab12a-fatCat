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
#include <iomanip>

/// Format the heading for dumping members of a class to the console
///
/// Print =====================
#define PRINT_HEADING_FOR_DUMP \
 /* Print =========================================================== */ \
 std::cout << std::setw(80) << std::setfill( '=' ) << "" << std::endl
/// Format a line for dumping the members of a class to the console.
/// Setup the fields for printing (space pad, left justify, etc.)
#define FORMAT_LINE_FOR_DUMP( className, member ) \
 std::cout << std::setfill( ' ' ) /* Space pad */ \
 << std::left /* Left justify */ \
 << std::boolalpha /* Print `true` or `false` for `bool`s */ \
 << std::setw(8) << (className) \
 << std::setw(20) << (member) \
 << std::setw(52) /* (data) */

const Weight::t_weight Weight::UNKNOWN_WEIGHT   = (0.0);
const Weight::t_weight Weight::KILOS_IN_A_POUND = (0.453592);
const Weight::t_weight Weight::SLUGS_IN_A_POUND = (0.031081);

const std::string Weight::POUND_LABEL = "Pound";
const std::string Weight::KILO_LABEL  = "Kilogram";
const std::string Weight::SLUG_LABEL  = "Slug";

Weight::Weight() noexcept {
    bIsKnown     = false;
    bHasMax      = false;
    unitOfWeight = POUND;
    weight       = 0.0;
    maxWeight    = 0.0;
}

Weight::Weight(Weight::t_weight newWeight) : Weight() {
    try {
        setWeight(newWeight);
    } catch (std::exception const& e) {
        throw std::invalid_argument(e.what());
    }

    assert(validate());
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight) noexcept : Weight() {
    unitOfWeight = newUnitOfWeight;
}

Weight::Weight(t_weight newWeight, UnitOfWeight newUnitOfWeight) : Weight() {

    unitOfWeight = newUnitOfWeight;
    try {
        setWeight(newWeight);
    } catch (std::exception const& e) {
        throw std::invalid_argument (e.what());
    }

    assert(validate());
}

Weight::Weight(Weight::t_weight newWeight, Weight::t_weight newMaxWeight) : Weight() {

    try{
        setWeight(newWeight);
        setMaxWeight(newMaxWeight);
    } catch (std::exception const& e) {
        throw std::invalid_argument (e.what());
    }

    assert(validate());
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, Weight::t_weight newMaxWeight) : Weight() {
    try{
        setMaxWeight(newMaxWeight);
    } catch (std::exception const& e) {
        throw std::invalid_argument (e.what());
    }

    unitOfWeight = newUnitOfWeight;

    assert(validate());
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, Weight::t_weight newWeight, Weight::t_weight newMaxWeight) : Weight() {

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
    t_weight convertedWeight = convertWeight(newWeight, weightUnits, unitOfWeight);
    if ((convertedWeight > 0.0 && !bHasMax) || (convertedWeight > 0.0 && convertedWeight <= maxWeight)) {
        weight = convertedWeight;
        bIsKnown = true;
    } else
        throw std::invalid_argument( PROGRAM_NAME " Weight::setWeight(t_weight, UnitOfWeight): newWeight must be > 0 and <= maxWeight");
}

Weight::t_weight Weight::getMaxWeight() const noexcept {
    if(bHasMax)
        return maxWeight;
    else
        return UNKNOWN_WEIGHT;
}

void Weight::setMaxWeight(Weight::t_weight newMaxWeight) {
    if(!bHasMax) {
        Weight::maxWeight = newMaxWeight;
        bHasMax = true;
    }
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
    t_weight lhs_weight = (bIsKnown) ? getWeight(UnitOfWeight::POUND) : (Weight::t_weight ) 0.0;
    t_weight rhs_weight = (rhs_Weight.isWeightKnown()) ? rhs_Weight.getWeight(UnitOfWeight::POUND) : (Weight::t_weight ) 0.0;

    return lhs_weight == rhs_weight;
}

bool Weight::operator<(const Weight &rhs_Weight) const {
    t_weight lhs_weight = (bIsKnown) ? getWeight(UnitOfWeight::POUND) : (Weight::t_weight ) 0.0;
    t_weight rhs_weight = (rhs_Weight.isWeightKnown()) ? rhs_Weight.getWeight(UnitOfWeight::POUND) : (Weight::t_weight ) 0.0;

    return lhs_weight < rhs_weight;
}

Weight& Weight::operator+=(Weight::t_weight rhs_addToWeight) {
    t_weight newWeight = getWeight() +rhs_addToWeight;
    if(isWeightValid(newWeight))
        setWeight(newWeight);
    else
        throw std::out_of_range( PROGRAM_NAME " Weight::operator+= exceeded maxWeight" );

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
            //break;
        case UnitOfWeight::KILO:
            if(fromUnit == UnitOfWeight::POUND)
                return fromPoundToKilogram(fromWeight);
            else if (fromUnit == UnitOfWeight::SLUG)
                return fromPoundToKilogram(fromSlugToPound(fromWeight));
            else
                return fromWeight;
            //break;
        case UnitOfWeight::SLUG:
            if(fromUnit == UnitOfWeight::POUND)
                return fromPoundToSlug(fromWeight);
            else if (fromUnit == UnitOfWeight::KILO)
                return fromPoundToSlug(fromKilogramToPound(fromWeight));
            else
                return fromWeight;
            //break;
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
    if(weight.hasMaxWeight()){
        os << weight.getWeight() << " out of " << weight.getMaxWeight() << " " << weight.getWeightUnit();
        if(weight.getMaxWeight() != 1.0)
            os << "s";
    } else {
        os << weight.getWeight() << " " << weight.getWeightUnit();
        if (weight.getWeight() != 1.0)
            os << "s";
    }
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

void Weight::dump() const noexcept {
    PRINT_HEADING_FOR_DUMP;
    FORMAT_LINE_FOR_DUMP("Weight", "this") << this << std::endl;
    FORMAT_LINE_FOR_DUMP("Weight", "bIsKnown") << bIsKnown << std::endl;
    FORMAT_LINE_FOR_DUMP("Weight", "weight") << weight << std::endl;
    FORMAT_LINE_FOR_DUMP("Weight", "unitOfWeight") << unitOfWeight << std::endl;
    FORMAT_LINE_FOR_DUMP("Weight", "bHasMax") << bHasMax << std::endl;
    FORMAT_LINE_FOR_DUMP("Weight", "maxWeight") << maxWeight << std::endl;
}