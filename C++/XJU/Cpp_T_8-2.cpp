#include <iostream>
using namespace std;
class Complex {
  public:
    Complex(int r, int i) {
        real = r;
        imag = i;
    }
    Complex(const Complex& c) {
        real = c.real;
        imag = c.imag;
    }
    void show_complex() {
        cout << real;
        if (imag > 0)
            cout << "+" << imag << "i\n";
        else if (imag == 0)
            cout << endl;
        else
            cout << imag << "i\n";
    }
    ~Complex() {
    }
  private:
    int real;
    int imag;
};
int main() {
    int r, i;
    cin >> r >> i;
    Complex z1(r, i);
    Complex z2 = z1;
    cout << "z1=";
    z1.show_complex();
    cout << "z2=";
    z2.show_complex();
    system("pause");
    return 0;
}