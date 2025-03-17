#include <iostream>
using namespace std;
#define PRINT(a, b)                         \
    cout << a << "+" << b << "i" << endl;
struct Complex {
    int real;
    int imaginary;
};
void print_complex(Complex z) {
    PRINT(z.real, z.imaginary);
}
void add(Complex a, Complex b) {
    int r = a.real + b.real;
    int i = a.imaginary + b.imaginary;
    PRINT(r, i);
}
int main() {
    Complex x, y;
    cin >> x.real >> x.imaginary >> y.real >> y.imaginary;
    print_complex(x);
    print_complex(y);
    add(x, y);
    system("pause");
    return 0;
}