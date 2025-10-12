// CASE 1

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string>

using namespace std;


const int MAX_LENGTH = 128;





class ArrayCollections
{
    private:
        int len;
    public:
        ArrayCollections(int len);
        int get_len();
        void set_len(int new_len);
        virtual int convert_to_int(int index)=0;
        virtual void add_array(ArrayCollections& obj)=0;
        virtual void print_array()=0;

};

ArrayCollections::ArrayCollections(int len)
{
    this->len = len;
}

int ArrayCollections::get_len()
{
    return len;
}

void ArrayCollections::set_len(int new_len)
{
    len = new_len;
}





class ArrayChar: public ArrayCollections
{
    private:
        unsigned char array[MAX_LENGTH];
    public:
        ArrayChar(char element = '0', int len = 1);
        int convert_to_int(int index);
        char convert_to_char(int sym);
        void add_array(ArrayCollections& obj);
        void print_array();
        unsigned char& operator[](int index);
};

ArrayChar::ArrayChar(char element, int len):ArrayCollections(len)
{
    for (int i = 0; i<len; i++)
    {
        array[i] = element;
    }
}

int ArrayChar::convert_to_int(int index)
{
    char sym;
    if ((index < get_len()) && (0 <= index))
        sym = array[index];
    else
    {
        cout << "Invalid array index!" << endl;
        exit(0);
    }

    switch (sym)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    
    default:
        cout << "Unexpected char! Current char cannot be defined as double" << endl;
        exit(0);
        break; 
    }
}

char ArrayChar::convert_to_char(int sym)
{
    switch (sym)
    {
    case 0:
        return '0';
    case 1:
        return '1';
    case 2:
        return '2';
    case 3:
        return '3';
    case 4:
        return '4';
    case 5:
        return '5';
    case 6:
        return '6';
    case 7:
        return '7';
    case 8:
        return '8';
    case 9:
        return '9';
    
    default:
        cout << "Unexpected int number! Current num cannot be defined as char" << endl;
        exit(0);
        break; 
    }
}

void ArrayChar::add_array(ArrayCollections& obj)
{
    if (obj.get_len() > get_len())
    {
        int old_len = get_len();
        set_len(obj.get_len());

        for (int i = old_len; i<get_len(); i++)
            array[i] = '0';
    }
    
    //cout << "curr char len " << get_len() << endl;
    for (int i = 0; i<get_len(); i++)
    {
        int sum_result;
        if (i < obj.get_len())
        {
            //cout << "case 1" << endl;
            sum_result = convert_to_int(i) + obj.convert_to_int(i);
        }
        else
        {
            //cout << "case 2" << endl;
            sum_result = convert_to_int(i);
        }

        //cout << sum_result << endl;
        
        int last_sym = sum_result%10;

        array[i] = convert_to_char(last_sym);
    }
}

void ArrayChar::print_array()
{
    cout << "[";
    for (int i = 0; i < get_len(); i++)
    {
        cout << array[i];
        if (i < get_len()-1)
            cout << ", ";
        else
            cout << "]" << endl;
    }
}

unsigned char& ArrayChar::operator[](int index)
{
    if ((index < get_len()) && (0 <= index))
        return array[index];
    else
    {
        cout << "Invalid array index!" << endl;
        exit(0);
    }
}





class ArrayDouble: public ArrayCollections
{
    private:
        double array[MAX_LENGTH];
    public:
        ArrayDouble(int element = 0, int len = 1);
        int convert_to_int(int index);
        double convert_to_double(int sym);
        void add_array(ArrayCollections& obj);
        void print_array();
        double& operator[](int index);
};

ArrayDouble::ArrayDouble(int element, int len):ArrayCollections(len)
{
    for (int i = 0; i<len; i++)
    {
        array[i] = (double)element;
    }
}

int ArrayDouble::convert_to_int(int index)
{
    return (int)array[index];
}

double ArrayDouble::convert_to_double(int sym)
{
    return (double)sym;
}

void ArrayDouble::add_array(ArrayCollections& obj)
{
    if (obj.get_len() > get_len())
    {
        int old_len = get_len();
        set_len(obj.get_len());

        for (int i = old_len; i<get_len(); i++)
            array[i] = 0;
    }
    
    for (int i = 0; i<get_len(); i++)
    {
        int sum_result;
        if (i < obj.get_len())
            sum_result = convert_to_int(i) + obj.convert_to_int(i);
        else
            sum_result = convert_to_int(i);
        
        int last_sym = sum_result%10;

        array[i] = convert_to_double(last_sym);
    }
}

void ArrayDouble::print_array()
{
    cout << "[";
    for (int i = 0; i < get_len(); i++)
    {
        cout << array[i];
        if (i < get_len()-1)
            cout << ", ";
        else
            cout << "]" << endl;
    }
}

double& ArrayDouble::operator[](int index)
{
    return array[index];
}





int main()
{
    ArrayChar arr_char1('5', 4); 
    ArrayChar arr_char2('1', 5);
    ArrayDouble arr_double1(3, 3);
    ArrayDouble arr_double2(5,1);
    

    // Setting arr_char2
    for (int i = 0; i<arr_char2.get_len(); i++)
    {
        arr_char2[i] = arr_char2.convert_to_char(i + 1);
    }

    // Setting arr_double1
    for (int i = 0; i<arr_double1.get_len(); i++)
    {
        arr_double1[i] = i + 1;
    }


    // All array info print
    cout << "All arrays (4) info:" << endl;
    cout << "arr_char1: "; arr_char1.print_array();
    cout << "arr_char2: "; arr_char2.print_array();
    cout << "arr_double1: "; arr_double1.print_array();
    cout << "arr_double2: "; arr_double2.print_array();
    
    // Testing add 'arr_char2' to 'arr_char1'
    cout << endl << "Testing add 'arr_char2' to 'arr_char1':" << endl;
    arr_char1.add_array(arr_char2);
    arr_char1.print_array();

    // Testing add 'arr_char1' to 'arr_char2'
    cout << endl << "Testing add 'arr_char1' to 'arr_char2':" << endl;
    arr_char2.add_array(arr_char1);
    arr_char2.print_array();

    // Testing add 'arr_double2' to 'arr_double1'
    cout << endl << "Testing add 'arr_double2' to 'arr_double1':" << endl;
    arr_double1.add_array(arr_double2);
    arr_double1.print_array();

    // Testing add 'arr_double1' to 'arr_double2'
    cout << endl << "Testing add 'arr_double1' to 'arr_double2':" << endl;
    arr_double2.add_array(arr_double1);
    arr_double2.print_array();

}