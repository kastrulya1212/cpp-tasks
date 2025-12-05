//  Task 3 (Лаб 10, #3) in process...

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string>
#include <vector>

using namespace std;


template<typename Func, typename Arg>
void forEach(Func func, Arg arg) {
    func(arg);
}

template<typename Func, typename First, typename... Other>
void forEach(Func&& func, First&& first, Other&&... other) {
    func(first);
    forEach(func, other...);
}


template<typename T>
void addNum(T& num) {
    num *= 10;
}

int main() {
    int a = 1, b = 2, c = 3;
    forEach(addNum, a, b ,c);
}