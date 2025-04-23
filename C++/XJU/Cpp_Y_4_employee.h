#ifndef CPP_Y_4_EMPLOYEE_H
#define CPP_Y_4_EMPLOYEE_H
#include <string>
using std::string;

class Employee {
  private:
    string id;
    char gender;
    double salary;
    static int amount;

  public:
    Employee(const string& id = "num000", char g = 'M', double s = 0.0);
    Employee(const Employee& e);
    ~Employee();
    void set_id(const string&);
    string get_id() const;
    void set_gender(char);
    char get_gender() const;
    void set_salary(double);
    double get_salary() const;
    static int get_amount();
};

#endif