#include <iostream>
using namespace std;

int main() {
    double kelvin;

    cout << "Enter temperature in Kelvin: ";
    cin >> kelvin;

    // Intelligence check: You can't go below Absolute Zero
    if (kelvin < 0) {
        cout << "Error: Physics doesn't allow temperatures below 0 K!" << endl;
    } else {
        constexpr double OFFSET = 273.15;
        const double celsius = kelvin - OFFSET;
        cout << kelvin << " K is equal to " << celsius << "°C" << endl;
    }

    return 0;
}
