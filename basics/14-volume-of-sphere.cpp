#include <iostream>
using namespace std;

int main()
{
    int r;

    cout << "Enter radius cm: ";

    cin >> r;

    double v = (4.0 / 3.0) * (22.0 / 7.0) * (r * r * r);

    cout << "Volume of cube is : " << v << " cm^3" << endl;

    return 0;
}