/**
 * @file Thief.hpp
 * @brief Class header for Thief class
 */

#ifndef THIEF_HPP
#define THIEF_HPP

#include "Warrior.hpp"

/**
 * @class Thief
 * @brief Special Warrior who can steal
 */
class Thief : public Warrior
{
public:
    /**
     * @brief Constructor for the Thief class
     * @param name character name
     * @param health base health
     * @param inventory starting inventory
     * @param weapon starting weapon
     */
    Thief(const std::string name, int health, const Inventory& inventory, Weapon& weapon);

    /**
     * @brief steal an item from another character's inventory
     * @param target character to steal from
     * @return reference to stealing Thief
     */
    Thief& steal(Character& target);
};

#endif // THIEF_HPP