//  Task 2 (Лаб 10, #2)

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string>
#include <vector>

using namespace std;


template<typename T>
T minOf(T value) {
    return value;
}

template<class First, class... Other>
auto minOf(First first, Other... other) {
    return (first < minOf(other...) ? first : minOf(other...));
}


int main() {
    cout << minOf(1, 5, -100, 7, 2, 10, 3) << endl;
}