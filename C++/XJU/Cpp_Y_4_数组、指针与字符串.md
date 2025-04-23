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
   void set_id(const string&);
   string get_id() const;
   void set_gender(char);
   char get_gender() const;
   void set_salary(double);
   double get_salary() const;
   static int get_amount();
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

1. 使用多文件结构编写程序实现人事管理的人员信息管理。

   1. `employee.h`

   ```cpp
   #ifndef PERSON_H
   #define PERSON_H
   #include <string>
   using std::string;

   class Employee {
     private:
      string id;
      char gender;
      double salary;
      static int amount;

     public:
      Employee(const string& id = "num000", char g = 'M', double s = 0.0);
      Employee(const Employee& e);
      ~Employee();
      void set_id(const string&);
      string get_id() const;
      void set_gender(char);
      char get_gender() const;
      void set_salary(double);
      double get_salary() const;
      static int get_amount();
   };

   #endif
   ```

   2. `employee.cpp`

   ```cpp
   #include "Cpp_Y_4_employee.h"
   #include <iostream>
   using namespace std;

   int Employee::amount = 0;

   Employee::Employee(const string& id, char g, double s)
            : id(id), gender(g), salary(s) { amount++; }

   Employee::Employee(const Employee& e)
            : id(e.id), gender(e.gender), salary(e.salary) { amount++; }

   Employee::~Employee() { amount--; }

   void Employee::set_id(const string& id) { this->id = id; }

   string Employee::get_id() const { return id; }

   void Employee::set_gender(char g) {
      if (g != 'M' && g != 'F')
         cout << "Error" << endl;
      else
         gender = g;
   }

   char Employee::get_gender() const { return gender; }

   void Employee::set_salary(double s) {
      if (s < 0)
         cout << "Error" << endl;
      else
         salary = s;
   }

   double Employee::get_salary() const { return salary; }

   int Employee::get_amount() { return amount; }
   ```
   3. `main.cpp`

```cpp
#include "Cpp_Y_4_employee.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <variant>
#include <vector>
using namespace std;
using KeyType = variant<char, double, string>;

vector<Employee> eArray;

void add(const Employee& e) {
    eArray.push_back(e);
}

void sort(vector<Employee>& eArray, int c) {
    switch (c) {
    case 1:
        std::sort(eArray.begin(), eArray.end(), [](const Employee& a, const Employee& b) {
            return a.get_id() < b.get_id();
        });
        break;
    case 2:
        std::sort(eArray.begin(), eArray.end(), [](const Employee& a, const Employee& b) {
            return a.get_gender() < b.get_gender();
        });
        break;
    case 3:
        std::sort(eArray.begin(), eArray.end(), [](const Employee& a, const Employee& b) {
            return a.get_salary() < b.get_salary();
        });
        break;
    default:
        cout << "Error" << endl;
        break;
    }
    for (const auto& e : eArray) {
        cout << e.get_id() << " " << e.get_gender() << " " << e.get_salary() << endl;
    }
}

void edit(const string& id) {
    auto it = find_if(eArray.begin(), eArray.end(),
                      [&id](const Employee& e) { return e.get_id() == id; });
    if (it == eArray.end()) {
        cout << "Not found" << endl;
        return;
    }
    cout << "Enter new data: ";
    string input;
    cin >> input;
    KeyType value;
    try {
        double salary = stod(input);
        value = salary;
        it->set_salary(salary);
        return;
    } catch (...) {
    }
    if (input.length() == 1 && (toupper(input[0]) == 'M' || toupper(input[0]) == 'F')) {
        value = toupper(input[0]);
        it->set_gender(input[0]);
        return;
    }
    value = input;
    it->set_id(input);
}

void del(const string& id) {
    auto it = find_if(eArray.begin(), eArray.end(),
                      [&id](const Employee& e) { return e.get_id() == id; });
    if (it == eArray.end()) {
        cout << "Not found" << endl;
        return;
    }
    eArray.erase(it);
}

void show(bool c) {
    if (c == true) {
        string id;
        cout << "Enter ID to show: ";
        cin >> id;
        auto it = find_if(eArray.begin(), eArray.end(),
                          [&id](const Employee& e) { return e.get_id() == id; });
        if (it == eArray.end()) {
            cout << "Not found" << endl;
            return;
        }
        cout << "ID: " << it->get_id() << endl
             << "Gender: " << it->get_gender() << endl
             << "Salary: " << it->get_salary() << endl;
        return;
    } else {
        for (const Employee& e : eArray) {
            cout << "ID: " << e.get_id() << endl
                 << "Gender: " << e.get_gender() << endl
                 << "Salary: " << e.get_salary() << endl;
        }
        return;
    }
}

void select_func(int c) {
    switch (c) {
    case 1:
        sort(eArray, 1);
        break;
    case 2:
        sort(eArray, 2);
        break;
    case 3:
        sort(eArray, 3);
        break;
    case 4: {
        string id;
        cout << "Enter employee's ID to edit: ";
        cin >> id;
        edit(id);
        break;
    }
    case 5: {
        string id;
        char g;
        double s;
        cout << "Enter ID, gender, salary: ";
        cin >> id >> g >> s;
        if (toupper(g) != 'M' || toupper(g) != 'F') {
            cout << "Invalid gender!" << endl;
            break;
        }
        if (s < 0) {
            cout << "Invalid salary!" << endl;
            break;
        }
        Employee eTmp(id, toupper(g), s);
        add(eTmp);
        break;
    }
    case 6: {
        string id;
        cout << "Enter employee's ID to delete: ";
        cin >> id;
        del(id);
        break;
    }
    case 7:
        show(true);
        break;
    case 8:
        show(false);
        break;
    case 9:
        cout << Employee::get_amount() << " employees" << endl;
        break;
    default:
        cout << "Error" << endl;
        break;
    }
}
int main() {
    Employee e1("num001", 'M', 1953.65), e2("num002", 'F', 4698.91), e3(e1);
    add(e1);
    add(e2);
    add(e3);
    while (true) {
        cout << endl
             << "Select function:\n"
             << "1. Sort by ID\n"
             << "2. Sort by Salary\n"
             << "3. Sort by Gender\n"
             << "4. Edit Employee\n"
             << "5. Add Employee\n"
             << "6. Delete Employee\n"
             << "7. Show Employee\n"
             << "8. Show All Employees\n"
             << "9. Show amount of employees\n"
             << "0. Exit" << endl;
        int c;
        cin >> c;
        if (c == 0) {
            system("pause");
            return 0;
        }
        if (c < 0 || c > 9) {
            cout << "Error" << endl;
            continue;
        }
        select_func(c);
    }
    system("pause");
    return 0;
}
   ```

![4-1](4-1.png)

![4-2](4-2.png)


## 四、实验小结

（包括问题和解决办法、心得体会。__必须要有具体错误截图和针对性讨论，不能仅有文字文字说明。__）__（20分）__

#### 实验小结参考示例：

__问题与解决办法__

没有

__解决办法：__ 没有

__心得体会：__ 没有

