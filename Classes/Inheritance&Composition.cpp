#include <iostream>
#include <string>

using namespace std;

class BankAccount {
protected:
    int accountNumber;
    double balance;

public:
    BankAccount(int accNumber, double initBalance)
        : accountNumber(accNumber), balance(initBalance) {}

    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds. Withdrawal failed.\n";
        }
    }

    void printInfo() const {
        cout << "Account Number: " << accountNumber << "\nBalance: $" << balance << "\n";
    }
};

class CheckingAccount : public BankAccount {
private:
    double interestRate;
    double minimumBalance;
    double serviceCharges;

public:
    CheckingAccount(int accNumber, double initBalance, double intRate, double minBalance, double charges)
        : BankAccount(accNumber, initBalance), interestRate(intRate), minimumBalance(minBalance), serviceCharges(charges) {}

    void setInterestRate(double rate) {
        interestRate = rate;
    }

    double getInterestRate() const {
        return interestRate;
    }

    void setMinimumBalance(double minBalance) {
        minimumBalance = minBalance;
    }

    double getMinimumBalance() const {
        return minimumBalance;
    }

    void setServiceCharges(double charges) {
        serviceCharges = charges;
    }

    double getServiceCharges() const {
        return serviceCharges;
    }

    void postInterest() {
        deposit(getBalance() * interestRate);
    }

    bool isBelowMinimumBalance() const {
        return getBalance() < minimumBalance;
    }

    void writeCheck(double amount) {
        withdraw(amount);
    }

    void withdraw(double amount) {
        BankAccount::withdraw(amount);
        if (isBelowMinimumBalance()) {
            balance -= serviceCharges;
            cout << "Service charges applied. New balance: $" << getBalance() << "\n";
        }
    }

    void printInfo() const {
        BankAccount::printInfo();
        cout << "Interest Rate: " << interestRate << "\nMinimum Balance: $" << minimumBalance << "\nService Charges: $" << serviceCharges << "\n";
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(int accNumber, double initBalance, double intRate)
        : BankAccount(accNumber, initBalance), interestRate(intRate) {}

    void setInterestRate(double rate) {
        interestRate = rate;
    }

    double getInterestRate() const {
        return interestRate;
    }

    void postInterest() {
        deposit(getBalance() * interestRate);
    }

    void withdraw(double amount) {
        BankAccount::withdraw(amount);
    }

    void printInfo() const {
        BankAccount::printInfo();
        cout << "Interest Rate: " << interestRate << "\n";
    }
};

int main() {
    CheckingAccount checking(101, 1000.0, 0.02, 500.0, 10.0);
    SavingsAccount savings(201, 2000.0, 0.015);

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
