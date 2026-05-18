/**
 * @file Character.hpp
 * @brief class header for Character class
 */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "Inventory.hpp"
#include "Weapon.hpp"
//#include "Healer.hpp" // problematic: (Healer.hpp includes Mage.hpp which includes Character.hpp)
class Healer; // Pedefenition to avoid chicken and egg problem

/**
 * @class Character
 * @brief Abstract character class holding template for basic functionality
 */
class Character
{
friend class Healer;

private:
    int health;

protected:
    // Attributes
    const std::string name;
    int level;
    int xp;
    
    static constexpr int maxLevel = 10;
    static constexpr int xpLimit = 10; // Never set to 0

    // Associations
    Inventory inventory;
    Weapon* weapon;

public:
    /**
     * @brief Constructor for Character class
     * @param name character name
     * @param health base health
     * @param inventorySize starting inventory size
     * @param weapon starting weapon
     */
    Character(const std::string name, int health, int inventorySize, Weapon& weapon);

    /**
     * @brief prints relevant character info to console
     * @return reference to the character
     */
    virtual Character& display() = 0;

    /**
     * @brief regenerates class specific points (implemented in derived classes)
     * @param amount amount of points to regenerate
     * @return reference to the character
     */
    virtual Character& regeneratePoints(int amount) = 0;

    /**
     * @brief adds one to the characters level
     * @return reference to the character
     */
    Character& levelUp();

    /**
     * @brief adds some xp, when limit is reached, calls level up
     * @param xp amount of xp to add
     * @return reference to the character
     */
    Character& addXp(int xp);

    /**
     * @brief get reference to the characters Inventory
     * @return reference to character's inventory
     */
    Inventory& getInventory();

    /**
     * @brief get current health points
     * @return health
     */
    int getHealth() const;
};

#endif // CHARACTER_HPP