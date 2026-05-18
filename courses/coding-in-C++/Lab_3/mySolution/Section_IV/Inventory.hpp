/**
 * @file Inventory.hpp
 * @brief class header for Inventory class
 */

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <string>
#include <vector>

/**
 * @class Inventory
 * @brief Represents an inventory with limited slots
 */
class Inventory
{
private:
    // Attributes
    const int maxSlots;
    int filledSlots;
    std::vector<std::string> items;

public:
    /**
     * @brief Constructor for inventories
     * @param size maximum number of items in the inventory
     */
    Inventory(int size);

    /**
     * @brief check if inventory is empty
     * @return true if no items in inventory
     */
    bool isEmpty() const;

    /**
     * @brief check if inventory is full
     * @return true if filledSlots equal maxSlots
     */
    bool isFull() const;

    /**
     * @brief add one item to inventory if not already full
     * @param item item name to add
     * @return true if successful
     */
    bool addItem(const std::string& item);

    /**
     * @brief remove the last item in the inventory
     * @param[out] item removed item
     * @return true if successful
     */
    bool removeLastItem(std::string& item);

    /**
     * @brief get inventory capacity
     * @return maximum amount of items allowed in inventory
     */
    int capacity() const;

    /**
     * @brief get invertory fill level
     * @return amount of items in inventory
     */
    int fillLevel() const;

};

#endif // INVENTORY_HPP