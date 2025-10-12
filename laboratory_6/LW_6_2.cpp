// CASE 2

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string>

using namespace std;

const int MAXIMUS_INT_PART_LEN = 64;
const int MAXIMUS_FRACTION_PART_LEN = 64;

class Fraction
{
    private:
        long int int_part;
        long int fraction_part;
        int max_fraction_len;
        short sign;
    public:
        Fraction(long int int_part, long int fraction_part, int max_fraction_len, short sign);
        void print();
};

Fraction::Fraction(long int int_part, long int fraction_part, int max_fraction_len, short sign)
{
    // Writing fraction part to array type
    int* fraction_part_arr_reverse = new int[max_fraction_len];
    int fraction_part_len = 0;

    long int temp_fraction = fraction_part;
    int i = 0;
    while (fraction_part > 0)
    {
        fraction_part_arr_reverse[i] = fraction_part%10;
        fraction_part = fraction_part / 10;
        i++;
        fraction_part_len++;
    }

    // Calculating fract_part with max_fraction_len
    long int validated_fractual_part = 0;
    int multiplyer = 0;
    for (int i = 0; i < min(fraction_part_len, max_fraction_len); i++)
    {
        validated_fractual_part += ((pow(10, multiplyer) * fraction_part_arr_reverse[i]));
        multiplyer++;
    }
    delete[] fraction_part_arr_reverse;



    this->int_part = int_part;
    this->fraction_part = validated_fractual_part;
    this->max_fraction_len = max_fraction_len;
    this->sign = sign;

    // // Reverse this array
    // int* fractinon_part_arr = new int[max_fraction_len];
    // int j = 0;
    // for (int i = fraction_part_len; i>=0; i--)
    // {
    //     fractinon_part_arr[j] = fraction_part_arr_reverse[i];
    //     j++;
    // }
    // delete[] fraction_part_arr_reverse;
}

void Fraction::print()
{
    cout << int_part << "." << fraction_part << endl;
}





int main()
{
    Fraction fr1(12345, 67890, 3, 0);
    fr1.print();
}