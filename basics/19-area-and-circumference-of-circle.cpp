#include <iostream>
#include <iomanip> // For controlling decimal places
using namespace std;

int main()
{
    double r;
    const double PI = 3.14159265358979;

    cout << "Enter the radius of the circle (cm): ";
    cin >> r;

    double circumference = 2 * PI * r;
    double area = PI * (r * r);

    // Using fixed and setprecision(2) to make the output look clean
    cout << fixed << setprecision(2);
    cout << "Circumference: " << circumference << " cm" << endl;
    cout << "Area: " << area << " cm^2" << endl;

    return 0;
}