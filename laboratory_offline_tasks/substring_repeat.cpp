// TASK 2

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string>
#include <vector>
using namespace std;


string longest_sub_string(string str) {
    string ans_str;
    string sub_str = "";
    bool in_sub_flag;

    for (int l = 0; l < str.length(); l++) {
        sub_str = "";
        for (int i = l; i < str.length(); i++) {
            // check if sym already in sub
            in_sub_flag = false;
            for (int j = 0; j < sub_str.length(); j++) {
                if (sub_str.at(j) == str.at(i)) 
                    in_sub_flag = true;
            }
            // if it is already in, then skip and start new
            if (in_sub_flag) {
                if (sub_str.length() > ans_str.length()) {
                    ans_str = sub_str;
                }
                break;
            }
            else {
                // if it is not in sub
                sub_str.push_back(str.at(i));
            }
        }
        if (sub_str.length() > ans_str.length()) 
            ans_str = sub_str;
    }



    
    return ans_str;
}


int main() {
    string inp_str = "aaabccabcdaa";
    cout << longest_sub_string(inp_str) << endl ;
}