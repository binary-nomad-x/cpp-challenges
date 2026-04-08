#include <iostream>
#include <iomanip>
#include <cmath> // For M_PI and pow()

using namespace std;

int main() {
    double radius;

    // Using cmath's pi is more precise, but if not available, your constexpr is perfect.
    // M_PI is a common macro, but since it's not standard C++, your constant is safer.
    constexpr double PI = 3.14159265358979323846;

    cout << "Circle Property Calculator" << endl;
    cout << "--------------------------" << endl;
    cout << "Enter radius (cm): ";

    // Check if input is a valid positive number
    if (!(cin >> radius) || radius < 0) {
        cout << "Error: Please enter a valid positive number for the radius." << endl;
        return 1;
    }

    // Calculations
    // Using pow(radius, 2) is an alternative, but radius * radius is faster!
    const double circumference = 2 * PI * radius;
    const double area = PI * radius * radius;

    // Output formatting
    cout << "\nResults:" << endl;
    cout << fixed << setprecision(2);
    cout << " > Circumference: " << circumference << " cm" << endl;
    cout << " > Area:          " << area << " sq cm" << endl;
    cout << "--------------------------" << endl;

    return 0;
}
