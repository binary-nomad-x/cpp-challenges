#include <iostream>
#include <iomanip> // Decimal points ko control karne ke liye

using namespace std;

int main() {
    cout << "Check whether the primitive values crossing the limits or not :" << endl;
    cout << "--------------------------------------------------------------------" << endl;

    // 1. Character (Single letter ke liye)
    constexpr char gender = 'F';

    // 2. Boolean (True/False ya 0/1 ke liye)
    constexpr bool isMarried = true;

    // 3. Short (Choti values ke liye memory bachata hai)
    constexpr short sons = 2;

    // 4. Int (Years ya normal numbers ke liye)
    constexpr int yearOfAppt = 2009;

    // 5. Long (Bari salary values ke liye)
    constexpr long yearlySalary = 1500000;

    // 6. Float (Decimal values ke liye - iske end mein 'f' likhte hain)
    constexpr float height = 79.48f;

    // 7. Double (Zyada precision wale decimal ke liye)
    constexpr double gpa = 4.69;

    // 8. Long Long (Bohat baray numbers ke liye - 64 bit)
    constexpr long long salaryDrawn = 12047235LL;
    constexpr long long balance = 995324987LL;

    // Outputting the values
    cout << "The Gender is : " << gender << endl;
    cout << "Is she married? : " << isMarried << endl;
    cout << "Number of sons she has : " << sons << endl;
    cout << "Year of her appointment : " << yearOfAppt << endl;
    cout << "Salary for a year : " << yearlySalary << endl;
    cout << "Height is : " << height << endl;
    cout << "GPA is " << gpa << endl;
    cout << "Salary drawn upto : " << salaryDrawn << endl;
    cout << "Balance till : " << balance << endl;

    return 0;
}
