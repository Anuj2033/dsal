#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Structure to represent student information
struct Student {
    int rollNumber;
    string name;
    string division;
    string address;
};

// Function to add student information to the file
void addStudentInfo(const Student& student) {
    ofstream outFile("student_records.txt", ios::app); // Open file in append mode

    if (outFile.is_open()) {
        outFile << student.rollNumber << "," << student.name << "," << student.division << "," << student.address << "\n";
        outFile.close();
        cout << "Student information added successfully." << endl;
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}

// Function to delete student information from the file
void deleteStudentInfo(int rollNumber) {
    ifstream inFile("student_records.txt");
    ofstream tempFile("temp.txt");

    if (!inFile || !tempFile) {
        cout << "Unable to open file for deletion." << endl;
        return;
    }

    bool found = false;
    Student student;
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string token;
        getline(ss, token, ',');
        student.rollNumber = stoi(token);

        if (student.rollNumber != rollNumber) {
            tempFile << line << endl;
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    if (found) {
        remove("student_records.txt");
        rename("temp.txt", "student_records.txt");
        cout << "Student information deleted successfully." << endl;
    } else {
        cout << "Student with roll number " << rollNumber << " not found." << endl;
        remove("temp.txt"); // Delete temporary file
    }
}

// Function to display information of a particular student
void displayStudentInfo(int rollNumber) {
    ifstream inFile("student_records.txt");

    if (inFile.is_open()) {
        bool found = false;
        Student student;
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string token;
            getline(ss, token, ',');
            student.rollNumber = stoi(token);
            getline(ss, student.name, ',');
            getline(ss, student.division, ',');
            getline(ss, student.address);

            if (student.rollNumber == rollNumber) {
                found = true;
                cout << "Roll Number: " << student.rollNumber << endl;
                cout << "Name: " << student.name << endl;
                cout << "Division: " << student.division << endl;
                cout << "Address: " << student.address << endl;
                break;
            }
        }
        if (!found) {
            cout << "Student with roll number " << rollNumber << " not found." << endl;
        }
        inFile.close();
    } else {
        cout << "Unable to open file for reading." << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "Menu:\n1. Add student information\n2. Delete student information\n3. Display student information\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Student newStudent;
                cout << "Enter Roll Number: ";
                cin >> newStudent.rollNumber;
                cout << "Enter Name: ";
                cin.ignore(); // Ignore newline character left in the input buffer
                getline(cin, newStudent.name);
                cout << "Enter Division: ";
                getline(cin, newStudent.division);
                cout << "Enter Address: ";
                getline(cin, newStudent.address);

                addStudentInfo(newStudent);
                break;
            }
            case 2: {
                int rollNumber;
                cout << "Enter Roll Number of student to delete: ";
                cin >> rollNumber;
                deleteStudentInfo(rollNumber);
                break;
            }
            case 3: {
                int rollNumber;
                cout << "Enter Roll Number of student to display: ";
                cin >> rollNumber;
                displayStudentInfo(rollNumber);
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
