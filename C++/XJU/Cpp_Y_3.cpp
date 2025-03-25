#include <cmath>
#include <iostream>
using namespace std;
class Point {
  private:
    double x;
    double y;

  public:
    Point(int x0, int y0) {
        x = x0;
        y = y0;
    }
    void set_xy(int x0, int y0) {
        x = x0;
        y = y0;
    }

    void get_x() {
        cout << x << endl;
    }
    void get_y() {
        cout << y << endl;
    }
};

class Line {
  private:
    Point sPoint;
    Point ePoint;

  public:
    void set_sPoint(Point p) {
        sPoint = p;
    }
    void set_ePoint(Point p) {
        ePoint = p;
    }

    void get_sPoint() {
        printf("(%d,%d)", sPoint.x, sPoint.y);
    }
    void get_ePoint() {
        printf("(%d,%d)", ePoint.x, ePoint.y);
    }

    double get_length() {
        return sqrt(pow(fabs(ePoint.x - sPoint.x), 2) + pow(fabs(ePoint.y - sPoint.y), 2));
    }

    bool is_point_on_line(Point p) {
        double x0 = fabs(ePoint.x - sPoint.x);
        double y0 = fabs(ePoint.y - sPoint.y);
        double xp = fabs(p.x - sPoint.x);
        double yp = fabs(p.y - sPoint.y);
        double dot = x0 * xp + y0 * yp;
        bool inRange = (dot >= 0 && dot <= get_length());
        double cross = xp * y0 - yp * x0;
        bool collinear = fabs(cross) < 1e-9;
        return (inRange && collinear) ? true : false;
    }
};

int main() {
}