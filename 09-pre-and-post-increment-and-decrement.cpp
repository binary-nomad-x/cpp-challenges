#include <iostream>
using namespace std;

int main()
{
    int n = 57;

    cout << "the number is : " << n << endl;

    // int post_incremented = n++; // n value is passd and then the n is incremented by 1

    // UNDEFINED BEHAVIOUR
    // | ^
    // 9-pre-and-post-increment-and-decrement.cpp:6:9: note: 'int n' previously declared here
    //     6 |     int n = 57;
    //       |         ^
    // PS C:\projects\cpp\leanring\basic>

    // WE WONT USE A THIRD VARIABLE post_incremented,
    // WE CAN POST & PRE INCREMENTED WITHOUT ASSIGNING TO ANOTHER VARIABLE

    // cout << "after the post increment : " << post_incremented << endl;

    n++;

    cout << "The value after POST INCREMENTED : " << n << endl;

    --n;

    cout << "The value after PRE INCREMENT : " << n << endl;

    // Direct addition
    n = n + 1;
    cout << "After increasing by 1 the number is : " << n << endl;

    // Post-decrement: Pehle use, phir kam
    n--;
    cout << "After post decrement by 1 the number is : " << n << endl;

    // Pre-decrement: Pehle kam, phir use
    --n;
    cout << "After pre decrement by 1 the number is : " << n << endl;

    // Direct subtraction
    n = n - 1;
    cout << "After decreasing by 1 the number is : " << n << endl;

    return 0;
}
