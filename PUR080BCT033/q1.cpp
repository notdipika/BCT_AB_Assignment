/* 1. Create a class person with name and date of birth as data members. Ask the user to enter a date of birth and print all persons name with matched date of birth.

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
private:
    string name;
    string dob;

public:
    Person() {}
    Person(const string &name, const string &dob)
    {
        this->name = name;
        this->dob = dob;
    }

    void getData()
    {
        cin.ignore(); // Ignore the newline character left in the input buffer
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter date of birth (dd/mm/yyyy): ";
        getline(cin, dob);
    }

    void display() const
    {
        cout << "Name: " << name << endl;
        cout << "Date of birth: " << dob << endl;
    }

    friend void search(const vector<Person> &persons);
};

void search(const vector<Person> &persons)
{
    string date;
    cout << "Enter the date of birth to search (dd/mm/yyyy): ";
    cin >> date;

    bool found = false;
    for (const auto &person : persons)
    {
        if (person.dob == date)
        {
            cout << "Name: " << person.name << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No person found with the date of birth: " << date << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of persons: ";
    cin >> n;
    vector<Person> persons(n);
    for (int i = 0; i < n; i++)
    {
        persons[i].getData();
    }

    for (int i = 0; i < n; i++)
    {
        persons[i].display();
    }

    search(persons);

    return 0;
}