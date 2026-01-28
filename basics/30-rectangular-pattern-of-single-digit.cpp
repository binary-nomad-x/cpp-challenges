#include <iostream>
using namespace std;


int main() {
    
    int digit, rows, cols;

    cout << "--- Rectangular Pattern Generator ---" << endl;

    // Get the digit to repeat
    cout << "Enter a single digit (0-9): ";
    cin >> digit;

    // Get dimensions
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "\nResulting Pattern:\n" << endl;

    // Nested loop logic
    for (int i = 0; i < rows; i++) {       // Outer loop for rows
        for (int j = 0; j < cols; j++) {   // Inner loop for columns
            cout << digit; 
        }
        cout << endl; // Move to the next line after each row is printed
    }

    return 0;
}