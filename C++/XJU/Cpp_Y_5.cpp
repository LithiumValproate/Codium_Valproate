#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;

public:
    Person(string n) : name(n) {};

    virtual ~Person() {};

    virtual void display() const
    {
        cout << name << " ";
    }

    virtual void modify(string n)
    {
        name = n;
    }
};

class Student : virtual public Person
{
protected:
    int stuId;
    string major;

public:
    Student(string n, int id, string m) : Person(n), stuId(id), major(m) {}

    virtual ~Student() {};

    virtual void display(bool s) const
    {
        if (s)
            Person::display();
        cout << stuId << " " << major << " ";
    }

    virtual void modify(string n, int id, string m)
    {
        Person::modify(n);
        stuId = id;
        major = m;
    }
};

class Teacher : virtual public Person
{
protected:
    string course;

public:
    Teacher(string n, string c) : Person(n), course(c) {};

    virtual ~Teacher() {};

    virtual void display(bool s) const
    {
        if (s)
            Person::display();
        cout << course << " ";
    }

    virtual void modify(string n, string c)
    {
        Person::modify(n);
        course = c;
    }
};

class Assistant : public Student, public Teacher
{
protected:
    int workHours;

public:
    Assistant(string n, int id, string m, string c, int h)
        : Person(n), Student(n, id, m), Teacher(n, c), workHours(h) {};

    ~Assistant() override {};

    void display() const override
    {
        Student::display(1);
        Teacher::display(0);
        cout << workHours << " ";
    }

    void modify(string n, int id, string m, string c, int h)
    {
        Person::modify(n);
        stuId = id;
        major = m;
        course = c;
        workHours = h;
    }
};

int main()
{
    Person p("John Doe");
    p.display();
    cout << endl;
    Student s("Jane Doe", 12345, "Computer Science");
    s.display(1);
    cout << endl;
    Teacher t("Dr. Smith", "Physics");
    t.display(1);
    cout << endl;
    Assistant a("Alice", 67890, "Mathematics", "Calculus", 20);
    a.display();
    cout << endl;
    p.modify("John Smith");
    p.display();
    cout << endl;
    s.modify("Jane Smith", 54321, "Biology");
    s.display(1);
    cout << endl;
    t.modify("Dr. Johnson", "Chemistry");
    t.display(1);
    cout << endl;
    a.modify("Alice Smith", 98765, "Statistics", "Linear Algebra", 30);
    a.display();
    cout << endl;
    // system("pause");
    return 0;
}