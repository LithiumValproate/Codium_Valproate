#include <cmath>
#include <iostream>
#include <utility>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int x0, int y0) : x(x0), y(y0) {
        cout << "调用Point类自定义构造函数\n";
    }
    Point(const Point& p) : x(p.x), y(p.y) {
        cout << "调用Point类复制构造函数\n";
    }
    ~Point() {
        cout << "调用Point类析构函数\n";
    }
    void show_point() {
        printf("(%d,%d)", x, y);
    }
    pair<int, int> get_p() const {
        return make_pair(x, y);
    }
};

class Circle {
private:
    Point centre;
    int radius;

public:
    Circle(int x0, int y0, int r) : centre(x0, y0), radius(r) {
        cout << "调用Circle类值的自定义构造函数\n";
    }
    Circle(Point p, int r) : centre(p), radius(r) {
        cout << "调用Circle类点的自定义构造函数\n";
    }
    Circle(const Circle& c) : centre(c.centre), radius(c.radius) {
        cout << "调用Circle类复制构造函数\n";
    }
    ~Circle() {
        cout << "调用Circle类析构函数\n";
    }
    void show_circle() {
        cout << "圆心坐标";
        centre.show_point();
        cout << "\n圆半径：" << radius << endl;
    }
    int judge(const Circle& c) const {
        int r1 = radius, r2 = c.radius;
        pair<int, int> p1 = centre.get_p();
        pair<int, int> p2 = c.centre.get_p();
        double d = pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2);
        double rSum = r1 + r2;
        double rDiff = abs(r1 - r2);
        if (d == pow(rSum, 2)) return 1;
        else if (d == pow(rDiff, 2)) return 2;
        else if (d < pow(rDiff, 2)) return 3;
        else if (d > pow(rSum, 2)) return 4;
        else return 5;
    }
};

void pos_rela(int i) {
    cout << "两个圆的关系为：";
    switch (i) {
    case 1: cout << "两圆相切\n"; break;
    case 2: cout << "两圆相切\n"; break;
    case 3: cout << "两圆包含\n"; break;
    case 4: cout << "两圆相离\n"; break;
    case 5: cout << "两圆相交\n"; break;
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    Point p1(3, 4);
    Circle cc1(a, b, c);
    Circle cc2(p1, 1);
    cc1.show_circle();
    cc2.show_circle();
    pos_rela(cc1.judge(cc2));
    return 0;
}