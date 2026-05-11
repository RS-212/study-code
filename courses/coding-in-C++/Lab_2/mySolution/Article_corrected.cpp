/**
 * @file Article_corrected.cpp
 * @brief correct mistakes made in the exaple
 */

#include <iostream>
#include <string>

/**
 * @class Article
 * @brief Class to manage articles of an online shop
 */
class Article {
private:
    std::string name;
    double price;
    int stock;
    std::string category;
    int id;

public:
    /**
     * @brief Constructs article object
     * @param name article name
     * @param price article base price
     * @param stock number of articles of this type in stock
     * @param category category of the article
     * @param id unique id of the article
     */
    Article(const std::string& p_name, double p_price, int p_stock, const std::string& p_category, int p_id)
    : name(p_name), price(p_price), stock(p_stock), category(p_category), id(p_id)
    {

    }

    /**
     * @brief sets price of article to a positive value
     * @param price new price
     */
    void setPrice(double price)
    {
        if (price < 0)
        {
            std::cout << "Invalid price!" << std::endl;
            return;
        }
        this->price = price;
    }

    /**
     * @brief decrease stock of Article
     * @param amount number of items to sell
     */
    void sell(int amount)
    {
        if (amount < 0 || stock < amount)
        {
            std::cout << "Invalid amount!" << std::endl;
            return;
        }
        stock -= amount;
    }

    /**
     * @brief increase stock of Article
     * @param amount number of items to restock
     */
    void restock(int amount)
    {
        if (amount < 0)
        {
            std::cout << "Invalid amount!" << std::endl;
            return;
        }
        this->stock += amount;
    }

    /**
     * @brief get discounted price
     * @param percent discount percentage
     * @return discounted price
     */
    double applyDiscount(double percent)
    {
        if (percent < 0 || percent > 100)
        {
            return price - price * percent / 100;
        }
        return price;
    }

    /**
     * @brief get articles price
     * @return price
     */
    double getPrice() const
    {
        return price;
    }

    /**
     * @brief check if item is in stock
     * @return true if in stock, false otherwise
     */
    bool isAvailable() const
    {
        return (stock > 0);
    }

    /**
     * @brief prints relevant data to console
     */
    void printInfo() const
    {
        std::cout << "Article: " << name << std::endl;
        std::cout << "Category: " << category << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "Stock: " << stock << std::endl;
        std::cout << "ID: " << id << std::endl;
    }
};

int main() {
    // Create Article Instance laptop
    const double price_laptop = 999.99;
    const int stock_laptop = 10;
    const int id_laptop = 101;

    Article laptop("Laptop", price_laptop, stock_laptop, "Electronics", id_laptop);

    // Test edge cases
    laptop.sell(15);
    laptop.restock(-5);
    laptop.setPrice(-100);
    laptop.applyDiscount(150);

    if (laptop.isAvailable())
    {
        std::cout << "Article available" << std::endl;
    }

    // Print relevant info to console
    laptop.printInfo();
}