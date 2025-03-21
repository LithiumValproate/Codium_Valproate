#include <cmath>
#include <iostream>
using namespace std;
const double PI = 3.141592653589793;
class Circle {
public:
    double radium;
    Circle(double r) {
        radium = r;
        cout << "调用构造函数" << endl;
    }
    Circle(const Circle& c) {
        radium = c.radium;
        cout << "调用复制构造函数" << endl;
    }
    ~Circle() {
        cout << "调用析构函数" << endl;
    }

    double area() {
        return PI * pow(radium, 2);
    }
    double circumference() {
        return 2 * PI * radium;
    }
};
double annulus_perimeter(Circle& c1, Circle& c2) {
    return c1.circumference() + c2.circumference();
}
double annulus_area(Circle& c1, Circle& c2) {
    return fabs(c1.area() - c2.area());
}
int main() {
    double r1, r2;
    cin >> r1 >> r2;
    Circle c1(r1), c2(r2);
    cout << "圆环的面积=" << annulus_area(c1, c2) << endl;
    cout << "圆环的周长=" << annulus_perimeter(c1, c2) << endl;
    system("pause");
    return 0;
}