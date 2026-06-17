#include <iostream>
#include <iomanip> // For better formatting

using namespace std;

int main() {
    // Initializing the starting value
    int num = 57;
    cout << "Initial Number: " << num << endl;
    cout << "-----------------------------" << endl;

    // 1. Post-Increment: Increments after the current line
    num++;
    cout << "After Post-Increment (num++): " << num << endl;

    // 2. Pre-Decrement: Decrements before the next operation
    --num;
    cout << "After Pre-Decrement (--num):  " << num << endl;

    // 3. Direct Addition: Explicitly adding 1
    num = num + 1;
    cout << "After Direct Addition (+1):   " << num << endl;

    // 4. Post-Decrement: Decrements after the current line
    num--;
    cout << "After Post-Decrement (num--): " << num << endl;

    // 5. Pre-Decrement: Decrements before the next operation
    --num;
    cout << "After Pre-Decrement (--num):  " << num << endl;

    // 6. Direct Subtraction: Explicitly subtracting 1
    num = num - 1;
    cout << "After Direct Subtraction (-1): " << num << endl;

    return 0;
}
