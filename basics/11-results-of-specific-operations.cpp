#include <iostream>
using namespace std;

int main() {
    constexpr int numOne = 14;
    constexpr int numTwo = 9;

    cout << "result of 1st expression : " << numOne / numTwo << endl;
    cout << "result of 2nd expression : " << numOne * numTwo << endl;
    cout << "result of 3rd expression : " << numOne + numTwo << endl;
    cout << "result of 1th expression : " << numOne - numTwo << endl;

    return 0;
}
