#include <iostream>
using namespace std;
class Employee
{

    int id;
    string name;
    float salary;

public:
    void input_data()
    {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee name: ";
        cin >> name;
        cout << "Enter Employee salary: ";
        cin >> salary;
    }
    float get_salary() const
    {
        return salary;
    }

    void display_data()
    {
        cout << "\n";
        cout << "-----Employee who have greater salary than user specified  salary-----";
        cout << "\n";
        cout << "Employee ID: " << id << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Employee Salary: " << salary << endl;
    }
};

int main()
{
    int n, sp_salary = 3000;
    cout << "Enter the number of employees: ";
    cin >> n;
    Employee *e[n];
    for (int i = 0; i < n; i++)
    {
        e[i] = new Employee;
        e[i]->input_data();
    }

    for (int i = 0; i < n; i++)
    {
        if (e[i]->get_salary() > sp_salary)
        {
            cout << "\n";
            e[i]->display_data();
        }
    }

    for (int i = 0; i < n; ++i)
    {
        delete e[i];
    }

    return 0;
}