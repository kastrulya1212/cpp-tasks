// TASK 6

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string>
#include <vector>

using namespace std;


int shortest_triangle_path(vector<vector<int>> triangle) {
    int prev_index = 0;
    int path = triangle[0][0];
    for (int i = 1; i < triangle.size(); i++) {
        if (triangle[i].size() > prev_index+1) {
            path += min(triangle[i][prev_index], triangle[i][prev_index+1]);
        }
        else {
            path += triangle[i][prev_index];
        }
    }
    return path;
}


int main() {
    vector<vector<int>> arr = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << shortest_triangle_path(arr) << endl;
}