// CASE 6

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string>

using namespace std;


// NOT READY YET
// NOT READY YET
// NOT READY YET

template<typename Type> 
void quick_sort(Type arr[], int size)
{
    if (size <= 1) return;
    
    // Selecting pivot element
    Type pivot = arr[size / 2];
    
    int left = 0;
    int right = size - 1;
    
    // Divided array (cause defaul quick sort create new mini-array every 
    // itteration, which is almost impossible to realize with dynamic arrays, so the 
    // only way to solve it - use other "quick sort" version without arrays)
    while (left <= right) {
        while (arr[left] < pivot) left++;
        while (arr[right] > pivot) right--;
        
        if (left <= right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
}


int main()
{
    int intArr[] = {64, 34, 25, 12, 22, 11, 90};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);

    quick_sort<int>(intArr, )
}