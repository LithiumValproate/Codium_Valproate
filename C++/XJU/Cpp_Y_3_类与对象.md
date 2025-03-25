# 实验三 类与对象

__班级：软件24-18  姓名：杨鎏__

## 一、实验目的

* 学习定义类和组合类
* 设计不同构造函数，观察构造函数和析构函数的执行过程

## 二、实验内容

1. 设计并实现以下类和对象：

    1. 设计`Point`类表示二维平面上点。__（30分）__

    * 属性：横坐标`x`，纵坐标`y`。
    * 行为：
      * 设置横坐标和纵坐标的值 `set_xy`；
      * 获取横坐标的值 `get_x`；
      * 获取纵坐标的值 `get_y`。

    2. 设计`Line`类表示二维平面上的线段。__（50分）__

    * 属性：线段的起始点`sPoint`，终点`ePoint`（`sPoint`和`ePoint`均为`Point`类的对象）。
    * 行为：
      * 设置起始点`sPoint`的位置 `set_sPoint`；
      * 设置终点`ePoint`的位置 `set_ePoint`；
      * 获取起始点`sPoint`的位置 `get_sPoint`；
      * 获取终点`ePoint`的位置`get_ePoint`；
      * 获取当前线段的长度`get_length`；
      * 判断某个点是否在当前线段上`is_point_on_line`。

在`main`函数中实例化相应对象并且调用以上类中的所有行为。__（20分）__

整个代码要求体现：带参数的构造函数，默认构造函数，复制构造函数、析构函数、类成员访问权限的控制，组合的思想。

## 三、实验步骤及结果

（在此部分列出 __解题思路、程序代码和运行结果截图等三项内容__。请注意保持格式规范统一，截图清晰，大小合适）

#### 代码撰写基本规范：

* 保持代码结构清晰，注意缩进和对齐。
* 标识符命名遵循“见其名，知其意思”原则，建议用英文词汇或其简写。
* 括号等成对输入，不易遗漏。
* 提高代码可读性。合理使用段注释和行注释。

#### 参考示例：

0. 编写程序，在屏幕输出“Hello World"

```cpp
/*
  功能：从键盘输入a,b两个整数，并输出它们的值
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

1. 设计`Point`类表示二维平面上点；
    设计`Line`类表示二维平面上的线段；
    在`main`函数中实例化相应对象并且调用以上类中的所有行为。

```cpp
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
```

运行结果截图：
<img src=http://167.179.97.78/wp-content/uploads/2025/03/屏幕截图-2025-03-25-121138.png>


## 四、实验小结

（包括问题和解决办法、心得体会。 __必须要有具体错误截图和针对性讨论，不能仅有文字文字说明。__）__（20分）__

__问题与解决办法：__ `Line`类无法访问`Point`类中的私有数据。

__解决办法：__ 查找资料后，学习到了添加`friend`语句。

__心得体会：__ 多查资料。