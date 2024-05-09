#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Structure to represent employee information
struct Employee {
    int employeeID;
    string name;
    string designation;
    double salary;
};

// Function to add employee information to the file
void addEmployeeInfo(const Employee& employee) {
    ofstream outFile("employee_records.txt", ios::app); // Open file in append mode

    if (outFile.is_open()) {
        outFile << employee.employeeID << "," << employee.name << "," << employee.designation << "," << employee.salary << "\n";
        outFile.close();
        cout << "Employee information added successfully." << endl;
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}

// Function to delete employee information from the file
void deleteEmployeeInfo(int employeeID) {
    ifstream inFile("employee_records.txt");
    ofstream tempFile("temp.txt");

    if (!inFile || !tempFile) {
        cout << "Unable to open file for deletion." << endl;
        return;
    }

    bool found = false;
    Employee employee;
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string token;
        getline(ss, token, ',');
        employee.employeeID = stoi(token);

        if (employee.employeeID != employeeID) {
            tempFile << line << endl;
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    if (found) {
        remove("employee_records.txt");
        rename("temp.txt", "employee_records.txt");
        cout << "Employee information deleted successfully." << endl;
    } else {
        cout << "Employee with ID " << employeeID << " not found." << endl;
        remove("temp.txt"); // Delete temporary file
    }
}

// Function to display all records of employees
void displayAllEmployeeRecords() {
    ifstream inFile("employee_records.txt");

    if (inFile.is_open()) {
        cout << "Employee ID | Name | Designation | Salary" << endl;
        cout << "----------------------------------------" << endl;

        Employee employee;
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string token;

            getline(ss, token, ',');
            employee.employeeID = stoi(token);

            getline(ss, employee.name, ',');
            getline(ss, employee.designation, ',');

            getline(ss, token);
            employee.salary = stod(token);

            cout << employee.employeeID << " | " << employee.name << " | " << employee.designation << " | " << employee.salary << endl;
        }
        inFile.close();
    } else {
        cout << "Unable to open file for reading." << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "Menu:\n1. Add employee information\n2. Delete employee information\n3. Display employee information\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Employee newEmployee;
                cout << "Enter Employee ID: ";
                cin >> newEmployee.employeeID;
                cout << "Enter Name: ";
                cin.ignore(); // Ignore newline character left in the input buffer
                getline(cin, newEmployee.name);
                cout << "Enter Designation: ";
                getline(cin, newEmployee.designation);
                cout << "Enter Salary: ";
                cin >> newEmployee.salary;

                addEmployeeInfo(newEmployee);
                break;
            }
            case 2: {
                int employeeID;
                cout << "Enter Employee ID of employee to delete: ";
                cin >> employeeID;
                deleteEmployeeInfo(employeeID);
                break;
            }
            case 3: {
                displayAllEmployeeRecords();
                break;
            }
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
