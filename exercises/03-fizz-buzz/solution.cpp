#include <iostream>
#include <vector>
#include <string>

using namespace std;

static vector<string> fizzBuzz(const int n) {
    vector<string> result;

    for (int i = 1; i <= n; i++) {
        if (i % 15 == 0) {
            result.emplace_back("FizzBuzz");
        } else if (i % 3 == 0) {
            result.emplace_back("Fizz");
        } else if (i % 5 == 0) {
            result.emplace_back("Buzz");
        } else {
            result.push_back(to_string(i));
        }
    }

    return result;
}

int main() {
    constexpr int n = 15;
    const vector<string> result = fizzBuzz(n);

    for (const string &s: result) {
        cout << s << endl;
    }

    return 0;
}
