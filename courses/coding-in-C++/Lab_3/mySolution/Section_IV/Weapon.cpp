/**
 * @file Weapon.cpp
 * @brief Implementation of the Weapon class
 */

#include "Weapon.hpp"
#include <iostream>

/**
 * @brief Constructor of the Weapon class
 * @param name name of the weapon
 * @param damage damage of the weapon
 */
Weapon::Weapon(const std::string& name, int damage)
: name(name), damage(damage)
{}

/**
 * @brief print name and damage to console
 */
void Weapon::displayStats() const
{
    std::cout << "Weapon Name: " << name
            << "\nWeapon Damage: " << damage << std::endl;
}