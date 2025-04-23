#include "Cpp_Y_4_employee.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<Employee> eArray;

void add(const Employee& e) {
    eArray.push_back(e);
}

void sort(vector<Employee>& eArray, int c) {
    switch (c) {
    case 1:
        std::sort(eArray.begin(), eArray.end(), [](const Employee& a, const Employee& b) {
            return a.get_id() < b.get_id();
        });
        break;
    case 2:
        std::sort(eArray.begin(), eArray.end(), [](const Employee& a, const Employee& b) {
            return a.get_gender() < b.get_gender();
        });
        break;
    case 3:
        std::sort(eArray.begin(), eArray.end(), [](const Employee& a, const Employee& b) {
            return a.get_salary() < b.get_salary();
        });
        break;
    default:
        cout << "Error" << endl;
        break;
    }
    for (const auto& e : eArray) {
        cout << e.get_id() << " " << e.get_gender() << " " << e.get_salary() << endl;
    }
}

void edit(const string& id) {
    auto it = find_if(eArray.begin(), eArray.end(),
                      [&id](const Employee& e) { return e.get_id() == id; });
    if (it == eArray.end()) {
        cout << "Not found" << endl;
        return;
    }
    cout << "Enter new data: ";
    string input;
    cin >> input;
    try {
        double salary = stod(input);
        it->set_salary(salary);
        return;
    } catch (...) {
    }
    if (input.length() == 1 && (toupper(input[0]) == 'M' || toupper(input[0]) == 'F')) {
        it->set_gender(input[0]);
        return;
    }
    it->set_id(input);
}

void del(const string& id) {
    auto it = find_if(eArray.begin(), eArray.end(),
                      [&id](const Employee& e) { return e.get_id() == id; });
    if (it == eArray.end()) {
        cout << "Not found" << endl;
        return;
    }
    eArray.erase(it);
}

void show(bool c) {
    if (c == true) {
        string id;
        cout << "Enter ID to show: ";
        cin >> id;
        auto it = find_if(eArray.begin(), eArray.end(),
                          [&id](const Employee& e) { return e.get_id() == id; });
        if (it == eArray.end()) {
            cout << "Not found" << endl;
            return;
        }
        cout << "ID: " << it->get_id() << endl
             << "Gender: " << it->get_gender() << endl
             << "Salary: " << it->get_salary() << endl;
        return;
    } else {
        for (const Employee& e : eArray) {
            cout << "ID: " << e.get_id() << endl
                 << "Gender: " << e.get_gender() << endl
                 << "Salary: " << e.get_salary() << endl;
        }
        return;
    }
}

void select_func(int c) {
    switch (c) {
    case 1:
        sort(eArray, 1);
        break;
    case 2:
        sort(eArray, 2);
        break;
    case 3:
        sort(eArray, 3);
        break;
    case 4: {
        string id;
        cout << "Enter employee's ID to edit: ";
        cin >> id;
        edit(id);
        break;
    }
    case 5: {
        string id;
        char g;
        double s;
        cout << "Enter ID, gender, salary: ";
        cin >> id >> g >> s;
        if (toupper(g) != 'M' && toupper(g) != 'F') {
            cout << "Invalid gender!" << endl;
            break;
        }
        if (s < 0) {
            cout << "Invalid salary!" << endl;
            break;
        }
        Employee eTmp(id, toupper(g), s);
        add(eTmp);
        break;
    }
    case 6: {
        string id;
        cout << "Enter employee's ID to delete: ";
        cin >> id;
        del(id);
        break;
    }
    case 7:
        show(true);
        break;
    case 8:
        show(false);
        break;
    case 9:
        cout << Employee::get_amount() << " employees" << endl;
        break;
    default:
        cout << "Error" << endl;
        break;
    }
}
int main() {
    Employee e1("num001", 'M', 1953.65), e2("num002", 'F', 4698.91), e3(e1);
    add(e1);
    add(e2);
    add(e3);
    while (true) {
        cout << "Select function:\n"
             << "1. Sort by ID\n"
             << "2. Sort by Gender\n"
             << "3. Sort by Salary\n"
             << "4. Edit Employee\n"
             << "5. Add Employee\n"
             << "6. Delete Employee\n"
             << "7. Show Employee\n"
             << "8. Show All Employees\n"
             << "9. Show amount of employees\n"
             << "0. Exit" << endl;
        int c;
        cin >> c;
        if (c == 0) {
            system("pause");
            return 0;
        }
        if (c < 0 || c > 9) {
            cout << "Error" << endl;
            continue;
        }
        select_func(c);
    }
    system("pause");
    return 0;
}