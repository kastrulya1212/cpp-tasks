//  Task 4 (Лаб 11, #4) 

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

template <typename T>
constexpr auto fib = [] (T num) constexpr {
    auto n1 = 1, n2 = 1, count = 2;
    auto result = 0;

    if (num == 1 || num == 2) return 1;

    while (count < num) {
        result = n1 + n2;
        n1 = n2;
        n2 = result;

        count++;
    }
    return result;
};

int main() {
    constexpr auto result = fib<int>(7);
    cout << result << endl;

    // (1) (1) (1 + 1 = 2) (1 + 2 = 3) (2 + 3 = 5) (3 + 5 = 8) (5 + 8 = 13)
}