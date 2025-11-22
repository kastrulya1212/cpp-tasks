// TASK 1

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string>
#include <vector>

using namespace std;



string decode_string(string s, int index) {
    string result;


    while (index<s.length() && s[index]!=']') {
        if (isdigit(s[index])) {
            int k = 0;
            while (index < s.length() && isdigit(s[index])) {
                k = k * 10 + stoi(to_string(s[index]));
                index++;
            }

            index++;

            string inner = decode_string(s, index);

            index++;

            for (int i = 0; i < k; i++) {
                result += inner;
            }
        }
        else {
            result += s[index];
            index++;
        }
    }
    return result;
}

string decode_string(string s) {
    int index = 0;
    return decode_string(s, index);
}



int main() {
    cout << decode_string("3[a]2[bc]") << endl;
}