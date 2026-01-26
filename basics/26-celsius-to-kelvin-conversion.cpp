#include <iostream>
using namespace std;

int main() {
    double celsius, kelvin;
    const double OFFSET = 273.15;

    cout << "Enter temperature in Celsius: ";
    cin >> celsius;

    // Intelligence check: Cannot be colder than Absolute Zero
    if (celsius < -273.15) {
        cout << "Error: That temperature is physically impossible!" << endl;
    } else {
        kelvin = celsius + OFFSET;
        cout << celsius << "°C is equal to " << kelvin << " K" << endl;
    }

    return 0;
}