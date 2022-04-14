///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-lab12a-fatCat - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 1.0
///
/// @author Waylon Bader <wbader@hawaii.edu>
/// @date   14_Apr_2022
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
    enum UnitOfWeight unitOfWeight;
};
