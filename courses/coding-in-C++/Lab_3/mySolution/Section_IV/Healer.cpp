/**
 * @file Healer.cpp
 * @brief Implementation of the Healer class
 */

#include "Healer.hpp"

/**
 * @brief Constructor for the Healer class
 * @param name character name
 * @param health base health
 * @param inventorySize starting inventory size
 * @param weapon starting weapon
 */
Healer::Healer(const std::string name, int health, int inventorySize, Weapon& weapon, int healStrength)
: Mage(name, health, inventorySize, weapon)
{
    // Input sanitizing, so no negative heal occurs
    constexpr int DEFAULT_HEAL_STRENGTH = 10;
    if (healStrength < 0)
    {
        healStrength = DEFAULT_HEAL_STRENGTH;
    }
    this->healStrength = healStrength;
}

/**
 * @brief heals specified target, taking into account the healers strength
 * @param target Character to heal
 * @return reference to healer
 */
Healer& Healer::heal(Character& target)
{
    target.health += healStrength;
    return *this;
}