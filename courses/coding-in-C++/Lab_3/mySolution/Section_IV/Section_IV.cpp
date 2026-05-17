/**
 * @file Section_IV.cpp
 * @brief Contains main method of a Game Character system
 * 
 * The Game charakter system is used to practice inheritance and UML modelling
 */

/**
 * Answers to questions:
 * 
 * Friend is used to enable Healers to directly modify the health attribute.
 * The benefit is, that only Healers can modify health. There are no public
 * setters that enable modifying for other classes. Using friend avoids
 * implementing complex authentication logic.
 * 
 * Stealing uses public methods, because managing an Inventory requires more
 * complex logic. This logic is implemented in the Invernory's interface (its
 * public methods)
 * Also using direct access to inventory data would allow others to see the
 * contents of the inverntory. Thiefs should not see what they are stealing.
 * 
 * 
 * friend class:
 * - direct read and write access
 * - limited to friend class
 * - more freedom (more errors)
 * 
 * public interface:
 * - everyone can access
 * - can limit read or write
 * - input sanitizing
 * - more control (less freedom and errors)
 */

#include <iostream>
#include <string>
#include "Character.hpp"

int main()
{
    std::cout << "Joa." << std::endl;
    return 0;
}