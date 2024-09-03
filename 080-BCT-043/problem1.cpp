/*
Create a class person with name and date of birth as data members. Ask the user to
enter a date of birth and print all persons name with a matched date of birth.
*/
#include <iostream>
#include <string>
using namespace std;
class Person {
private:
    string name;
    int year;
    int month;
    int day;

public:
    Person(){}

    Person( string& n, int y, int m, int d) : name(n), year(y), month(m), day(d) {}

    string getName()  {
        return name;
    }

    int getYear()  {
        return year;
    }

    int getMonth()  {
        return month;
    }

    int getDay()  {
        return day;
    }
};

int main() {
    int n;
    cout << "Enter the number of persons: ";
    cin >> n;

    Person *p = new Person[n];

    for (int i = 0; i < n; i++) {
        string name;
        int year, month, day;
        cout << "Enter name for person " << (i + 1) << ": ";
        cin >> name;
        cout << "Enter date of birth (YY MM DD) for person " << (i + 1) << ": ";
        cin >> year >> month >> day;
        p[i] = Person(name, year, month, day);
    }

    int searchYear, searchMonth, searchDay;
    cout << "Enter a date of birth (YY MM DD) to search: ";
    cin >> searchYear >> searchMonth >> searchDay;

    cout << "Persons with matching date of birth:" << endl;
    for (int i = 0; i < n; i++) {
        if (p[i].getYear() == searchYear && p[i].getMonth() == searchMonth && p[i].getDay() == searchDay) {
            cout << p[i].getName() << endl;
        }
    }

    delete[] p;

    return 0;
}