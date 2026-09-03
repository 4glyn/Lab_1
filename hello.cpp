#include <iostream>
#include <string>
using namespace std;

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"

struct Student {
    string school;
    string name;
    string studentNumber;
    string course;
    string block;
};

int main() {
    int capacity = 10;
    int count = 0;
    Student* students = new Student[capacity];
    int choice;

    do {
        cout << "\n" << CYAN << BOLD << "=== Student Information System ===" << RESET << endl;
        cout << YELLOW << "1. Add Student" << RESET << endl;
        cout << YELLOW << "2. View All Students" << RESET << endl;
        cout << YELLOW << "3. Exit" << RESET << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            if (count == capacity) {
                capacity *= 2;
                Student* temp = new Student[capacity];
                for (int i = 0; i < count; i++) {
                    temp[i] = students[i];
                }
                delete[] students;
                students = temp;
            }

            cin.ignore();
            cout << "Enter School Name: ";
            getline(cin, students[count].school);
            cout << "Enter Student Name: ";
            getline(cin, students[count].name);
            cout << "Enter Student Number: ";
            getline(cin, students[count].studentNumber);
            cout << "Enter Course: ";
            getline(cin, students[count].course);
            cout << "Enter Block: ";
            getline(cin, students[count].block);

            count++;
            cout << GREEN << BOLD << "Student successfully added!" << RESET << endl;
        }
        else if (choice == 2) {
            if (count > 0) {
                cout << "\n" << BLUE << BOLD << "--- Student Records ---" << RESET << endl;
                for (int i = 0; i < count; i++) {
                    cout << CYAN << "ID: " << RESET << students[i].studentNumber
                         << CYAN << " | Name: " << RESET << students[i].name
                         << CYAN << " | School: " << RESET << students[i].school
                         << CYAN << " | Course: " << RESET << students[i].course
                         << CYAN << " | Block: " << RESET << students[i].block << endl;
                }
            } else {
                cout << RED << "No student records found." << RESET << endl;
            }
        }
    } while (choice != 3);

    delete[] students;
    cout << RED << BOLD << "Exiting System." << RESET << endl;
    return 0;
}
