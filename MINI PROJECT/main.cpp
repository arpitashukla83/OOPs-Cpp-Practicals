#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <iomanip>
using namespace std;

// Base class
class Account {
protected:
    int accountNumber;
    string name;
    double balance;

public:
    Account() {
        accountNumber = 0;
        name = "";
        balance = 0;
    }

    virtual void createAccount() {
        cout << "\nEnter Account Number: ";
        cin >> accountNumber;

        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Initial Balance: ";
        cin >> balance;

        if (balance < 0) {
            throw invalid_argument("Balance cannot be negative!");
        }

        cout << "\nAccount Created Successfully!\n";
    }

    void deposit() {
        double amount;

        cout << "Enter Deposit Amount: ";
        cin >> amount;

        if (amount <= 0) {
            throw invalid_argument("Invalid deposit amount!");
        }

        balance += amount;

        cout << "Money Deposited Successfully!\n";
    }

    virtual void withdraw() {
        double amount;

        cout << "Enter Withdrawal Amount: ";
        cin >> amount;

        if (amount <= 0) {
            throw invalid_argument("Invalid withdrawal amount!");
        }

        if (amount > balance) {
            throw runtime_error("Insufficient Balance!");
        }

        balance -= amount;

        cout << "Money Withdrawn Successfully!\n";
    }

    void checkBalance() {
        cout << "\nCurrent Balance: Rs. "
             << fixed << setprecision(2) << balance << endl;
    }

    void displayAccount() {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nCustomer Name: " << name;
        cout << "\nBalance: Rs. " << balance << endl;
    }

    void saveToFile() {
        ofstream file("bank.txt", ios::app);

        if (!file) {
            throw runtime_error("Unable to open file!");
        }

        file << accountNumber << "|"
             << name << "|"
             << balance << endl;

        file.close();
    }

    void readFromFile() {
        ifstream file("bank.txt");

        if (!file) {
            cout << "\nNo saved records found.\n";
            return;
        }

        int accNo;
        string customerName;
        double amount;

        cout << "\n======= SAVED ACCOUNTS =======\n";

        while (file >> accNo) {
            file.ignore();
            getline(file, customerName, '|');
            file >> amount;

            cout << "\nAccount Number: " << accNo;
            cout << "\nCustomer Name: " << customerName;
            cout << "\nBalance: Rs. " << amount << endl;
        }

        file.close();
    }

    virtual ~Account() {}
};

// Derived class
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount() {
        interestRate = 4.0;
    }

    void createAccount() override {
        Account::createAccount();

        cout << "Enter Interest Rate (%): ";
        cin >> interestRate;

        if (interestRate < 0) {
            throw invalid_argument("Invalid interest rate!");
        }

        saveToFile();
    }

    void calculateInterest() {
        double interest = balance * interestRate / 100;

        cout << "\nInterest Rate: " << interestRate << "%";
        cout << "\nInterest Amount: Rs. " << interest << endl;
    }
};

// Main function
int main() {
    SavingsAccount account;
    int choice;

    do {
        cout << "\n";
        cout << "===============================\n";
        cout << "    BANK MANAGEMENT SYSTEM    \n";
        cout << "===============================\n";

        cout << "1. Create Savings Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Display Account Details\n";
        cout << "6. Calculate Interest\n";
        cout << "7. View Saved Accounts\n";
        cout << "0. Exit\n";

        cout << "===============================\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        try {
            switch (choice) {

                case 1:
                    account.createAccount();
                    break;

                case 2:
                    account.deposit();
                    break;

                case 3:
                    account.withdraw();
                    break;

                case 4:
                    account.checkBalance();
                    break;

                case 5:
                    account.displayAccount();
                    break;

                case 6:
                    account.calculateInterest();
                    break;

                case 7:
                    account.readFromFile();
                    break;

                case 0:
                    cout << "\nThank You For Using Our Bank!\n";
                    break;

                default:
                    cout << "\nInvalid Choice!\n";
            }
        }
        catch (const exception& e) {
            cout << "\nError: " << e.what() << endl;
        }

    } while (choice != 0);

    return 0;
}
