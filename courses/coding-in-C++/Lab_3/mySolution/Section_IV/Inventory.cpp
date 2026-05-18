/**
 * @file Inventory.cpp
 * @brief Implementation of the Inventory class
 */

#include "Inventory.hpp"

/**
 * @brief Constructor for inventories
 * @param size maximum number of items in the inventory
 */
Inventory::Inventory(int size) : maxSlots(size), filledSlots(0)
{}

/**
 * @brief check if inventory is empty
 * @return true if no items in inventory
 */
bool Inventory::isEmpty() const
{
    return filledSlots <= 0;
}

/**
 * @brief check if inventory is full
 * @return true if filledSlots equal maxSlots
 */
bool Inventory::isFull() const
{
    return filledSlots >= maxSlots;
}

/**
 * @brief add one item to inventory if not already full
 * @param item item name to add
 * @return true if successful
 */
bool Inventory::addItem(const std::string& item)
{
    if(isFull())
    {
        // Inventory already full
        return false;
    }

    filledSlots++;
    items.push_back(item);
    return true;
}

/**
 * @brief remove the last item in the inventory
 * @param[out] item removed item
 * @return true if successful
 */
bool Inventory::removeLastItem(std::string& item)
{
    if(isEmpty())
    {
        // Inventory already empty
        return false;
    }

    filledSlots--;
    item = items.back();
    items.pop_back();
    return true;
}

/**
 * @brief get inventory capacity
 * @return maximum amount of items allowed in inventory
 */
int Inventory::capacity() const
{
    return maxSlots;
}

/**
 * @brief get invertory fill level
 * @return amount of items in inventory
 */
int Inventory::fillLevel() const
{
    return filledSlots;
}