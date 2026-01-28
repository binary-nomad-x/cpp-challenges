#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double kelvin;

    cout << "Enter temperature in Kelvin: ";
    cin >> kelvin;

    // Check if temperature is below Absolute Zero
    if (kelvin < 0) {
        cout << "Error: Temperature cannot be below 0 Kelvin (Absolute Zero)." << endl;
    } else {
        constexpr double KELVIN_OFFSET = 273.15;
        const double fahrenheit = (kelvin - KELVIN_OFFSET) * 1.8 + 32;

        cout << fixed << setprecision(2);
        cout << kelvin << " K is equal to " << fahrenheit << "°F" << endl;
    }

    return 0;
}
