/**
 * @file DrinkBuilder.cpp
 * @brief Using method chaining to configure a drink
 */

#include <iostream>
#include <string>

/**
 * @class DrinkBuilder
 * @brief basic method chaining drink configuration
 */
class DrinkBuilder
{
private:
    std::string name;
    int sugar;
    int temperature;
    bool withMilk;

    // constexpr default values (must be static)
    static constexpr int default_temp = 50;
    static constexpr int max_sugar = 10;

public:
    /**
     * @brief default contructor. Initializes temp to defualt value
     */
    DrinkBuilder() : name(""), sugar(0), temperature(default_temp), withMilk(false)
    {

    }

    /**
     * @brief set name of drink
     * @param[in] name const reference to new name
     * @return reference to current object
     */
    DrinkBuilder& setName(const std::string& name)
    {
        this->name = name;
        return *this;
    }

    /**
     * @brief set sugar level. cap at max value
     * @param[in] sugar amount of sugar to set
     * @return reference to current object
     */
    DrinkBuilder& setSugar(int sugar)
    {
        if (sugar > max_sugar)
        {
            sugar = max_sugar;
        }
        if (sugar < 0)
        {
            sugar = 0;
        }

        this->sugar = sugar;
        
        return *this;
    }

    /**
     * @brief set temperature to desired temp
     * @param[in] temperature new temperature
     * @return reference to current object
     */
    DrinkBuilder& setTemperature(int temperature)
    {
        if (temperature < 0)
        {
            temperature = 0;
        }
        this->temperature = temperature;
        return *this;
    }

    /**
     * @brief modify milkyness
     * @param[in] withMilk new milk state
     * @return reference to current object
     */
    DrinkBuilder& setWithMilk(bool withMilk)
    {
        this->withMilk = withMilk;
        return *this;
    }

    /**
     * @brief output all current values to console
     * @return reference to current object
     */
    DrinkBuilder& print()
    {
        std::cout   << "Drink name: " << this->name
                    << "\nSugar level: " << this->sugar
                    << "\nTemperature: " << this->temperature
                    << "\nWith milk?: " << ((this->withMilk) ? "true" : "false") << std::endl;
        
        return *this;
    }

    /**
     * @brief checks if drink config is valid
     * @return true if valid, false if not
     */
    bool isValid() const
    {
        // Is temperature negative?
        if (temperature < 0)
        {
            return 0;
        }
        // Is sugar value negative?
        if (sugar < 0)
        {
            return 0;
        }
        // Is name empty?
        if (name == "")
        {
            return 0;
        }

        // All chekcs passed
        return 1;
    }
};

int main()
{
    DrinkBuilder builder;
    builder.setName("Tea")
        .setSugar(2)
        .setTemperature(65)
        .setWithMilk(true)
        .print();

    return 0;
}