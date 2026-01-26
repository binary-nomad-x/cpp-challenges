#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double km, miles;
    const double KM_TO_MILES_FACTOR = 0.621371;

    cout << "Enter distance in Kilometers: ";
    cin >> km;

    miles = km * KM_TO_MILES_FACTOR;

    cout << fixed << setprecision(2);
    cout << km << " km is approximately " << miles << " miles." << endl;

    return 0;
}