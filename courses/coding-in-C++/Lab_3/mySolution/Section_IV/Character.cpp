/**
 * @file Character.cpp
 * @brief Implementation of the Character class
 */

#include "Character.hpp"

/**
 * @brief Constructor for Character class
 * @param name character name
 * @param health base health
 * @param inventorySize starting inventory size
 * @param weapon starting weapon
 */
Character::Character(const std::string name, int health, int inventorySize, Weapon& weapon)
: name(name), level(1), xp(0), inventory(Inventory(inventorySize)), weapon(&weapon)
{
    // Input sanitation for negative health values
    constexpr int DEFAULT_HEALTH = 100;

    if(health < 0)
    {
        health = DEFAULT_HEALTH;
    }
    this->health = health;
}

/**
 * @brief adds one to the characters level
 * @return reference to the character
 */
Character& Character::levelUp()
{
    level++;
    if (level > maxLevel)
    {
        level = maxLevel;
    }
    return *this;
}

/**
 * @brief adds some xp, when limit is reached, calls level up
 * @param xp amount of xp to add
 * @return reference to the character
 */
Character& Character::addXp(int xp)
{
    // No negative values allowed
    if(xp < 0)
    {
        return *this;
    }

    // Level up more than once when enough xp are added
    int levels = (this->xp + xp) / xpLimit;
    this->xp = (this->xp + xp) % xpLimit;

    for (int i = 0; i < levels; i++)
    {
        levelUp();
    }
    return *this;
}

/**
 * @brief get reference to the characters Inventory
 * @return reference to character's inventory
 */
Inventory& Character::getInventory()
{
    return this->inventory;
}

/**
 * @brief get current health points
 * @return health
 */
int Character::getHealth() const
{
    return health;
}