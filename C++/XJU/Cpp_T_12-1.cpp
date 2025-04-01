#include <iostream>
using namespace std;

class Student {
  private:
    int id;
    double maths;
    double english;
    double total = maths + english;

  public:
    Student(int i, double m, double e) : id(i), maths(m), english(e) {
    }

    ~Student() {
    }

    double avr = total / 2;

    void show() const {
        cout << "学生学号：" << id << "\n数学成绩：" << maths
             << "\n英语成绩：" << english << "\n总分是" << total << "分，平均是" << avr << "分\n";
    }

};

int main() {
    int id1, id2;
    double m1, m2, e1, e2;
    cin >> id1 >> m1 >> e1 >> id2 >> m2 >> e2;
    Student stu1(id1, m1, e1), stu2(id2, m2, e2);
    double* srtA[2] = {&stu1.avr, &stu2.avr};
    if (*srtA[0] >= *srtA[1]) {
        stu1.show();
        stu2.show();
    } else {
        stu2.show();
        stu1.show();
    }
    return 0;
}