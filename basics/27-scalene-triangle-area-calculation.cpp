#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double a, b, c;

    cout << "Enter lengths of the three sides: " << endl;
    cin >> a >> b >> c;

    // The Triangle Inequality Check: Memory of geometry rules
    if ((a + b > c) && (a + c > b) && (b + c > a)) {
        double s = (a + b + c) / 2.0;
        double area = sqrt(s * (s - a) * (s - b) * (s - c));

        cout << fixed << setprecision(2);
        cout << "The area of the scalene triangle is: " << area << " units^2" << endl;
    } else {
        // Without this check, the result would be 'nan' (Not a Number)
        cout << "Error: These sides do not form a valid triangle!" << endl;
    }

    return 0;
}