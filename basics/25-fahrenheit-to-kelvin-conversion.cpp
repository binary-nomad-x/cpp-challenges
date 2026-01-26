#include <iostream>
using namespace std;

int main() {
    double kelvin, celsius;
    const double OFFSET = 273.15;

    cout << "Enter temperature in Kelvin: ";
    cin >> kelvin;

    // Intelligence check: You can't go below Absolute Zero
    if (kelvin < 0) {
        cout << "Error: Physics doesn't allow temperatures below 0 K!" << endl;
    } else {
        celsius = kelvin - OFFSET;
        cout << kelvin << " K is equal to " << celsius << "°C" << endl;
    }

    return 0;
}