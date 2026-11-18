#include <iostream>
using namespace std;
 
class BankAccount {
private:
    int accNo;
    double balance;
 
protected:
    int getAccNo() {
        return accNo;
    }
 
public:
    BankAccount() {
        accNo = 101;
        balance = 1000.00;
    }
 
    void displayDetails() {
        cout << "Bank Account Details" << endl;
        cout << "Account Number: " << accNo << endl;
        cout << "Balance: " << balance << endl;
    }
};
 
class SavingsAccount : public BankAccount {
public:
    void showDetails() {
        displayDetails();
        cout << "Account Number using protected function: "
             << getAccNo() << endl;
    }
};
 
int main() {
    SavingsAccount account;
    account.showDetails();
 
    return 0;
}
