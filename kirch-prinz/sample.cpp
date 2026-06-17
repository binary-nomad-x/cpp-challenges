#include <iostream>
#include <climits>
#include <cfloat>

using namespace std;

void pause() {
    // page: 12
    cout << "BREAK" << endl;
}

void allTyps() {
    // page: 18

    // boolean
    bool demo;

    // charts
    char16_t demo2;
    char32_t demoooo;
    wchar_t charssss;

    // integers
    short demooooooooooo = -12222;
    int rewrqwer;
    long erwerew;

    // for floating point values
    float adsfasfd;
    double adsfsadfadsf;
    long double adsfsadfsadf;
}

void showLimitsOfDataTypes() {
    // page: 18
    cout << "int max " << INT_MAX << endl;
    cout << "int min" << INT_MIN << endl;
    cout << "unsigned int max " << UINT_MAX << endl;
    cout << "short min " << SHRT_MIN << endl;
    cout << "short max " << SHRT_MAX << endl;
    cout << "unsinged short max " << USHRT_MAX << endl;
    cout << "double max " << DBL_MAX << endl;
    cout << "double min " << DBL_MIN << endl;
    cout << "float epsilon" << FLT_EPSILON << endl;

    cout << "------------- other types --------------" << endl;
    cout << sizeof(unsigned int) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(unsigned short) << endl;
    cout << sizeof(long long) << endl;
}

void escapedString() {
    cout << "\nthis is \t a string \n\t\t with \"many\" escape sequences!!! \n";
}

int main() {
    // current page : 32

    return 0;
}
