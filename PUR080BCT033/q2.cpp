/*

2. Design a class Emoloyee with id,name,and salary as data members.Implement functions to input employee data and display employees who have a salary greater than a user-specified amount.

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee
{
private:
    int id;
    string name;
    double salary;

public:
    void getdata()
    {
        cout << "Enter employee ID: ";
        cin >> id;
        cout << "Enter employee name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter employee salary: ";
        cin >> salary;
        cout << endl;
    }

    void display() const
    {
        cout << "ID: (" << id << ") Name: (" << name << ") Salary: (" << salary << ")" << endl;
    }

    friend void displayHighSalaryEmployees(const vector<Employee> &employees, double threshold);
};

void displayHighSalaryEmployees(const vector<Employee> &employees, double threshold)
{
    cout << endl
         << "Employees with salary greater than " << threshold << ":" << endl;
    for (const auto &employee : employees)
    {
        if (employee.salary > threshold)
        {
            employee.display();
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;
    cout << endl;

    vector<Employee> employees(n);
    for (int i = 0; i < n; ++i)
    {
        employees[i].getdata();
    }

    double threshold;
    cout << "Enter the salary threshold: ";
    cin >> threshold;

    displayHighSalaryEmployees(employees, threshold);

    return 0;
}