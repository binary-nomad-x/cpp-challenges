#include <iostream>
using namespace std;

int main() {
    int length;
    cout << "Enter length of single side (cm) : ";

    cin >> length;

    double const volume = length * length * length;

    cout << "volumen of cube : " << volume << " cm^3" << endl;

    return 0;
}
