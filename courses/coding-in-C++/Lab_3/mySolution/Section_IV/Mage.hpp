/**
 * @file Mage.hpp
 * @brief class header for Mage class
 */

#ifndef MAGE_HPP
#define MAGE_HPP

#include "Character.hpp"

/**
 * @class Mage
 * @brief Special Character with magic abilities
 */
class Mage : public Character
{
protected:
    int mana;

public:
    /**
     * @brief Constructor for Mages
     * @param name character name
     * @param health base health
     * @param inventory starting inventory
     * @param weapon starting weapon
     */
    Mage(const std::string name, int health, const Inventory& inventory, Weapon& weapon);

    /**
     * @brief override of abstract display method in Character
     * @return reference to calling Mage
     */
    Mage& display() override;

    /**
     * @brief regenerate mana points
     * @param amount amount of mana to regenerate
     * @return reference to calling Mage
     */
    Mage& regeneratePoints(int amount) override;
};

#endif // MAGE_HPP