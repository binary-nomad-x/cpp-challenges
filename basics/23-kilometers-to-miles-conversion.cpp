#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double kilometers;
    constexpr double KM_TO_MILES_FACTOR = 0.621371;

    cout << "Enter distance in Kilometers: ";
    cin >> kilometers;

    const double miles = kilometers * KM_TO_MILES_FACTOR;

    cout << fixed << setprecision(2);
    cout << kilometers << " km is approximately " << miles << " miles." << endl;

    return 0;
}
