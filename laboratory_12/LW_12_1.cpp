// Task 1 (задача про конфеты)

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string>
#include <vector>

using namespace std;


class Ratings {
    private:
        vector<int> rating;
    public:
        Ratings(vector<int> input);
        Ratings(Ratings& obj);
        void printRating();
        int calcMinCandies();
};

Ratings::Ratings(vector<int> input) {
    rating = input;
}

Ratings::Ratings(Ratings& obj) {
    rating = obj.rating;
}

void Ratings::printRating() {
    for (int i = 0; i < rating.size(); i++) {
        if (i == rating.size()-1) {
            cout << rating[i] << endl;
            break;
        }
        cout << rating[i] << ", ";
    }
}

int Ratings::calcMinCandies() {
    vector<int> candies_data = vector<int>(rating.size(), 1);

    // From left to right (if prev<curr, curr+1)
    for (int i = 1; i < rating.size(); i++) {
        if (rating[i-1] < rating[i]) {
            candies_data[i] = candies_data[i-1] + 1;
        }
    }

    // From right to left (if curr>prev and has <= candies, curr+1)
    for (int i = rating.size() - 1; i >= 0; i--) {
        if (rating[i] > rating[i+1]) {
            candies_data[i] = max(candies_data[i], candies_data[i+1]+1);
        }
    }

    int sum = 0;
    for (int i = 0; i < candies_data.size(); i++) 
        sum += candies_data[i];

    return sum;
}





int main() {
    vector<int> test1 = {1, 5, 4, 3, 2, 1};
    Ratings obj1 = Ratings(test1);
    obj1.printRating();

    cout << "ans: " << obj1.calcMinCandies() << endl;
}