#include <iostream>
// #include <climits> // is ki zroort ni shayd
using namespace std;

// min max limits of integer types
int main()
{
    cout << "maximum limit of int type : " << INT_MAX << endl;

    cout << "minimium limit int type : " << INT_MIN << endl;

    cout << "max of unsinged int type : " << UINT_MAX << endl;

    cout << "max of long long type : " << LONG_LONG_MAX << endl;

    cout << "min of long long type : " << LONG_LONG_MIN << endl;

    cout << "max of long long type : " << ULONG_LONG_MAX << endl;

    cout << "max bits of char type : " << CHAR_BIT << endl;

    cout << "max limit char type : " << CHAR_MAX << endl;

    cout << "minimum of char type : " << CHAR_MIN << endl;

    cout << "max of signed char : " << UCHAR_MAX << endl;

    cout << "max of short type : " << SHRT_MAX << endl;

    cout << "min short type : " << SHRT_MIN << endl;

    cout << "max of unsigned short type : " << USHRT_MAX;
}

/*
maximum limit of int type : 2147483647
minimium limit int type : -2147483648
max of unsinged int type : 4294967295
max of long long type : 9223372036854775807
min of long long type : -9223372036854775808
max of long long type : 18446744073709551615
max bits of char type : 8
max limit char type : 127
minimum of char type : -128
max of signed char : 255
max of short type : 32767
min short type : -32768
max of unsigned short type : 65535

*/