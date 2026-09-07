#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

namespace {
    constexpr auto RESET = "\033[0m";
    constexpr auto BOLD = "\033[1m";
    constexpr auto CYAN = "\033[36m";
    constexpr auto GREEN = "\033[32m";
    constexpr auto YELLOW = "\033[33m";
    constexpr auto RED = "\033[31m";
    constexpr auto BLUE = "\033[34m";

    void clearScreen() {
        cout << "\033[2J\033[H";
    }

    void header() {
        cout << CYAN << BOLD
                << "╔══════════════════════════════════════════╗\n"
                << "║       MULTIPLICATION TABLE APP 🚀       ║\n"
                << "╚══════════════════════════════════════════╝\n"
                << RESET;
    }

    void menu() {
        cout << '\n'
                << BLUE << "  1." << RESET << " Single Table\n"
                << BLUE << "  2." << RESET << " Range of Tables\n"
                << BLUE << "  3." << RESET << " Exit\n\n"
                << YELLOW << "  Choose an option: " << RESET;
    }

    int getInt(const string &prompt) {
        int value;

        while (true) {
            cout << prompt;

            if (cin >> value) {
                return value;
            }

            cout << RED << "  ✗ Invalid input. Enter a number.\n" << RESET;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    void pause() {
        cout << '\n' << YELLOW << "  Press Enter to continue..." << RESET;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    void printTable(const int number, const int limit) {
        cout << '\n'
                << GREEN << BOLD
                << "  Multiplication Table: " << number
                << RESET << '\n'
                << "  ─────────────────────────\n";

        for (int i = 1; i <= limit; ++i) {
            cout << "  "
                    << setw(4) << number << " × "
                    << setw(2) << i << " = "
                    << setw(6) << number * i << '\n';
        }

        cout << "  ─────────────────────────\n";
    }

    void printRange(const int start, const int end, const int limit) {
        cout << '\n'
                << GREEN << BOLD
                << "  Tables: " << start << " → " << end
                << RESET << "\n\n";

        for (int i = 1; i <= limit; ++i) {
            for (int number = start; number <= end; ++number) {
                cout << "  "
                        << setw(3) << number
                        << " × "
                        << setw(2) << i
                        << " = "
                        << setw(5) << number * i;
            }
            cout << '\n';
        }
    }

    void singleTable() {
        const int number = getInt("  Enter number: ");
        const int limit = getInt("  Enter limit: ");

        if (limit < 1) {
            cout << RED << "  ✗ Limit must be greater than 0.\n" << RESET;
            return;
        }

        printTable(number, limit);
    }

    void rangeTables() {
        int start = getInt("  Enter start: ");
        int end = getInt("  Enter end: ");

        if (start > end)
            swap(start, end);

        const int limit = getInt("  Enter limit: ");

        if (limit < 1) {
            cout << RED << "  ✗ Limit must be greater than 0.\n" << RESET;
            return;
        }

        printRange(start, end, limit);
    }
}

int main() {
    while (true) {
        clearScreen();
        header();
        menu();

        const int choice = getInt("");

        switch (choice) {
            case 1:
                singleTable();
                pause();
                break;

            case 2:
                rangeTables();
                pause();
                break;

            case 3:
                cout << '\n'
                        << GREEN << BOLD
                        << "  ✓ Thanks for using the app! Goodbye 👋\n"
                        << RESET;
                return 0;

            default:
                cout << RED << "  ✗ Invalid choice. Try again.\n" << RESET;
                pause();
        }
    }
}
