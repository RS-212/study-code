
#include <iostream>
#include <string>
#include <stdexcept>

class SensorFailureError : public std::runtime_error
{
public:
    SensorFailureError(const std::string& error) : std::runtime_error(error) {}
};

class Sensor
{
private:
    std::string name;
    double value;
    const double min_value;
    const double max_value;

public:
    Sensor(std::string name, double initial_value, double min_value, double max_value);

    void update_value(double value);

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

    void simulate_failure() const
    {
        throw SensorFailureError("Simulated error in '" + this->name + "'");
    }
};

Sensor::Sensor(std::string name, double initial_value, double min_value, double max_value)
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

void Sensor::update_value(double value)
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
        Sensor humidity("Humidity Sensor", 0.0, MIN_HUMIDITY, MAX_HUMIDITY);
        Sensor temperature("Temperature Sensor", 0.0, MIN_TEMPERATURE, MAX_TEMPERATURE);
        Sensor water_level("Water level Sensor", 0.0, MIN_WATER_LEVEL, MAX_WATER_LEVEL);

        humidity.print_info();
        temperature.print_info();
        water_level.print_info();

        humidity.simulate_failure();
    }
    catch(const SensorFailureError& error)
    {
        std::cout << "Sensor Failure!\n" << error.what() << std::endl;
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