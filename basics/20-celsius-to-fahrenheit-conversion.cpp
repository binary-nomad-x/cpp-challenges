#include <iostream>
using namespace std;

int main()
{
    double celsius;

    cout << "Enter temperature in Celsius: ";
    cin >> celsius;

    // Use 1.8 or (9.0 / 5.0) to ensure floating-point math
    const double fahrenheit = (celsius * 1.8) + 32;

    cout << celsius << "°C is equal to " << fahrenheit << "°F" << endl;

    return 0;
}