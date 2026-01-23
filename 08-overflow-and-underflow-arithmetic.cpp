#include <iostream>
using namespace std;

// Write a C++ program to check overflow/underflow during various arithmetic operations.

#include <iostream>
#include <climits> // INT_MIN aur INT_MAX ke liye

using namespace std;

int main()
{
    int n; // Badi range use karein taake check kar sakein

    cout << "Enter a number : ";
    if (!(cin >> n))
    {
        // Agar user ne alphabet ya koi ajeeb cheez daali
        cout << "Not an integer but something else" << endl;
    }
    else if (n < INT_MIN || n > INT_MAX)
    {
        cout << "Range of int is [" << INT_MIN << ", " << INT_MAX << "]" << endl;
        cout << "Your number is out of range!" << endl;
    }
    else
    {
        cout << "Valid integer: " << n << endl;
    }

    return 0;
}

// Sample Output:
// Check overflow/underflow during various arithmetical operation :
// Range of int is [-2147483648, 2147483647]
