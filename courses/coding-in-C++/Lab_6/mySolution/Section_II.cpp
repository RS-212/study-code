
#include <iostream>
#include <string>
#include <stdexcept>

class Sensor
{
private:
    std::string name;
    double value;
    const double min_value;
    const double max_value;

public:
    Sensor(std::string name, double initial_value, double min_value, double max_value)
    : name(name), min_value(min_value), max_value(max_value)
    {
        if (initial_value < min_value)
        {
            throw std::invalid_argument("Value too small! Could not initialize!");   
        }
        else if (initial_value > max_value)
        {
            throw std::invalid_argument("Value too large! Could not initialize!");
        }

        this->value = initial_value;
    }

    void update_value(double value)
    {
        if (value < min_value)
        {
            throw std::out_of_range("Value too small! Could not override!");
        }
        else if (value > max_value)
        {
            throw std::out_of_range("Value too large! Could not override!");
        }
        this->value = value;
    }

    double get_value()
    {
        return this->value;
    }

    void print_info()
    {
        std::cout << "Sensor name: " << this->name
                << "\nCurrent value: " << get_value()
                << "\nValid values from '" << this->min_value << "' to '" << this->max_value
                << "'\n" << std::endl;
    }
};


int main()
{
    // Value constraints
    // Humidity:
    constexpr double MIN_HUMIDITY = 0.0;
    constexpr double MAX_HUMIDITY = 100.0;
    // Temperature:
    constexpr double MIN_TEMPERATURE = -273.15;
    constexpr double MAX_TEMPERATURE = 999.9;
    // Water Level:
    constexpr double MIN_WATER_LEVEL = 0.0;
    constexpr double MAX_WATER_LEVEL = 5.0;


    // Testing three sensors
    try
    {
        Sensor humidity("Humidity Sensor", -1.0, MIN_HUMIDITY, MAX_HUMIDITY);

        humidity.print_info();
    }
    catch(const std::exception& error)
    {
        std::cout << "Error: " << error.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "Unknown error!" << std::endl;
    }

    try
    {
        Sensor temperature("Temperature Sensor", 5000, MIN_TEMPERATURE, MAX_TEMPERATURE);

        temperature.print_info();
    }
    catch(const std::exception& error)
    {
        std::cout << "Error: " << error.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "Unknown error!" << std::endl;
    }

    try
    {
        Sensor water_level("Water level Sensor", 0.0, MIN_WATER_LEVEL, MAX_WATER_LEVEL);

        water_level.print_info();

        water_level.update_value(-5);
    }
    catch(const std::exception& error)
    {
        std::cout << "Error: " << error.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "Unknown error!" << std::endl;
    }

    return 0;
}