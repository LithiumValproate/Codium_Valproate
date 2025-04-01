#include <iostream>
using namespace std;

class Cube {
  private:
    int a = 0, b = 0, c = 0;

  public:
    Cube(int a0 = 0, int b0 = 0, int c0 = 0) : a(a0), b(b0), c(c0) {
        cout << "调用构造函数\n";
    }

    ~Cube() {
        cout << "调用析构函数\n";
    }

    int sum = (a + b + c) * (a + b + c);
};

int main() {
    Cube first(1), second(1,2), third(1,2,3);
    printf("立方和分别为：%d %d %d\n", first.sum, second.sum, third.sum);
    return 0;
}