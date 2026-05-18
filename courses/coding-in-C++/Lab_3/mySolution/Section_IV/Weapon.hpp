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
     * @brief Constructor of the Weapon class
     * @param name name of the weapon
     * @param damage damage of the weapon
     */
    Weapon(const std::string& name, int damage);

    /**
     * @brief print name and damage to console
     */
    void displayStats() const;
};

#endif // WEAPON_HPP