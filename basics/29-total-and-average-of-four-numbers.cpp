#include <iostream>
#include <iomanip> // For controlling decimal precision

using namespace std;

int main() {
    double n1, n2, n3, n4;
    double total, average;

    cout << "--- Total and Average Calculator ---" << endl;

    // Input section
    cout << "Enter four numbers separated by spaces: ";
    if (!(cin >> n1 >> n2 >> n3 >> n4)) {
        cout << "Invalid input. Please enter numeric values." << endl;
        return 1;
    }

    // Calculations
    total = n1 + n2 + n3 + n4;
    average = total / 4.0;

    // Output section
    cout << fixed << setprecision(2); // Set output to 2 decimal places
    cout << "------------------------------------" << endl;
    cout << "Total   : " << total << endl;
    cout << "Average : " << average << endl;
    cout << "------------------------------------" << endl;

    return 0;
}