#include <iostream>
#include <climits>
#include <cfloat>

using namespace std;

static void pause() {
    // page: 12
    cout << "BREAK" << endl;
}

static void allTyps() {
    // page: 18

    bool booleanValue;

    // 8 bit
    char singleCharSingleQuoted;

    // charts
    char16_t demo2;
    char32_t demoooo;
    wchar_t widtCharacter; // 16 bit

    // integers
    short shortNumber_16bits = -12222;
    int interger_16bits;
    long longInteger_32bits;

    long long longLongInterger_64bits = 213243214;

    // for floating point values
    // single precision float value => 6 significant digits
    float singlePrecisionFloat;

    // double precision float, 10 significant digits
    double doublePrecisionFloat;

    // 10 significant digits
    long double extendedPrecisionFloatingPoint;
}

static void showLimitsOfDataTypes() {
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

static void escapedString() {
    cout << "\nthis is \t a string \n\t\t with \"many\" escape sequences!!! \n";
}

int main() {
    // current page : 32

    return 0;
}
