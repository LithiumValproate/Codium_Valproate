#include "Cpp_Y_4_employee.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <variant>
#include <vector>
using namespace std;
using KeyType = variant<char, double, string>;

vector<Employee> eArray;

void add_employee(const Employee& e) {
    eArray.push_back(e);
}

void sort_employee(vector<Employee> eArray, int c) {
    switch (c) {
        case 1: {
            sort(eArray.begin(), eArray.end(), [](const Employee& a, const Employee& b) {
                return a.get_id() < b.get_id();
            });
            break;
        }
        case 2: {
            sort(eArray.begin(), eArray.end(), [](const Employee& a, const Employee& b) {
                return a.get_gender() < b.get_gender();
            });
            break;
        }
        case 3: {
            sort(eArray.begin(), eArray.end(), [](const Employee& a, const Employee& b) {
                return a.get_salary() < b.get_salary();
            });
            break;
        }
        default:
            cout << "Error" << endl;
            break;
    }
    for (const auto& e : eArray) {
        cout << e.get_id() << " " << e.get_gender() << " " << e.get_salary() << endl;
    }
}

void edit_employee(const string& id) {
    auto it = find_if(eArray.begin(), eArray.end(), 
        [&id](const Employee& e) { return e.get_id() == id; });
    if (it == eArray.end()) {
        cout << "Not found" << endl;
        return;
    }
    cout << "Enter new data: ";
    string input;
    cin >> input;
    KeyType value;
    try {
        double salary = stod(input);
        value = salary;
        it->set_salary(salary);
        return;
    } catch (...) {}
    if (input.length() == 1 && (toupper(input[0]) == 'M' || toupper(input[0]) == 'F')) {
        value = toupper(input[0]);
        it->set_gender(input[0]);
        return;
    }
    value = input;
    it->set_id(input);
}

void select_func(int c) {
    switch (c) {
        case 1:
            sort_employee(eArray, 1);
            break;
        case 2:
            sort_employee(eArray, 2);
            break;
        case 3:
            sort_employee(eArray, 3);
            break;
        case 4: {

            break;
        }
        case 5: {
            break;
        }
        case 6: {
            break;
        }
        case 7:{

        }
        case 8: {
            break;
        }
        default:
            cout << "Error" << endl;
            break;
    }
}
int main() {
    Employee e1("num001", 'M', 1953.65), e2("num002", 'F', 4698.91), e3(e1);
    add_employee(e1);
    add_employee(e2);
    add_employee(e3);
    while (true) {
        cout << endl << "Select function:\n"
        << "1. Sort by ID\n"
        << "2. Sort by Salary\n"
        << "3. Sort by Gender\n"
        << "4. Edit Employee\n"
        << "5. Add Employee\n"
        << "6. Delete Employee\n"
        << "7. Show Employee\n"
        << "8. Show All Employees\n"
        << "9. Exit" << endl;
        int c;
        cin >> c;
        if (c == 9) return 0;
        if (c < 1 || c > 9) {
            cout << "Error" << endl;
            continue;
        }
        select_func(c);

    }

}