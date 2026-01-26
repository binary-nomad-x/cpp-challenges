#include <iostream>
using namespace std;

int main()
{
    double r, h;
    const double PI = 3.14159265;

    cout << "Enter radius (cm): ";
    cin >> r;
    cout << "Enter height (cm): ";
    cin >> h;

    double v = PI * (r * r) * h;

    cout << "Volume of the cylinder is: " << v << " cm^3" << endl;

    return 0;
}