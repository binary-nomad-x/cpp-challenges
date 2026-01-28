#include <iostream>
#include <cmath> // Required for sqrt()
using namespace std;

int main() {
    double a, b, c;

    cout << "Enter the three sides of the triangle: ";
    cin >> a >> b >> c;

    // Intelligence check: Can these sides actually form a triangle?
    if (a + b > c && a + c > b && b + c > a) {
        const double s = (a + b + c) / 2.0;

        const double area = sqrt(s * (s - a) * (s - b) * (s - c));

        cout << "The Area using Heron's Formula is: " << area << endl;
    } else {
        cout << "Error: These sides do not form a valid triangle." << endl;
    }

    return 0;
}
