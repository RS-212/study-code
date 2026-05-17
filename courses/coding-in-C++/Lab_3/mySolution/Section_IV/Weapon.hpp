/**
 * @file Weapon.hpp
 * @brief Class header wor Weapon class
 */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

/**
 * @class Weapon
 * @brief Basic weapon with a name and damage
 */
class Weapon
{
private:
    std::string name;
    int damage;

public:
    /**
     * @brief print name and damage to console
     * @return Reference to caller
     */
    Weapon& displayStats() const;
};

#endif // WEAPON_HPP