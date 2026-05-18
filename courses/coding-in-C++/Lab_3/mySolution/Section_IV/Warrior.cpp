/**
 * @file Warrior.cpp
 * @brief Implementation of the Warrior class
 */

#include "Warrior.hpp"
#include <iostream>

/**
 * @brief Constructor for Warriors
 * @param name character name
 * @param health base health
 * @param inventory starting inventory
 * @param weapon starting weapon
 */
Warrior::Warrior(const std::string name, int health, const Inventory& inventory, Weapon& weapon)
: Character(name, health, inventory, weapon)
{}

/**
 * @brief override of abstract display method in Character
 * @return reference to calling Warrior
 */
Warrior& Warrior::display()
{
    std::cout << "Name: " << name
            << "\nClass: Warrior"
            << "\nHealth: " << getHealth()
            << "\nWeapon skill points: " << weaponXp
            << "\nLevel: " << level
            << "\nCurrently equipped weapon:\n";
            
    weapon->displayStats();

    std::cout << "Inventory: (" << inventory.fillLevel()
            << "/" << inventory.capacity() << ")"
            << "\n" << std::endl;

    return *this;
}

/**
 * @brief regenerate weapon xp points
 * @param amount amount of weapon xp to regenerate
 * @return reference to calling Warrior
 */
Warrior& Warrior::regeneratePoints(int amount)
{
    if (amount < 0)
    {
        // No negative regeneration allowed!
        return *this;
    }
    
    weaponXp += amount;
    return *this;
}