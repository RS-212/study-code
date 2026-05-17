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
private:
    int mana;

public:
    /**
     * @brief override of abstract display method in Character
     * @return reference to calling Mage
     */
    Mage& display() const override;

    /**
     * @brief regenerate mana points
     * @param amount amount of mana to regenerate
     * @return reference to calling Mage
     */
    Mage& regeneratePoints(int amount) override;
};

#endif // MAGE_HPP