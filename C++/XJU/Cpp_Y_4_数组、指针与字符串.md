# 实验四 数组、指针与字符串

__班级：软件24-18  姓名：杨鎏__

## 一、实验目的

* 学习使用数组数据对象
* 学习使用多文件结构编写程序
* 学习使用`string`类完成字符串操作
* 学习使用动态内存分配

## 二、实验内容

1. 使用多文件结构编写程序实现人事管理的人员信息管理。

   `include`合适的头文件。在`Person.h`中声明类的所有数据成员和成员函数，在`Person.cpp`中实现`Person`类。__（50分）__

   `Person`类的属性为：

   ```cpp
   string id;       // 员工工号，格式为“numXXX",其中XXX表示三个数字字符
   char gender;       // 性别
   double salary;     // 薪资
   static int amount; //公司人数（静态数据成员）
   ```

   `Person`类的行为为：

   ```cpp
   //默认构造函数：初始化为空值或默认值，同时更新公司人数
   //带参数的构造函数：初始化所有成员变量，同时更新公司人数
   //复制构造函数：深拷贝，同时更新公司人数
   //析构函数：当对象被销毁时减少公司人数 
   //初始化静态成员
   
   //其他函数：
   void setId(const string& id); 
   string getId() const;
   void setGender(char gender); //'f'表示女，'m'表示男
   char getGender() const;
   void setSalary(double salary);
   double getSalary() const;
   static int getAmount();  // 获取当前公司员工总数
   ```
   
   在`main.cpp`中使用`Person`类。__（30分）__
   
   ```cpp
      void sortPeopleByID(Person pArray[3], int size) //实现Person对象数组的简单排序，按字典序从小到大，要求使用string类的比较功能
          
      /*
      在main方法中：
      （1）声明并初始化有三个元素的Person对象数组
      （2）使用Person类定义的成员函数录入数据或者修改数据
      （3）调用sortPeopleById方法对对象数组排序，输出工号最小的员工的信息（包括员工工号，性别，薪资）
      （4）打印当前公司员工总数
      （5）显示对象数组生命周期结束时的析构过程
      */
   ```

2. 实现一个3行3列的矩阵的转置操作，要求使用动态内存分配。__（20分）__

## 三、实验步骤及结果

（在此部分列出 __解题思路、程序代码和运行结果截图等三项内容__。请注意保持格式规范统一，截图清晰，大小合适）

#### 代码撰写基本规范：

* 保持代码结构清晰，注意缩进和对齐；
* 标识符命名遵循“见其名，知其意思”原则，建议用英文词汇或其简写。
* 括号等成对输入，不易遗漏；
* 提高代码可读性。合理使用段注释和行注释

#### 参考示例：

0. 编写程序，在屏幕输出“Hello World"

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

1. 编译出错，提示`error: unexpected character <U+201C>`

![](https://gitee.com/yannyyy/object-oriented-programming/raw/master/imgs/error.png)

__解决办法：__ 查找资料后，发现中文状态输入双引号，系统只允许英文状态下双引号字符。改正后，错误消失,程序运行正常。

__心得体会：__

