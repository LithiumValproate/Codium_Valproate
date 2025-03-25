#include <cmath>
#include <iostream>
#include <utility>
using namespace std;
class Point {
  private:
    int x;
    int y;

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
    pair<int, int> get_point() const {
        return {x, y};
    }
};

class Rectangle {
  private:
    Point D;
    Point B;
    int l = fabs(D.get_point().first - B.get_point().first);
    int w = fabs(D.get_point().second - B.get_point().second);

  public:
    Rectangle(Point p1, Point p2) : D(p1), B(p2) {
        cout << "调用Rectangle类自定义构造函数\n";
    }
    Rectangle(const Rectangle& r) : D(r.D), B(r.B) {
        cout << "调用Rectangle类复制构造函数\n";
    }
    ~Rectangle() {
        cout << "调用Rectangle类析构函数\n";
    }
    void show_rec() {
        cout << "矩形左下角：";
        D.show_point();
        cout << endl;
        cout << "矩形右上角：";
        B.show_point();
        cout << endl;
        cout << "长：" << l << endl;
        cout << "宽：" << w << endl;
    }
    int get_area() {
        return l * w;
    }

};

int main() {
    Point p1(3, 2), p2(8, 4);
    Rectangle r1(p1, p2);
    Rectangle r2 = r1;
    r2.show_rec();
    cout << "矩形面积：" << r2.get_area() << endl;
    return 0;
}