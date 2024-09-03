#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
class person
{
    string name;
    int day, month, year;

public:
    void input()
    {
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your date of birth (dd mm yyyy): ";
        cin >> day >> month >> year;

        if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900)
        {
            cout << "Invalid date" << endl;
            exit(0);
        }
    }

    string get_name()
    {
        return name;
    }

    int get_day()
    {
        return day;
    }

    int get_month()
    {
        return month;
    }

    int get_year()
    {
        return year;
    }
    void show_data()
    {
        cout << "Name: " << name << endl;
        tm birthdate = {};
        birthdate.tm_mday = day;
        birthdate.tm_mon = month - 1;
        birthdate.tm_year = year - 1900;

        // Format and output the date
        char buffer[11]; // Buffer to hold the formatted date string
        strftime(buffer, sizeof(buffer), "%d/%m/%Y", &birthdate);
        cout << "Formatted date of birth: " << buffer << endl;
    }
};

int main()
{
    int num;
    cout << "Enter the number of persons: ";
    cin >> num;
    person *p[num];
    for (int i = 0; i < num; i++)
    {
        p[i] = new person;
        cout << "Enter person"
                "("
             << i + 1 << ")" << endl;
        p[i]->input();
    }

    for (int i = 0; i < num; i++)
    {
        p[i]->show_data();
    }

    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if ((p[i]->get_day() == p[j]->get_day()) && (p[i]->get_month() == p[j]->get_month()) && (p[i]->get_year() == p[j]->get_year()))
            {
                cout << "Duplicate date of birth found: " << p[i]->get_name() << " and " << p[j]->get_name() << endl;
            }
        }
    }
    for (int i = 0; i < num; i++)
    {
        delete p[i];
    }

    return 0;
}