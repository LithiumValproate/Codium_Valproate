#include <iostream>
using namespace std;
class Complex {
  public:
    int real;
    int imag;
    void set_complex(int r, int i) {
        real = r;
        imag = i;
    }
    void show_complex() {
        cout << real;
        if (imag > 0) cout << "+" << imag << "i\n";
        else if (imag == 0) cout << endl;
        else cout << imag << "i\n";
    }
    Complex add_complex(Complex a, Complex b) {
        Complex tmp;
        tmp.real = a.real + b.real;
        tmp.imag = a.imag + b.imag;
        return tmp;
    }
};
int main() {
    Complex z1, z2;
    int r1, r2, i1, i2;
    cin >> r1 >> i1;
    z1.set_complex(r1, i1);
    cin >> r2 >> i2;
    z2.set_complex(r2, i2);
    cout << "z1=";
    z1.show_complex();
    cout << "z2=";
    z2.show_complex();
    Complex sum;
    sum = sum.add_complex(z1, z2);
    cout << "z1+z2=" << sum.real;
    if (sum.imag > 0) cout << "+" << sum.imag << "i\n";
    else if (sum.imag == 0) cout << endl;
    else cout << sum.imag << "i\n";
    system("pause");
    return 0;
}