#include <iostream>
using namespace std;
class Date {
private:
    int year;
    int month;
    int day;

public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {
        cout << "调用构造函数" << endl;
    }
    Date(const Date& D) : year(D.year), month(D.month), day(D.day) {
        cout << "调用复制构造函数" << endl;
    }
    ~Date() {
        cout << "调用析构函数" << endl;
    }

    void show() const {
        cout << year << " " << month << " " << day << endl;
    }

    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
};

int calDate(const Date& D) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year = D.getYear();
    int month = D.getMonth();
    int day = D.getDay();
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[2] = 29;
    int totalDays = 0;
    for (int i = 1; i < month; i++)
        totalDays += daysInMonth[i];
    totalDays += day;
    return totalDays;
}

int main() {
    int y, m, d;
    cin >> y >> m >> d;
    Date d1(y, m, d);
    int days = calDate(d1);
    cout << y << "-" << m << "-" << d << "是第" << days << "天" << endl;
    Date d2(d1);
    days = calDate(d2);
    cout << y << "-" << m << "-" << d << "是第" << days << "天" << endl;
    system("pause");
    return 0;
}