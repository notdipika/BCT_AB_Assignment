#include <iostream>

using namespace std;

class Account
{
protected:
    int accountNumber;
    float balance = 0;

public:
    virtual void deposit() = 0;
    virtual void withdraw() = 0;
    virtual void DisplayBalance() = 0;
    virtual void InterestRates() {};
};

class SavingsAccount : public Account
{
private:
    float Irates[4] = {0.01, 0.035, 0.068, 0.115};
    float interestRate;
    int period;

public:
    void deposit()
    {
        cout << "Enter amount to deposit: ";
        float amount;
        cin >> amount;
        cout << "Enter Years: ";
        cin >> period;

        if (period == 1)
        {
            interestRate = Irates[0];
            balance += (amount + (amount * interestRate *1));
        }
        else if (period == 3)
        {
            interestRate = Irates[1];
            balance += (amount + (amount * interestRate * 3));
        }
        else if (period == 6)
        {
            interestRate = Irates[2];
            balance += (amount + (amount * interestRate * 6));
        }
        else if (period == 10)
        {
            interestRate = Irates[3];
            balance += (amount + (amount * interestRate * 10));
        }
        else
        {
            cout << "Invalid period!" << endl;
            return;
        }

        cout << "Amount deposited successfully!" << endl;
    }

    void InterestRates()
    {
        cout << "\tYears\t" << "Interest" << endl;
        cout << "\t" << "1" << "\t" << "0.01 or 1%" << endl;
        cout << "\t" << "3" << "\t" << "0.035 or 3.5%" << endl;
        cout << "\t" << "6" << "\t" << "0.068 or 6.8%" << endl;
        cout << "\t" << "10" << "\t" << "0.115 or 11.5%" << endl;
    }

    void DisplayBalance()
    {
        cout << "Balance: " << balance << endl;
    }

    void withdraw()
    {
        cout << "Enter amount to withdraw: ";
        float amount;
        cin >> amount;
        if (amount > balance)
        {
            cout << "Insufficient balance!" << endl;
        }
        else
        {
            balance -= amount;
            cout << "Amount withdrawn successfully!" << endl;
        }
    }
};

class CheckingAccount : public Account
{
public:
    void deposit()
    {
        cout << "Enter amount to deposit: ";
        float amount;
        cin >> amount;
        balance += amount;
        cout << "Amount deposited successfully!" << endl;
    }

    void withdraw()
    {
        cout << "Enter amount to withdraw: ";
        float amount;
        cin >> amount;
        if (amount > balance)
        {
            cout << "Insufficient balance!" << endl;
        }
        else
        {
            balance -= amount;
            cout << "Amount withdrawn successfully!" << endl;
        }
    }

    void DisplayBalance()
    {
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    int size = 2;
    Account *acc[size] = {
        new SavingsAccount(),
        new CheckingAccount()};

    int choice;
    cout << "1. Savings Account "<<endl<<"2. Checking Account: "<<endl<<"Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        acc[0]->InterestRates();
        acc[0]->deposit();
        acc[0]->DisplayBalance();
        acc[0]->withdraw();
        acc[0]->DisplayBalance();
    }
    else if (choice == 2)
    {
        acc[1]->deposit();
        acc[1]->DisplayBalance();
        acc[1]->withdraw();
        acc[1]->DisplayBalance();
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    for (int i = 0; i < size; i++)
    {
        delete acc[i];
    }

    return 0;
}