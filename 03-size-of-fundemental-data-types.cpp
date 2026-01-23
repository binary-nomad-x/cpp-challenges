#include <iostream>
using namespace std;

int main()
{
    cout << "--- Size of Fundamental Data Types (in Bytes) ---" << endl;

    cout << "char       : " << sizeof(char) << " byte" << endl;
    cout << "bool       : " << sizeof(bool) << " byte" << endl;
    cout << "int        : " << sizeof(int) << " bytes" << endl;
    cout << "float      : " << sizeof(float) << " bytes" << endl;
    cout << "double     : " << sizeof(double) << " bytes" << endl;
    cout << "long long  : " << sizeof(long long) << " bytes" << endl;

    return 0;
}

/*
--- Size of Fundamental Data Types (in Bytes) ---
char       : 1 byte
bool       : 1 byte
int        : 4 bytes
float      : 4 bytes
double     : 8 bytes
long long  : 8 bytes
 */