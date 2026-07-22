#include <iostream>

// #include <format>

#include <string>

using namespace std;

int main() {
    // FORMATTING CPP NUMBERS
    // Method 	Safety	Best Use Case
    // std::format	High	Modern applications needing flexible, safe formatting.
    // <iomanip>	High	Console output and stream-based manipulation.
    // std::to_string	High	Quick, basic numeric conversion.
    // sprintf	Low	Legacy code or when working with C-style char buffers.

    std::string score = "Score: " + std::to_string(100);

    return 0;
}
