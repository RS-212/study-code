// 22. Missing file header
#include <iostream>
#include <string>
// 21. iomanip is never used
#include <iomanip>
// 1. The using keyword should be avoided. Use scope operator instead
using namespace std;

class Article {
// 2. Public attributes are bad practice! Use getters and setters instead
// only expose if necessary
public:
    string name;
    double price;
    int stock;
    string* category;
    int id;

    // 3. Strings should be const references, as they are large objects
    Article(string name, double price, int stock, string category, int id) {
        // 4. For simple iinitialization initializer Lists should be used.
        // 5. Missing this pointer, the values will not be initialized.
        name = name;
        price = price;
        stock = stock;
        this->id = id;
        this->category = new string;
        *this->category = category;
    }
    // 20. Missing destructor to free category :(
    // It wasn't necessary to use dynamic memory in the first place...

    void setPrice(double price) {
        // 6. Missing this operator again
        // 7. Also no Input checking
        price = price;
    }

    void sell(int amount) {
        // 8. No checks if stock is sufficient. Why even write a setter at all...
        stock = stock - amount;
    }

    void restock(int amount) {
        // 9. No check if amount is positive
        this->stock += amount;
    }

    double applyDiscount(double percent) {
        // 10. original price is modified! Non discounted price is lost.
        // 11. No checking if percent is between 0 and 100
        price = price - price * percent / 100;
        return price;
    }

    // 12. non modifying function not marked as const
    double getPrice() {
        return price;
    }

    // 14. Same as 12
    bool isAvailable() {
        // 15. Unnecessary control structure. Return the boolean expression directly
        if (stock > 0)
        // 16. Missing curly braces for if and else
            return true;
        else
            return false;
    }

    // 15. missing const again
    void printInfo() {
        cout << "Article: " << name << endl;
        cout << "Category: " << *category << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
        cout << "ID: " << id << endl;
    }
};

// 16. In general: no comments on functions and behavior!
// Actually no comments at all...

int main() {
    // 17. ambiguous name a -> change to something discriptive
    Article a("Laptop", 999.99, 10, "Electronics", 101);

    // 18. Exploiting the missing checks mentioned earlier.
    a.sell(15); 
    a.restock(-5);
    a.price = -100;
    a.applyDiscount(150);

    // 19. Same as 16
    if (a.isAvailable()) cout << "Article available" << endl;

    a.printInfo();
}