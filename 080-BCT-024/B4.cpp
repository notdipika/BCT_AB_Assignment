#include <iostream>
using namespace std;

// Base class
class Account
{
protected:
    int accountNumber;
    double balance;

public:
    Account(int accNum, double bal) : accountNumber(accNum), balance(bal) {}

    virtual void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited " << amount << " in Account " << accountNumber << ". Balance: " << balance << endl;
    }

    virtual void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrew " << amount << " from Account " << accountNumber << ". Balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }

    virtual void displayBalance() const
    {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }

    virtual ~Account() {} // Virtual destructor
};

// Derived class for SavingAccount
class SavingAccount : public Account
{
private:
    double interestRate;

public:
    SavingAccount(int accNum, double bal, double rate)
        : Account(accNum, bal), interestRate(rate) {}

    void deposit(double amount) override
    {
        double interest = amount * interestRate;
        balance += amount + interest;
        cout << "Deposited " << amount << " + Interest " << interest << " in SavingAccount "
             << accountNumber << ". Balance: " << balance << endl;
    }

    void withdraw(double amount) override
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrew " << amount << " from SavingAccount " << accountNumber
                 << ". Balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient balance in SavingAccount!" << endl;
        }
    }
};

// Derived class for CheckingAccount
class CheckingAccount : public Account
{
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNum, double bal, double overdraft)
        : Account(accNum, bal), overdraftLimit(overdraft) {}

    void withdraw(double amount) override
    {
        if (amount <= balance + overdraftLimit)
        {
            balance -= amount;
            cout << "Withdrew " << amount << " from CheckingAccount " << accountNumber
                 << ". Balance: " << balance << endl;
        }
        else
        {
            cout << "Overdraft limit exceeded!" << endl;
        }
    }
};

int main()
{
    // Base class pointer
    Account *acc;

    // Pointing to SavingAccount object
    cout << "----SAVING ACCOUNT-----\n";
    acc = new SavingAccount(101, 1000.0, 0.03);
    acc->deposit(500);
    cout << "\n";
    acc->withdraw(200);
    cout << "\n";
    acc->displayBalance();
    delete acc; // Clean up
    cout << "\n";

    // Pointing to CheckingAccount object
    cout << "----CHECKING ACCOUNT-----\n";
    acc = new CheckingAccount(102, 1000.0, 500.0);
    cout << "\n";
    acc->deposit(300);
    cout << "\n";
    acc->withdraw(1500);
    cout << "\n";
    acc->displayBalance();
    delete acc; // Clean up
    cout << "\n";

    return 0;
}
