# 实验六 多态性

__班级：软件24-18  姓名：杨鎏__

## 一、实验目的

* 掌握运算符重载和虚函数实现多态性
* 设计基类，派生子类，观察纯虚函数和虚函数的作用，结合类型兼容规则，正确实现多态

## 二、实验内容

1. 设计一个二维平面上的点类`Point`，并实现以下运算符重载：

   * 重载加法运算符`+`，实现两个点的坐标相加
   * 重载减法运算符`-`，实现两个点的坐标相减
   * 重载前置自增运算符`++`，使点的横纵坐标分别各加1
   * 重载后置自增运算符`++`，使点的横纵坐标分别各加1
   * 重载输出流运算符`<<`，实现点坐标的格式化输出，格式为"(横坐标的值, 纵坐标的值)"
   
   并在`main`函数中使用相应的语法实现对以上运算符的正确调用。__（50分）__
   
2. 设计一个图形类继承体系。具体要求如下：

   * 设计一个抽象基类 `Shape`， `Shape`类中应包含：
     * 纯虚函数 `double getArea() const = 0`（计算面积）
     * 纯虚函数 `double getPerimeter() const = 0`（计算周长）
     * 虚析构函数
     * 虚函数 `void display() const`（打印图形的关键参数，例如圆形的半径或矩形的长宽）
   * 从 `Shape` 派生出以下两个具体的图形类：
     * `Circle`（圆形）：需要存储半径
     * `Rectangle`（矩形）：需要存储长和宽

   每个派生类都应：有合适的构造函数初始化其数据成员，实现所有纯虚函数和虚函数，使用 `override` 关键字明确标识覆盖的函数。并在main函数中创建不同图形对象并结合类型兼容规则，展示多态性。__（50分）__

## 三、实验步骤及结果

（在此部分列出 __解题思路、程序代码和运行结果截图等三项内容__。请注意保持格式规范统一，截图清晰，大小合适）

#### 代码撰写基本规范：
* 保持代码结构清晰，注意缩进和对齐；
* 标识符命名遵循“见其名，知其意思”原则，建议用英文词汇或其简写。
* 括号等成对输入，不易遗漏；
* 提高代码可读性。合理使用段注释和行注释。

#### 参考示例：

0. 编写程序，在屏幕上输出“Hello World"

```cpp
/*
  功能：在屏幕上输出“Hello World"
  作者：张三
  版本：1.0
*/
#include <iostream>
using namespace std;
int main(){
    cout << "Hello World" << endl;
    return 0;
}
```

运行结果截图：

<img src="https://gitee.com/yannyyy/object-oriented-programming/raw/master/imgs/helloworld.png" alt="Hello World示例" style="zoom:150%;" />

1. 设计一个二维平面上的点类`Point`，并实现运算符重载：

```cpp
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
```

运行结果截图：
![1-1](1.png)
![1-2](2.png)
![1-3](3.png)


2. 设计一个图形类继承体系：

```cpp
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
```

运行结果截图：

![2](4.png)

## 四、实验小结

（包括问题和解决办法、心得体会。__必须要有具体错误截图和针对性讨论，不能仅有文字文字说明。__）__（20分）__

#### 实验小结参考示例：

__问题与解决办法：__   无

__解决办法：__ 无

__心得体会：__ 学到了多态