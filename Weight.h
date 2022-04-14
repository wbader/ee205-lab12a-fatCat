///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-lab12a-fatCat - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 1.0
///
/// @author Waylon Bader <wbader@hawaii.edu>
/// @date   17_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

class Weight {
public:
    enum UnitOfWeight {
        POUND,
        KILO,
        SLUG
    };

private:
    bool bIsKnown;
    bool bHasMax;
    float weight;
    float maxWeight;
public:
    float getMaxWeight() const;

    void setMaxWeight(float newMaxWeight);

private:
    enum UnitOfWeight unitOfWeight;

public:

    Weight(Weight::UnitOfWeight newUnitOfWeight, float newWeight, float newMaxWeight);
    float getWeight() const;
    void setWeight(float newWeight);
    void setWeight(float newWeight, Weight::UnitOfWeight newUnitOfWeight);

};



