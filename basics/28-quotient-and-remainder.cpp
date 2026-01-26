#include <iostream>

using namespace std;

int main() {
    int a, b;

    cout << "--- Quotient and Remainder Calculator ---" << endl;

    // Input for the dividend
    cout << "Enter the dividend (a): ";
    if (!(cin >> a)) {
        cout << "Invalid input. Please enter an integer." << endl;
        return 1;
    }

    // Input for the divisor
    cout << "Enter the divisor (b): ";
    if (!(cin >> b)) {
        cout << "Invalid input. Please enter an integer." << endl;
        return 1;
    }

    // Safety check for division by zero
    if (b == 0) {
        cout << "Error: Division by zero is undefined!" << endl;
    } else {
        // Performing calculations
        int quotient = a / b;
        int remainder = a % b;

        cout << "-----------------------------" << endl;
        cout << "Quotient (a / b)  : " << quotient << endl;
        cout << "Remainder (a % b) : " << remainder << endl;
        cout << "-----------------------------" << endl;
    }

    return 0;
}