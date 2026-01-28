#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter a number : ";
    cin >> n;

    if (n > 0)
    {
        cout << "Positive";
    }
    else if (n == 0)
    {
        cout << "zero";
    }
    else if (n < 0)
    {
        cout << "negative";
    }

    cout << endl;

    return 0;
}