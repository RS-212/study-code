/**
 * @file bank_account.cpp
 * 
 * @brief Learning how to use classes in C++
 */

#include <iostream>
#include <string>

/**
 * @class BankAccount
 * @brief Simple Bank account class for learning
 */
class BankAccount
{
    private:
        std::string owner;
        double balance;

    public:
        /**
         * @brief Sets new owner name
         * 
         * @param owner New owner name
         */
        void setOwner(std::string const& owner)
        {
            this->owner = owner;
        }

        /**
         * @brief Gets owner name
         * 
         * @return owner name
         */
        std::string getOwner() const
        {
            return owner;
        }

        /**
         * @brief Deposit amount to bankaccount (only positive numbers)
         * 
         * @param amount Amount to deposit
         */
        void deposit(double amount)
        {
            if (amount > 0)
            {
                balance += amount;
            }
        }

        /**
         * @brief Withdraw amount from account (checks available balance first)
         * 
         * @param amount Amount to withdraw
         */
        void withdraw(double amount)
        {
            if (amount > balance)
            {
                std::cout << "Not enough money in the account to withdraw " << amount << "€" << std::endl;
            }
            else
            {
                balance -= amount;
                std::cout << "Successfully withdrew " << amount << "€" << std::endl;
            }
        }

        double getBalance() const;
        void getAccountInfo() const;

};

/**
 * @brief Getter for balance attribute
 * 
 * @return value of balance
 */
double BankAccount::getBalance() const
{
    return this->balance;
}

/**
 * @brief Print owner and balance to console
 */
void BankAccount::getAccountInfo() const
{
    std::cout   << "Account Owner: " << getOwner()
                << "\nAvailable Balance: " << getBalance() << std::endl;
}

int main()
{
    // Problem with balance: No Constructor, Value not initialized: random data in variable
    BankAccount myAccount;

    myAccount.setOwner("Peter");
    myAccount.getAccountInfo(); // Will print out trash value in account

    myAccount.deposit(1234.5);
    myAccount.getAccountInfo(); // Why is the Value now 1234.5? I thought it was adding to the trash value :l

    myAccount.withdraw(999999);
    myAccount.getAccountInfo();

    myAccount.withdraw(200);
    myAccount.getAccountInfo();

    return 0;
}