// TASK 9

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

int BUG_EXIT = 1000;

string who_win(string senate) {
    int exit_i = 0;
    while (exit_i < BUG_EXIT) {

        // counting senators
        
    
        // Checking if there is no opponents
        cout << senate << endl;
        
    
    
        // Senator choice
        int i = 0;
        while (i < senate.length()) {
            if (i >= senate.length()) break;

            char senator = senate.at(i);
            cout << senator << " " << senate << endl;
    
            if (senator == 'R') {   // RDDRRR  ---  
                if (i < senate.length()-1) {
                    string sub_senate = senate.substr(i+1, senate.size());
                    auto ind = sub_senate.find('D');
                    cout << sub_senate << " " << ind << endl;
                    senate.erase(i + ind + 1, 1);
                }
                else {
                    auto ind  = senate.find('D');
                    cout << senate << " " << ind << endl;
                    senate.erase(ind, 1);
                }
            }
            else {
                if (i < senate.length()-1) {
                    string sub_senate = senate.substr(i+1, senate.size());
                    auto ind = sub_senate.find('R');
                    cout << sub_senate << " " << ind << endl;
                    senate.erase(i + ind + 1, 1);
                }
                else {
                    auto ind  = senate.find('R');
                    cout << senate << " " << ind << endl;
                    senate.erase(ind, 1);
                }
            }
            i++;

            int r_count=0, d_count=0;
            for (int j = 0; j<senate.length(); j++) {
                if (senate.at(j)=='R') r_count++;
                else d_count++;
            }

            if (r_count == 0) return "Dire";
            if (d_count == 0) return "Radiant";
        }
        exit_i++;
    }
    return "None";
}


int main() {
    string senate = "RDD";      // RR
    cout << who_win(senate) << endl;
}