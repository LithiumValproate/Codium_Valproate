#include <iostream>
#include <string>
using namespace std;

class Author {
  private:
    string name;
    int year;

  public:
    Author(string n, int y) : name(n), year(y) {
        cout << "调用Author构造函数\n";
    }

    Author(const Author& a) : name(a.name), year(a.year) {
        cout << "调用Author复制构造函数\n";
    }

    ~Author() {
        cout << "调用Author析构函数\n";
    }

    void show() {
        cout << "作者姓名是：" << name << "\n作者出生年份是：" << year << endl;
    }
};

class Book {
  private:
    string name;
    Author author;
    float price;
    int year;

  public:
    Book(string n, Author a, float p, int y) : name(n), author(a), price(p), year(y) {
        cout << "调用Book构造函数\n";
    }

    ~Book() {
        cout << "调用Book析构函数\n";
    }

    void show(Author& a) {
        cout << "书名：" << name << endl;
        a.show();
        cout << "出版年份：" << year << "\n价格：" << price << endl;
    }
};

int main() {
    Author a("Dennis Ritchie", 1941);
    Book b("The C Programming Language", a, 29.99, 1978);
    b.show(a);
    return 0;
}