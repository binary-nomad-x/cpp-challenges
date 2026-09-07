#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double fahrenheit;

    cout << "Enter temperature in Fahrenheit: ";
    cin >> fahrenheit;

    // Parentheses are vital here!
    const double celsius = (fahrenheit - 32) * (5.0 / 9.0);

    cout << fixed << setprecision(1);
    cout << fahrenheit << "°F is equal to " << celsius << "°C" << endl;

    return 0;
}