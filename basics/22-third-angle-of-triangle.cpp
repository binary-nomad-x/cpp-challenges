#include <iostream>
using namespace std;

int main() {
    double angle1, angle2, angle3;

    cout << "Enter the first angle: ";
    cin >> angle1;
    cout << "Enter the second angle: ";
    cin >> angle2;

    // Intelligence Check
    if (angle1 + angle2 < 180 && angle1 > 0 && angle2 > 0) {
        angle3 = 180 - (angle1 + angle2);
        cout << "The third angle is: " << angle3 << "°" << endl;
    } else {
        cout << "Error: These angles cannot belong to a triangle." << endl;
    }

    return 0;
}