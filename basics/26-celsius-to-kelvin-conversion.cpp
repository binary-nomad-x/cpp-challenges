#include <iostream>
using namespace std;

int main() {
    double celsius;

    cout << "Enter temperature in Celsius: ";
    cin >> celsius;

    // Intelligence check: Cannot be colder than Absolute Zero
    if (celsius < -273.15) {
        cout << "Error: That temperature is physically impossible!" << endl;
    } else {
        constexpr double OFFSET = 273.15;
        const double kelvin = celsius + OFFSET;
        cout << celsius << "°C is equal to " << kelvin << " K" << endl;
    }

    return 0;
}