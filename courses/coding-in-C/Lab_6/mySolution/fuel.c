/**
 * @file fuel.c
 * 
 * @brief Simple struct excercise
 * 
 * Excercise to use a Struct to save fuel level of a car and refuel it
 * 
 */

#include <stdio.h>
#include <string.h>

struct Car
{
    float fuel_level;
    float max_fuel_level;
    char model[100];
};

/**
 * @brief refuels a car
 * 
 * @param[out] car Instance of Car to refuel
 * @param[in] amount Amount of fuel to add to the car
 * 
 * @return 1 if successful, 0 if unsuccessful
 */
int refuel(struct Car *car, float amount)
{
    float new_fuel_level = car->fuel_level + amount;
    if (new_fuel_level > car->max_fuel_level)
    {
        printf("Failed to refuel, too much fuel!\n");
        return 0;
    }
    printf("Refueling...\n");
    car->fuel_level = new_fuel_level;
    return 1;
}

int main()
{
    // Declare and initialize car
    struct Car porsche;
    porsche.fuel_level = 10.0;
    porsche.max_fuel_level = 100.0;
    strcpy(porsche.model, "992 Targa");

    printf("Initial fuel level: %f\n", porsche.fuel_level);

    refuel(&porsche, 12.7);

    printf("Fuel level after refueling: %f\n", porsche.fuel_level);

    return 0;
}
