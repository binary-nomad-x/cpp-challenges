### Coding Challenge: FizzBuzz

---

#### **Problem Statement**

Write a program that prints the numbers from `1` to `n`. But for multiples of `3` print `"Fizz"` instead of the number, for multiples of `5` print `"Buzz"`, and for numbers which are multiples of both `3` and `5` print `"FizzBuzz"`.

#### **Constraints**

1. `1 <= n <= 10^4`
2. Output each result on a new line.

---

#### **Example**

**Input:** `n = 15`

**Output:**
```
1
2
Fizz
4
Buzz
Fizz
7
8
Fizz
Buzz
11
Fizz
13
14
FizzBuzz
```

---

#### **Starter Template (C++)**

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> fizzBuzz(int n) {
    // Write your logic here

    return {};
}

int main() {
    int n = 15;
    vector<string> result = fizzBuzz(n);

    for (const string& s : result) {
        cout << s << endl;
    }

    return 0;
}
```

---

#### **Hint**

Use the modulo operator `%`. Check divisibility by 15 first, then 3, then 5.
