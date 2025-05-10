#include <iostream>
using namespace std;

class Shape {
  public:
    virtual ~Shape() {}

    virtual double getArea() const = 0;

    virtual double getPerimeter() const = 0;

    virtual void display() const = 0;
};

class Circle : public Shape {
  private:
    double radius;

  public:
    Circle(double r) : radius(r) {}

    double getArea() const override {
        return 3.14 * radius * radius;
    }

    double getPerimeter() const override {
        return 2 * 3.14 * radius;
    }

    void display() const override {
        cout << "Circle: Radius = " << radius << ", Area = " << getArea() << ", Perimeter = " << getPerimeter() << endl;
    }
};

class Rectangle : public Shape {
  private:
    double length;
    double width;

  public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double getArea() const override {
        return length * width;
    }

    double getPerimeter() const override {
        return 2 * (length + width);
    }

    void display() const override {
        cout << "Rectangle: Length = " << length << ", Width = " << width << ", Area = " << getArea() << ", Perimeter = " << getPerimeter() << endl;
    }
};

int main() {
    Shape* s[2];
    int r, l, w;
    cout << "Enter radius of circle: ";
    cin >> r;
    s[0] = new Circle(r);
    cout << "Enter length and width of rectangle: ";
    cin >> l >> w;
    s[1] = new Rectangle(l, w);
    for (int i = 0; i < 2; i++) {
        s[i]->display();
    }
    for (int i = 0; i < 2; i++) {
        delete s[i];
    }
    return 0;
}