#include <cmath>
#include <iostream>
using namespace std;
const double PI = 3.14;
struct Annulus {
    double ri;
    double ro;
};
double s(Annulus a) {
    return (pow(a.ro, 2) - pow(a.ri, 2)) * PI;
}
double c(Annulus a) {
    return (a.ro + a.ri) * PI * 2;
}
int main() {
    Annulus a;
    cout << "Inner radius: ";
    cin >> a.ri;
    cout << endl << "Outer radius: ";
    cin >> a.ro;
    cout << "Area is " << s(a) << endl
         << "Circumference is " << c(a);
    system("pause");
    return 0;
}