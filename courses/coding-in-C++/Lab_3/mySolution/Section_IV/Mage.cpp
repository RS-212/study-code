/**
 * @file Mage.cpp
 * @brief Implementation of the Mage class
 */

#include "Mage.hpp"
#include <iostream>

/**
 * @brief Constructor for Mages
 * @param name character name
 * @param health base health
 * @param inventorySize starting inventory size
 * @param weapon starting weapon
 */
Mage::Mage(const std::string name, int health, int inventorySize, Weapon& weapon)
: Character(name, health, inventorySize, weapon), mana(0)
{}

/**
 * @brief override of abstract display method in Character
 * @return reference to calling Mage
 */
Mage& Mage::display()
{
        std::cout << "Name: " << name
            << "\nClass: Mage"
            << "\nHealth: " << getHealth()
            << "\nMana: " << mana
            << "\nLevel: " << level
            << "\nCurrently equipped weapon:\n";
            
    weapon->displayStats();

    std::cout << "Inventory: (" << inventory.fillLevel()
            << "/" << inventory.capacity() << ")"
            << "\n" << std::endl;

    return *this;
}

/**
 * @brief regenerate mana points
 * @param amount amount of mana to regenerate
 * @return reference to calling Mage
 */
Mage& Mage::regeneratePoints(int amount)
{
    if (amount < 0)
    {
        // No negative regeneration allowed!
        return *this;
    }
    
    mana += amount;
    return *this;
}