#include <iostream>
using namespace std;

int main()
{
    int a, b, temp;

    cout << "Enter a : ";
    cin >> a;

    cout << "Enter b : ";
    cin >> b;

    temp = a;
    a = b;
    b = temp;

    cout << "swapped values : " << endl;

    cout << "a : " << a << endl;

    cout << "b : " << b << endl;

    return 0;
}