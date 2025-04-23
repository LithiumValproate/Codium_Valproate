#include "Cpp_Y_4_employee.h"
#include <iostream>
using namespace std;

int Employee::amount = 0;

Employee::Employee(const string& id, char g, double s)
    : id(id), gender(g), salary(s) { amount++; }

Employee::Employee(const Employee& e)
    : id(e.id), gender(e.gender), salary(e.salary) { amount++; }

Employee::~Employee() { amount--; }

void Employee::set_id(const string& id) { this->id = id; }

string Employee::get_id() const { return id; }

void Employee::set_gender(char g) {
    if (g != 'M' && g != 'F')
        cout << "Error" << endl;
    else
        gender = g;
}

char Employee::get_gender() const { return gender; }

void Employee::set_salary(double s) {
    if (s < 0)
        cout << "Error" << endl;
    else
        salary = s;
}

double Employee::get_salary() const { return salary; }

int Employee::get_amount() { return amount; }