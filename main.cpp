#include <iostream>
#include <iomanip> // Used for formatting (setw, setfill)
#include <limits>  // Used for input validation (numeric_limits)
#include <cstdlib> // Used for system("cls") / system("clear")

using namespace std;

// --- Function: Clear the Screen ---
void clearScreen()
{
// Check if running on Windows or Linux/Mac
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// --- Function: Print the Main Menu ---
void printMenu()
{
    cout << "==========================================\n";
    cout << "      MULTIPLICATION TABLE APP v2.0      \n";
    cout << "==========================================\n";
    cout << "1. Print Single Table (e.g., 5 x 10)\n";
    cout << "2. Print Range of Tables (e.g., 2 to 5)\n";
    cout << "3. Exit\n";
    cout << "==========================================\n";
    cout << "Enter your choice: ";
}

// --- Function: Validate Integer Input ---
// This ensures user types a number, not letters
int getValidInt(const string &prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        if (cin >> value)
        {
            return value; // Success
        }
        else
        {
            cout << "❌ Invalid input! Please enter a number.\n";
            cin.clear();                                         // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
        }
    }
}

// --- Function: Print a Single Table nicely ---
void printSingleTable(int number, int limit)
{
    cout << "\n";
    cout << "Multiplication Table for: " << number << "\n";
    cout << "----------------------------\n";

    // setw(15) sets width to 15 characters for alignment
    for (int i = 1; i <= limit; i++)
    {
        cout << setw(3) << number << "  x "
             << setw(2) << i << "  = "
             << setw(5) << (number * i) << endl;
    }
    cout << "----------------------------\n";
}

// --- Function: Print a Range of Tables (e.g., 2 to 5) ---
void printMultipleTables(int start, int end, int limit)
{
    cout << "\nPrinting tables from " << start << " to " << end << ":\n";
    cout << "=========================================================\n";

    for (int i = 1; i <= limit; i++)
    {
        for (int num = start; num <= end; num++)
        {
            // Print: 2x1=2   3x1=3   4x1=4
            cout << num << "x" << i << "=" << setw(4) << (num * i) << "   ";
        }
        cout << endl; // New line after every row
    }
    cout << "=========================================================\n";
}

// --- Main Function ---
int main()
{
    int choice;
    bool running = true;

    while (running)
    {
        clearScreen();
        printMenu();

        choice = getValidInt("");

        if (choice == 1)
        {
            // --- Option 1: Single Table ---
            int number = getValidInt("Enter the number: ");
            int limit = getValidInt("Enter the limit (e.g., 10): ");

            printSingleTable(number, limit);
        }
        else if (choice == 2)
        {
            // --- Option 2: Multiple Tables ---
            int start = getValidInt("Enter start number: ");
            int end = getValidInt("Enter end number: ");

            // Logic to ensure start is smaller than end
            if (start > end)
            {
                int temp = start;
                start = end;
                end = temp;
                cout << "Swapping values...\n";
            }

            int limit = getValidInt("Enter limit (e.g., 10): ");
            printMultipleTables(start, end, limit);
        }
        else if (choice == 3)
        {
            // --- Option 3: Exit ---
            running = false;
            cout << "\nThank you for using the app! Goodbye 👋\n";
        }
        else
        {
            cout << "Invalid choice! Please try again.\n";
        }

        if (running)
        {
            cout << "\nPress Enter to continue...";
            cin.ignore(); // Wait for Enter key
            cin.get();
        }
    }

    return 0;
}