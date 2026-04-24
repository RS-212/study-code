#include <cstdint>
#include <iostream>
#include <limits>

namespace validation
{
    const std::uint8_t ADULT_LIMIT = 18;
    const std::uint8_t SENIOR_LIMIT = 65;

    /**
     * @brief checks if given age is considered adult
     * 
     * @param[in] age age value to evaluate
     * @return true if age is at least ADULT_LIMIT, otherwise false
     */
    bool isAdult(std::uint8_t age)
    {
        return age >= ADULT_LIMIT;
    }

    /**
     * @brief checks if given age is considered senior
     * 
     * @param[in] age age value to evaluate
     * @return true if age is at least SENIOR_LIMIT, otherwise false
     */
    bool isSenior(std::uint8_t age)
    {
        return age >= SENIOR_LIMIT;
    }

}


// === Function Declarations ===

int getAgeFromUser();


// === Main Function ===

int main()
{
    // Read age from user and echo to confirm
    //uint8_t age = getAgeFromUser();  // Problematic, because uint8_t is interpreted as a char! -> see more in getAgeFromUser()
    int age = getAgeFromUser();  // Returns only valid ages
    std::uint8_t ageToValidate = static_cast<std::uint8_t>(age);

    std::cout << "Your age is: " << age << std::endl;

    // Age specific outputs
    std::cout << "This means you are ";
    if (validation::isSenior(ageToValidate))
    {
        std::cout << "a senior citizen.";
    }
    else if (validation::isAdult(ageToValidate))
    {
        std::cout << "an adult.";
    }
    else
    {
        std::cout << "not of age yet";
    }
    std::cout << std::endl;

    return 0;
}


// === Function Implementations ===

/**
 * @brief Prompts the user to input an age. In case of invalid entry: Repeats until valid entry.
 * 
 * @return valid age from user input
 */
int getAgeFromUser()
{
    const uint8_t MIN_AGE = 0;
    const uint8_t MAX_AGE = 150;

    //std::uint8_t ageFromUser = MIN_AGE;  // Problematic, because it reads the age as a char!
    /**
     * Other possible portable data types include:
     * std::uint16_t, std::uint32_t -> uses more storage
     * std::least_uint16_t, std::least_uint32_t -> ensures a minimum of the specified space
     * std::fast_uint16_t, std::fast_uint32_t -> uses the size which can be processed the fastest by the cpu, sacrificing space for speed
    */
    int ageFromUser = MIN_AGE;


    while (true)
    {
        std::cout << "Please enter your age: " << std::flush;

        // Clear input buffer in case of an earlier invalid entry
        if (std::cin.fail())
        {
            std::cin.clear();  // Clear fail bit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // clear entire input stream
        }

        // Read user input and check for validity
        if (!(std::cin >> ageFromUser))
        {
            std::cout << "The value you entered is not a number. Please try again:\n";
            continue;
        }

        // Check if age is in plausible range
        if (ageFromUser < MIN_AGE || ageFromUser > MAX_AGE)
        {
            std::cout << "The age you entered is not in a plausible range. Please try again:\n";
            continue;
        }

        // All checks passed, exit loop
        break;
    }
    return ageFromUser;
}