//  Task 1 (Лаб 10, #1)

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

template<typename T> 
T maxOf(T&& value) {
    return value;
}

template<class First, class... Other>
auto maxOf(First first, Other... other) {
    return (first > maxOf(other...) ? first : maxOf(other...));
}


int main() {
    cout << maxOf(3, 2, 11, 1, 4) << endl;
}