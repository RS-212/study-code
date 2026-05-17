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
private:
    int weaponXp;

public:
    /**
     * @brief override of abstract display method in Character
     * @return reference to calling Warrior
     */
    Warrior& display() const override;

    /**
     * @brief regenerate weapon xp points
     * @param amount amount of weapon xp to regenerate
     * @return reference to calling Warrior
     */
    Warrior& regeneratePoints(int amount) override;
};

#endif // WARRIOR_HPP