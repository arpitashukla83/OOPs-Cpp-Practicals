
#include <iostream>
#include <string>
using namespace std;

// Base Exception Class
class BankException {
protected:
    string message;

public:
    BankException(const string &msg) : message(msg) {}

    string getMessage() const {
        return message;
    }
};

// Invalid Amount Exception
class InvalidAmountException : public BankException {
public:
    InvalidAmountException(double amount)
        : BankException("Invalid transaction amount: $" +
                        to_string(amount) +
                        ". Must be positive.") {}
};

// Insufficient Funds Exception
class InsufficientFundsException : public BankException {
public:
    InsufficientFundsException(double attempted, double balance)
        : BankException("Insufficient funds: Balance is $" +
                        to_string(balance) +
                        ", tried to withdraw $" +
                        to_string(attempted) + ".") {}
};

// Account Frozen Exception
class AccountFrozenException : public BankException {
public:
    AccountFrozenException(const string &accountId)
        : BankException("Transaction blocked: Account [" +
                        accountId +
                        "] is currently frozen.") {}
};

// Bank Account Class
class BankAccount {
private:
    string accountId;
    double balance;
    bool frozen;

public:
    BankAccount(string id, double bal)
        : accountId(id), balance(bal), frozen(false) {}

    void freezeAccount() {
        frozen = true;
    }

    void deposit(double amount) {
        if (frozen)
            throw AccountFrozenException(accountId);

        if (amount <= 0)
            throw InvalidAmountException(amount);

        balance += amount;

        cout << "Deposited $" << amount
             << ". New Balance: $" << balance << endl;
    }

    void withdraw(double amount) {
        if (frozen)
            throw AccountFrozenException(accountId);

        if (amount <= 0)
            throw InvalidAmountException(amount);

        if (amount > balance)
            throw InsufficientFundsException(amount, balance);

        balance -= amount;

        cout << "Withdrawn $" << amount
             << ". Balance: $" << balance << endl;
    }
};

// Main Function
int main() {
    BankAccount acc("ACC-9081", 500.00);

    // Deposit and Insufficient Funds Exception
    try {
        acc.deposit(200.00);
        acc.withdraw(1000.00);
    }
    catch (const InsufficientFundsException &e) {
        cout << "[Funds Error] " << e.getMessage() << endl;
    }
    catch (const BankException &e) {
        cout << "[Bank Error] " << e.getMessage() << endl;
    }

    // Invalid Amount Exception
    try {
        acc.deposit(-50.00);
    }
    catch (const InvalidAmountException &e) {
        cout << "[Amount Error] " << e.getMessage() << endl;
    }

    // Account Frozen Exception
    try {
        acc.freezeAccount();
        acc.withdraw(100.00);
    }
    catch (const AccountFrozenException &e) {
        cout << "[Security Error] " << e.getMessage() << endl;
    }

    return 0;
}
