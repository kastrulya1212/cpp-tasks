//  Task 2 (Лаб 11, #2) 

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

template <typename T1, typename T2>
constexpr auto maxCommonDiv = [] (T1 num1, T2 num2) constexpr {
    auto result = 0;
    
    if (num1==0 || num2==0) return max(num1, num2);
    if (num1==1 || num2==1) return 1;

    for (int i = min(num1, num2); i > 0; i--) {
        if (num1%i==0 && num2%i==0) return i;
    }
    return 1;
};

int main() {
    constexpr auto result = maxCommonDiv<int, int>(0, 15);
    cout << result << endl;
}