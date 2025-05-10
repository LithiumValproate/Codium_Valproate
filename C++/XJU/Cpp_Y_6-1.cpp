#include <iostream>
using namespace std;

class Point {
    int x, y;

  public:
    Point(int x, int y) : x(x), y(y) {};

    ~Point() {};

    friend Point operator+(Point a, Point b);

    friend Point operator-(Point a, Point b);

    friend Point operator++(Point& a);

    friend Point operator--(Point& a);

    friend ostream& operator<<(ostream& os, const Point& a);
};

Point operator+(Point a, Point b) {
    return Point(a.x + b.x, a.y + b.y);
}

Point operator-(Point a, Point b) {
    return Point(a.x - b.x, a.y - b.y);
}

Point operator++(Point& a) {
    a.x++;
    a.y++;
    return a;
}

Point operator--(Point& a) {
    a.x--;
    a.y--;
    return a;
}

ostream& operator<<(ostream& os, const Point& a) {
    os << "(" << a.x << ", " << a.y << ")";
    return os;
}

int main() {
    while (1) {
        cout << "Enter number to select functions\n"
        << "1. Create a point\n"
        << "2. Addition\n"
        << "3. Substraction\n"
        << "4. Exit\n";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                int x, y;
                cout << "Enter x and y coordinates: ";
                cin >> x >> y;
                Point p(x, y);
                cout << "Point created: " << p << endl;
                cout << "Incrementing point: " << ++p << endl;
                cout << "Decrementing point: " << --p << endl;
                break;
            }
            case 2: {
                int x1, y1, x2, y2;
                cout << "Enter coordinates of first point: ";
                cin >> x1 >> y1;
                cout << "Enter coordinates of second point: ";
                cin >> x2 >> y2;
                Point p1(x1, y1);
                Point p2(x2, y2);
                Point result = p1 + p2;
                cout << "Result of addition: " << result << endl;
                break;
            }
            case 3: {
                int x1, y1, x2, y2;
                cout << "Enter coordinates of first point: ";
                cin >> x1 >> y1;
                cout << "Enter coordinates of second point: ";
                cin >> x2 >> y2;
                Point p1(x1, y1);
                Point p2(x2, y2);
                Point result = p1 - p2;
                cout << "Result of subtraction: " << result << endl;
                break;
            }
            case 4: {
                cout << "Exiting..." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }
}