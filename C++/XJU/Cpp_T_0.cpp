#include <iostream>
using namespace std;
#define PRINT(a, b)                           \
    if (b > 0)                                \
        cout << a << "+" << b << "i" << endl; \
    else if (b == 0)                          \
        cout << a << endl;                    \
    else                                      \
        cout << a << b << "i" << endl;
struct Complex {
    int real;
    int imag;
};
void print_complex(Complex z) {
    PRINT(z.real, z.imag);
}
void add(Complex a, Complex b) {
    int r = a.real + b.real;
    int i = a.imag + b.imag;
    PRINT(r, i);
}
int main() {
    Complex x, y;
    cin >> x.real >> x.imag >> y.real >> y.imag;
    print_complex(x);
    print_complex(y);
    add(x, y);
    system("pause");
    return 0;
}