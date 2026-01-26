#include <iostream>
using namespace std;

int main()
{

    int l;
    cout << "Enter length of single side (cm) : ";

    cin >> l;

    double v = l * l * l;

    cout << "volumen of cube : " << v << " cm^3" << endl;

    return 0;
}