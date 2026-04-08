#include <iostream>
#include <iomanip> // For formatting output

using namespace std;

int main() {
    double angle1, angle2;

    // Stylish header
    cout << "=====================================" << endl;
    cout << "   Triangle Third Angle Calculator   " << endl;
    cout << "=====================================" << endl;

    // Input with clear prompts
    cout << "Enter the first angle:  ";
    if (!(cin >> angle1)) return 1; // Basic check for non-numeric input

    cout << "Enter the second angle: ";
    if (!(cin >> angle2)) return 1;

    cout << "-------------------------------------" << endl;

    // Validation Logic
    // A triangle's angles must be positive and their sum must be less than 180
    if (angle1 > 0 && angle2 > 0 && (angle1 + angle2) < 180) {
        double const angle3 = 180.0 - (angle1 + angle2);
        cout << "Success! The third angle is: " << fixed << setprecision(2) << angle3 << "°" << endl;
    } else {
        cout << "Error: Invalid input." << endl;
        cout << "Note: Angles must be positive and their sum must be less than 180°." << endl;
    }

    cout << "=====================================" << endl;

    return 0;
}
