#include <iostream>
#include <string>
#define EMPLOYEE_NUM 5

using namespace std;

class Employee {
private:
    int id;
    string name;
    float salary;

public:
    
    void input() {
        cout << "Enter id: ";
        cin >> id;
        cin.ignore(); 

        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter salary: ";
        cin >> salary;
    }

    void display() const {
        cout << "Id: " << id << "\n" << " Name: " << name  << "\n" << " Salary: " << salary  << "\n" << endl;
    }

    float getSalary() const {
        return salary;
    }
};

int main() {

    Employee* employees = new Employee[EMPLOYEE_NUM];

    cout << "Enter the employee details for " << EMPLOYEE_NUM << " employees:" << endl;
    for (int i = 0; i < EMPLOYEE_NUM; i++) {
        cout << "Employee " << (i + 1) << ":" << endl;
        employees[i].input();
    }

    float threshold;
    cout << "Enter a threshold salary: ";
    cin >> threshold;

    cout << "Employees with salary greater than " << threshold << ":" << endl;
    for (int i = 0; i < EMPLOYEE_NUM; i++) {
        if (employees[i].getSalary() > threshold) {
            employees[i].display();
        }
    }

    delete[] employees;

    return 0;
}
