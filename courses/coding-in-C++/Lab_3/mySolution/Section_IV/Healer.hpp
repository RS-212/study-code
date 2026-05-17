/**
 * @file Healer.hpp
 * @brief class header for Healer
 */

#ifndef HEALER_HPP
#define HEALER_HPP

#include "Mage.hpp"

/**
 * @class Healer
 * @brief Special Mage with healing abilities (friend of Character)
 */
class Healer : public Mage
{
private:
    int healStrength;

public:
    /**
     * @brief heals specified target, taking into account the healers strength
     * @param target Character to heal
     * @return reference to healer
     */
    Healer& heal(const Character& target);
};

#endif // HEALER_HPP