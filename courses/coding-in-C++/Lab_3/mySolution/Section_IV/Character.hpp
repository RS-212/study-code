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
 * @brief Abstract charakter class holding template for basic functionality
 */
class Character
{
friend class Healer;

private:
    // Attributes
    const std::string name;
    int health;
    int level;
    int xp;
    static constexpr int xpLimit = 10;

    // Associations
    Inventory inventory;
    Weapon* weapon;

public:
    /**
     * @brief prints relevant character info to console
     * @return reference to the character
     */
    virtual Character& display() const = 0;

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
     * @return reference to characters invernotry
     */
    Inventory& getInventory();
};

#endif // CHARACTER_HPP