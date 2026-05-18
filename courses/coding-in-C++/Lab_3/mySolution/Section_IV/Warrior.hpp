/**
 * @file Warrior.hpp
 * @brief Class header for Warrior class
 */

#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include "Character.hpp"

/**
 * @class Warrior
 * @brief Special character with Weapon skills
 */
class Warrior : public Character
{
protected:
    int weaponXp;

public:
    /**
     * @brief Constructor for Warriors
     * @param name character name
     * @param health base health
     * @param inventory starting inventory
     * @param weapon starting weapon
     */
    Warrior(const std::string name, int health, const Inventory& inventory, Weapon& weapon);

    /**
     * @brief override of abstract display method in Character
     * @return reference to calling Warrior
     */
    Warrior& display() override;

    /**
     * @brief regenerate weapon xp points
     * @param amount amount of weapon xp to regenerate
     * @return reference to calling Warrior
     */
    Warrior& regeneratePoints(int amount) override;
};

#endif // WARRIOR_HPP