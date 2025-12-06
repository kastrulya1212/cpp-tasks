//  Task 1 (Лаб 11, #1) 

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string>
#include <vector>

using namespace std;



template <typename T>
constexpr auto isSimple = [] (T num) constexpr {
    if (num-1==0) return true;

    for (int i = 2; i<num; i++) {
        if (num%i==0) return false;
    }
    return true;
};

int main() {
    constexpr auto result = isSimple<int>(7 );
    cout << result << endl;
}