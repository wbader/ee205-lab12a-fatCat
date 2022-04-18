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

#include <string>

class Weight {
public:  // enum and typedef
    enum UnitOfWeight {
        POUND = 0,
        KILO,
        SLUG
    };

    typedef float t_weight;

private:
    bool              bIsKnown;
    bool              bHasMax;
    t_weight          weight;
    t_weight          maxWeight;
    enum UnitOfWeight unitOfWeight;

    static const t_weight UNKNOWN_WEIGHT;
    static const t_weight KILOS_IN_A_POUND;
    static const t_weight SLUGS_IN_A_POUND;

    static const std::string POUND_LABEL ;
    static const std::string KILO_LABEL ;
    static const std::string SLUG_LABEL ;

public:
    Weight() noexcept;
    explicit Weight(Weight::t_weight newWeight);
    explicit Weight(UnitOfWeight newUnitOfWeight) noexcept;
    Weight(t_weight newWeight, UnitOfWeight newUnitOfWeight);
    Weight(t_weight newWeight, t_weight newMaxWeight);
    Weight(Weight::UnitOfWeight newUnitOfWeight, t_weight newMaxWeight);
    Weight(Weight::UnitOfWeight newUnitOfWeight, t_weight newWeight, t_weight newMaxWeight);

    virtual ~Weight();

    bool isWeightKnown() const noexcept;
    bool hasMaxWeight() const noexcept;

    t_weight getWeight() const noexcept;
    t_weight getWeight(Weight::UnitOfWeight weightUnits) const noexcept;
    t_weight getMaxWeight() const noexcept;
    Weight::UnitOfWeight getWeightUnit() const noexcept;

    void setWeight(t_weight newWeight);
    void setWeight(t_weight newWeight, Weight::UnitOfWeight weightUnits);

    bool isWeightValid(float checkWeight) const noexcept;
    bool validate() const noexcept;

    void dump() const noexcept;

    bool operator==(const Weight &rhs_Weight) const;
    bool operator<(const Weight &rhs_Weight) const;

    Weight & operator+=(float rhs_addToWeight);

    static Weight::t_weight fromKilogramToPound(Weight::t_weight kilogram) noexcept;
    static Weight::t_weight fromPoundToKilogram(Weight::t_weight pound) noexcept;

    static Weight::t_weight fromSlugToPound(Weight::t_weight slug) noexcept;
    static Weight::t_weight fromPoundToSlug(Weight::t_weight pound) noexcept;

    static Weight::t_weight convertWeight(Weight::t_weight fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) noexcept;

    void setMaxWeight(float newMaxWeight);
};










