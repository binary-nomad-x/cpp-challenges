#include <iostream>
using namespace std;

int main() {
    int radius;

    cout << "Enter radius cm: ";

    cin >> radius;

    const double volume = (4.0 / 3.0) * (22.0 / 7.0) * (radius * radius * radius);

    cout << "Volume of cube is : " << volume << " cm^3" << endl;

    return 0;
}
