// CASE 1

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string>

using namespace std;


template<typename Type> 
bool compare(Type obj1, Type obj2)
{
    return obj1 == obj2;
}


int main()
{
    int a1 = 5, a2 = 5;
    char b1 = 'C', b2 = 'c';
    double c1 = 12.5, c2 = 12.5;

    cout << compare(a1, a2) << " " << compare(b1, b2) << " " << compare(c1, c2) << endl; 
}