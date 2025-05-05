# 实验五 类的继承

__班级：软件24-18  姓名：杨鎏__

## 一、实验目的

* 学习声明和使用类的继承关系，声明派生类
* 观察声明基类中有私有成员在派生类中访问情况
* 声明基类和派生类，观察构造函数和析构函数的执行情况

## 二、实验内容

设计人事管理的`Person`类，由此类派生出`Student`类和`Teacher`类，由`Student`类和`Teacher`类共同派生出`TAssistant`类，注意虚基类的使用。__（80分）__

在`main`函数中创建四个类的对象，调用类的每个成员函数，观察各个类的功能以及它们之间的继承关系。__（20分）__

UML类图如图所示：
<img src="https://gitee.com/yannyyy/object-oriented-programming/raw/master/imgs/test5.png" alt="Hello World示例" style="zoom: 60%;" />

### 类设计说明与功能解释

|              类名              | 继承方式                       | 属性                                         | 方法                                                         |
| :----------------------------: | ------------------------------ | -------------------------------------------- | ------------------------------------------------------------ |
|      __Person__<br />(人)      | -                              | `name: string`  姓名                         | `Person(name)` 构造函数<br />`~Person()` 析构函数 <br />`display(): void` 显示人员信息的虚函数<br />`modify(String name):void`  修改姓名 |
|  __Student__<br />（学生类）   | virtual public Person          | `stuId: int` 学号 <br />`major: string` 专业 | `Student(string name, int stuId, string major)` 构造函数 <br />`~Student()` 析构函数 <br />`modifyStu(int newId, string newMaj): void` 修改学生特有信息<br />`displayStu(): void` - 显示学生信息 |
|  __Teacher__<br />（教师类）   | virtual public Person          | `course: string`  教授课程                  | `Teacher(string name, string course)` 构造函数<br />`~Teacher()` - 析构函数 <br />`modifyTea(string newCou): void` 修改教师特有信息 <br />`getName() const: string` 获取姓名<br /> `getCourse() const: string` - 获取课程 |
| __TAssistant__<br />（助教类） | public Student, public Teacher | `workHours: int` 工作时长                   | `TAssistant(string name, int stuId, string major, string course, int workHours)` 构造函数 <br />`~TAssistant()`  析构函数<br />`modifyTA(string newName, int newId, string newMaj, string newCou, int newHours): void` 综合修改方法<br />`displayTA(): void` - 显示助教完整信息 <br />`getWorkHours(): int` - 获取工作时长 |


## 三、实验步骤及结果

（在此部分列出 __解题思路、程序代码和运行结果截图等三项内容__。请注意保持格式规范统一，截图清晰，大小合适）

#### 代码撰写基本规范：

* 保持代码结构清晰，注意缩进和对齐；
* 标识符命名遵循“见其名，知其意思”原则，建议用英文词汇或其简写。
* 括号等成对输入，不易遗漏；
* 提高代码可读性。合理使用段注释和行注释。

#### 参考示例：

1. 编写程序，在屏幕上输出“Hello World"

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

## 四、实验小结

（包括问题和解决办法、心得体会。__必须要有具体错误截图和针对性讨论，不能仅有文字文字说明。__）__（20分）__

#### 实验小结参考示例：

__问题与解决办法__



__解决办法：__ 查找资料后，发现中文状态输入双引号，系统只允许英文状态下双引号字符。改正后，错误消失,程序运行正常。

__心得体会：__
