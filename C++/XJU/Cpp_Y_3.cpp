#include <cmath>
#include <iostream>
using namespace std;

class Point {
  private:
    double x;
    double y;
    friend class Line;

  public:
    Point() : x(0), y(0) {
        cout << "Call the default constructor.\n";
    }
    Point(double x0, double y0) : x(x0), y(y0) {
        cout << "Call the parameterized constructor.\n";
    }
    Point(const Point& p) : x(p.x), y(p.y) {
        cout << "Call the duplicating constructor.\n";
    }
    void set_xy(double x0, double y0) {
        x = x0;
        y = y0;
    }
    ~Point() {
        cout << "Call the destructor.\n";
    }


    double get_x() const {
        return x;
    }
    double get_y() const {
        return y;
    }
};

class Line {
  private:
    Point sPoint;
    Point ePoint;

  public:
    void set_sPoint(const Point& p) {
        sPoint = p;
    }
    void set_ePoint(const Point& p) {
        ePoint = p;
    }

    void get_sPoint() const {
        cout << "Start point(" << sPoint.get_x() << ", " << sPoint.get_y() << ")\n";
    }
    void get_ePoint() const {
        cout << "End point(" << ePoint.get_x() << ", " << ePoint.get_y() << ")\n";
    }

    double get_length() const {
        return sqrt(pow(ePoint.get_x() - sPoint.get_x(), 2) + pow(ePoint.get_y() - sPoint.get_y(), 2));
    }

    bool is_point_on_line(const Point& p) const {
        double x0 = ePoint.get_x() - sPoint.get_x();
        double y0 = ePoint.get_y() - sPoint.get_y();
        double xp = p.get_x() - sPoint.get_x();
        double yp = p.get_y() - sPoint.get_y();
        double cross = xp * y0 - yp * x0;
        if (fabs(cross) > 1e-9)
            return false;
        double dot = xp * x0 + yp * y0;
        return dot >= 0 && dot <= (x0 * x0 + y0 * y0);
    }
};

int main() {
    Point s, e, d, p;
    Line l;
    double x, y;
    cout << "Enter x and y of start point:\n";
    cin >> x >> y;
    s = Point(x, y);
    cout << "Enter x and y of end point:\n";
    cin >> x >> y;
    e = Point(x, y);
    d = Point(s);
    cout << "Copied point x: " << d.get_x() << ", y: " << d.get_y() << endl;
    l.set_sPoint(s);
    l.set_ePoint(e);
    l.get_sPoint();
    l.get_ePoint();
    cout << "Length is " << l.get_length() << endl;
    cout << "Enter x and y of a point:\n";
    cin >> x >> y;
    p = Point(x, y);
    if (l.is_point_on_line(p))
        cout << "On line.\n";
    else
        cout << "Not on line.\n";
    system("pause");
    return 0;
}