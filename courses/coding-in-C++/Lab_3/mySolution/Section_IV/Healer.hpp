/**
 * @file Healer.hpp
 * @brief class header for Healer
 */

#ifndef HEALER_HPP
#define HEALER_HPP

#include "Mage.hpp"

/**
 * @class Healer
 * @brief Special Mage with healing abilities (friend of Character)
 */
class Healer : public Mage
{
protected:
    int healStrength;

public:
    /**
     * @brief Constructor for the Healer class
     * @param name character name
     * @param health base health
     * @param inventory starting inventory
     * @param weapon starting weapon
     * @param healStrength amount the healer can heal at once
     */
    Healer(const std::string name, int health, const Inventory& inventory, Weapon& weapon, int healStrength);

    /**
     * @brief heals specified target, taking into account the healers strength
     * @param target Character to heal
     * @return reference to healer
     */
    Healer& heal(Character& target);
};

#endif // HEALER_HPP