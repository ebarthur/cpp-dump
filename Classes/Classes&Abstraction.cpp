#include <iostream>
#include <string>


using namespace std;

class BankAccount {
private:
    static int nextAccountNumber;
    string accountHolderName;
    int accountNumber;
    string accountType;
    double balance;
    double interestRate;

public:
    BankAccount(const string& name, const string& type, double initialBalance, double rate)
        : accountHolderName(name), accountType(type), balance(initialBalance), interestRate(rate) {
        accountNumber = nextAccountNumber++;
    }

    ~BankAccount() {
        cout << "Account " << accountNumber << " for " << accountHolderName << " has been closed.\n";
    }

    void displayBalance() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Interest Rate: " << interestRate << endl;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit of $" << amount << " successful." << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal of $" << amount << " successful." << endl;
        } else {
            cout << "Insufficient funds for withdrawal." << endl;
        }
    }

    void transfer(BankAccount& destination, double amount) {
        if (amount <= balance) {
            balance -= amount;
            destination.deposit(amount);
            cout << "Transfer of $" << amount << " successful." << endl;
        } else {
            cout << "Insufficient funds for transfer." << endl;
        }
    }
};

int BankAccount::nextAccountNumber = 1000;

int main() {
    BankAccount* bankAccounts[10];

    bankAccounts[0] = new BankAccount("Vannessa Baby", "checking", 1000.0, 0.02);
    bankAccounts[1] = new BankAccount("Vanessa Ayertey", "saving", 5000.0, 0.03);

    bankAccounts[0]->displayBalance();
    bankAccounts[1]->displayBalance();

    bankAccounts[0]->deposit(500.0);
    bankAccounts[1]->withdraw(1000.0);
    bankAccounts[0]->transfer(*bankAccounts[1], 200.0);

    bankAccounts[0]->displayBalance();
    bankAccounts[1]->displayBalance();

    delete bankAccounts[0];
    delete bankAccounts[1];

    return 0;
}
