#include <iostream>
#include <string>
using namespace std;

class Person {
    string name;

  protected:
    Person(string n) : name(n) {};

    ~Person() {};

    virtual void display() const {
        cout << name << endl;
    }

    virtual void modify(string n) {
        name = n;
    }
};

class Student : virtual public Person {
    int stuId;
    string major;

  protected:
    Student(string n, int id, string m) : Person(n), stuId(id), major(m) {}

    ~Student() {};

    void display() const override {
        Person::display();
        cout << " " << stuId << " " << major << endl;
    }

    void modify(string n, int id, string m) {
        Person::modify(n);
        stuId = id;
        major = m;
    }
};

class Teacher : virtual public Person {
    string course;

  protected:
    Teacher(string n, string c) : Person(n), course(c) {};

    ~Teacher() {};

    void display() const override {
        Person::display();
        cout << " " << course << endl;
    }

    void modify(string n, string c) {
        Person::modify(n);
        course = c;
    }
};

class Assistant : public Student, public Teacher {
    int workHours;

  protected:
    Assistant(string n, int id, string m, string c, int h)
        : Person(n), Student(n, id, m), Teacher(n, c), workHours(h) {};

    ~Assistant() {};

    void display() const override {
        Student::display();
        Teacher::display();
    }

    void modify(string n, int id, string m, string c, int h) {
        Student::modify(n, id, m);
        Teacher::modify(n, c);
        workHours = h;
    }
};