#include <iostream>
using namespace std;

int main() {
    double radius, height;
    constexpr double PI = 3.14159265;

    cout << "Enter radius (cm): ";
    cin >> radius;
    cout << "Enter height (cm): ";
    cin >> height;

    double const v = PI * (radius * radius) * height;

    cout << "Volume of the cylinder is: " << v << " cm^3" << endl;

    return 0;
}
