/*
Create a base class Account with data members accountNumber and balance.
Derive two classes SavingsAccount and CheckingAccount from Account.
Implement polymorphic behavior where the base class pointer can point to objects of
derived classes, and call their respective member functions to deposit and withdraw
money, applying specific rules for each account type.
*/

#include <iostream>
#include <cstdlib>

#define NUM_ACCOUNTS 5

using namespace std;

class Account {
protected:
    int accNum;
    float bal;

public:
    Account() : accNum(rand()), bal(0.0) {}

    virtual void deposit() = 0;
    virtual void withdraw() = 0;

    virtual ~Account() {}
};

class SavingsAccount : public Account {
    int wLimit = 6;
    float penaltyRate = 0.01;

public:
    void deposit() override {
        float amt;
        cout << "Enter amount to deposit into account " << accNum << ": ";
        cin >> amt;
        bal += amt;
    }

    void withdraw() override {
        float amt;
        cout << "Enter amount to withdraw from account " << accNum << ": ";
        cin >> amt;

        if (wLimit > 0) {
            if (bal >= amt) {
                wLimit--;
                bal -= amt;
            } else {
                cout << "Insufficient Balance" << endl;
            }
        } else {
            char ch;
            cout << "Withdrawal limit reached. 1% penalty applies. Continue (y/n)? ";
            cin >> ch;
            if (ch == 'y') {
                if (bal >= amt * (1 + penaltyRate)) {
                    bal -= amt * (1 + penaltyRate);
                } else {
                    cout << "Insufficient Balance with penalty" << endl;
                }
            } else {
                cout << "Transaction cancelled!" << endl;
            }
        }
    }
};

class CheckingAccount : public Account {
    float maxWithdrawal = 100000;

public:
    void deposit() override {
        float amt;
        cout << "Enter amount to deposit into account " << accNum << ": ";
        cin >> amt;
        bal += amt;
    }

    void withdraw() override {
        float amt;
        cout << "Enter amount to withdraw from account " << accNum << ": ";
        cin >> amt;

        if (amt > maxWithdrawal) {
            cout << "Cannot withdraw more than " << maxWithdrawal << " at once." << endl;
        } else {
            if (bal >= amt) {
                bal -= amt;
            } else {
                cout << "Insufficient Balance" << endl;
            }
        }
    }
};

int main() {
    Account* accounts[NUM_ACCOUNTS];
    accounts[0] = new SavingsAccount;
    accounts[1] = new SavingsAccount;
    accounts[2] = new CheckingAccount;
    accounts[3] = new CheckingAccount;
    accounts[4] = new CheckingAccount;

    for (int i = 0; i < NUM_ACCOUNTS; i++)
        accounts[i]->deposit();

    for (int i = 0; i < NUM_ACCOUNTS; i++)
        accounts[i]->withdraw();

    for (int i = 0; i < NUM_ACCOUNTS; i++)
        delete accounts[i];

    return 0;
}
