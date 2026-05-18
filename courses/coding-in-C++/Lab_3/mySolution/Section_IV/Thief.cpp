/**
 * @file Thief.cpp
 * @brief Implementation of the Thief class
 */

#include "Thief.hpp"
#include <iostream>

/**
 * @brief Constructor for the Thief class
 * @param name character name
 * @param health base health
 * @param inventorySize starting inventory size
 * @param weapon starting weapon
 */
Thief::Thief(const std::string name, int health, int inventorySize, Weapon& weapon)
: Warrior(name, health, inventorySize, weapon)
{}

/**
 * @brief steal an item from another character's inventory
 * @param target character to steal from
 * @return reference to stealing Thief
 */
Thief& Thief::steal(Character& target)
{
    if(inventory.isFull())
    {
        std::cout << "Stealing failed! Inventory full!" << std::endl;
        return *this;
    }
    if(target.getInventory().isEmpty())
    {
        std::cout << "Stealing failed! Target's inventory empty!" << std::endl;
        return *this;
    }

    // Strength condition
    if(weaponXp > target.getHealth())
    {
        // Stealing succeeded
        std::string stolen_goods;
        target.getInventory().removeLastItem(stolen_goods); // No need to check for failure due to prior inventory checks
        inventory.addItem(stolen_goods);
    }

    return *this;
}