#include <iostream>
#include <string>

using namespace std;

// Base class representing a generic bank account
class BankAccount {
protected:
    int accountNumber;
    double balance;

public:
    // Constructor to initialize a BankAccount with an account number and initial balance
    BankAccount(int accNumber, double initBalance)
        : accountNumber(accNumber), balance(initBalance) {}

    // Getter method to retrieve the account number
    int getAccountNumber() const {
        return accountNumber;
    }

    // Getter method to retrieve the account balance
    double getBalance() const {
        return balance;
    }

    // Method to deposit funds into the account
    void deposit(double amount) {
        balance += amount;
    }

    // Method to withdraw funds from the account, with error handling for insufficient funds
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds. Withdrawal failed.\n";
        }
    }

    // Method to print basic account information
    void printInfo() const {
        cout << "Account Number: " << accountNumber << "\nBalance: $" << balance << "\n";
    }
};

// Derived class representing a checking account, inheriting from BankAccount
class CheckingAccount : public BankAccount {
private:
    double interestRate;
    double minimumBalance;
    double serviceCharges;

public:
    // Constructor to initialize a CheckingAccount with additional parameters
    CheckingAccount(int accNumber, double initBalance, double intRate, double minBalance, double charges)
        : BankAccount(accNumber, initBalance), interestRate(intRate), minimumBalance(minBalance), serviceCharges(charges) {}

    // Setter method to set the interest rate
    void setInterestRate(double rate) {
        interestRate = rate;
    }

    // Getter method to retrieve the interest rate
    double getInterestRate() const {
        return interestRate;
    }

    // Setter method to set the minimum balance
    void setMinimumBalance(double minBalance) {
        minimumBalance = minBalance;
    }

    // Getter method to retrieve the minimum balance
    double getMinimumBalance() const {
        return minimumBalance;
    }

    // Setter method to set the service charges
    void setServiceCharges(double charges) {
        serviceCharges = charges;
    }

    // Getter method to retrieve the service charges
    double getServiceCharges() const {
        return serviceCharges;
    }

    // Method to apply interest to the account balance
    void postInterest() {
        deposit(getBalance() * interestRate);
    }

    // Method to check if the account balance is below the minimum balance
    bool isBelowMinimumBalance() const {
        return getBalance() < minimumBalance;
    }

    // Method to write a check (withdraw funds), applying service charges if necessary
    void writeCheck(double amount) {
        withdraw(amount);
    }

    // Overridden method to withdraw funds, applying service charges if necessary
    void withdraw(double amount) {
        BankAccount::withdraw(amount);
        if (isBelowMinimumBalance()) {
            balance -= serviceCharges;
            cout << "Service charges applied. New balance: $" << getBalance() << "\n";
        }
    }

    // Overridden method to print detailed account information
    void printInfo() const {
        BankAccount::printInfo();
        cout << "Interest Rate: " << interestRate << "\nMinimum Balance: $" << minimumBalance << "\nService Charges: $" << serviceCharges << "\n";
    }
};

// Derived class representing a savings account, inheriting from BankAccount
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    // Constructor to initialize a SavingsAccount with additional parameters
    SavingsAccount(int accNumber, double initBalance, double intRate)
        : BankAccount(accNumber, initBalance), interestRate(intRate) {}

    // Setter method to set the interest rate
    void setInterestRate(double rate) {
        interestRate = rate;
    }

    // Getter method to retrieve the interest rate
    double getInterestRate() const {
        return interestRate;
    }

    // Method to apply interest to the account balance
    void postInterest() {
        deposit(getBalance() * interestRate);
    }

    // Overridden method to withdraw funds
    void withdraw(double amount) {
        BankAccount::withdraw(amount);
    }

    // Overridden method to print detailed account information
    void printInfo() const {
        BankAccount::printInfo();
        cout << "Interest Rate: " << interestRate << "\n";
    }
};

// Main function for testing the BankAccount hierarchy
int main() {
    // Create instances of CheckingAccount and SavingsAccount
    CheckingAccount checking(101, 1000.0, 0.02, 500.0, 10.0);
    SavingsAccount savings(201, 2000.0, 0.015);

    // Perform transactions and display account information
    checking.deposit(500.0);
    checking.withdraw(200.0);
    checking.postInterest();
    checking.printInfo();

    savings.deposit(1000.0);
    savings.withdraw(300.0);
    savings.postInterest();
    savings.printInfo();

    return 0;
}
