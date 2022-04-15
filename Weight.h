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
public:  // enum and typedef
    enum UnitOfWeight {
        POUND = 0,
        KILO,
        SLUG
    };

    typedef float t_weight;

private:
    bool bIsKnown;
    bool bHasMax;
    t_weight weight;
    t_weight maxWeight;
    enum UnitOfWeight unitOfWeight;

    constexpr static const t_weight UNKNOWN_WEIGHT = -1.0;
    constexpr static const t_weight KILOS_IN_A_POUND = (1.0 / 2.205);
    constexpr static const t_weight SLUGS_IN_A_POUND = (1.0 / 32.174);

public:
    Weight();
    Weight(Weight::UnitOfWeight newUnitOfWeight, t_weight newWeight, t_weight newMaxWeight);

    virtual ~Weight();

    t_weight getMaxWeight() const;
    void setMaxWeight(float newMaxWeight);

    t_weight getWeight() const;
    void setWeight(t_weight newWeight);
    void setWeight(t_weight newWeight, Weight::UnitOfWeight newUnitOfWeight);

};







