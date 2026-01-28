#include <iostream>
using namespace std;

int main() {
    int numOne, numTwo;

    cout << "Enter a : ";
    cin >> numOne;

    cout << "Enter b : ";
    cin >> numTwo;

    const int temp = numOne;
    numOne = numTwo;
    numTwo = temp;

    cout << "swapped values : " << endl;

    cout << "a : " << numOne << endl;

    cout << "b : " << numTwo << endl;

    return 0;
}
