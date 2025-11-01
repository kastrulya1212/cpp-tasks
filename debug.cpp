// CASE 6

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string>

using namespace std;

// [1,2,3,4,5]
// [1,2,3,4,5,6]
const int RECREATION_STEP = 10;





class ArrayInt
{
    private:
        int* array;
        int actual_length;
        int reserve_length;

        int* create_temp_array();
        int* create_temp_array(int* array, int length);
    public:
        ArrayInt();
        ArrayInt(int size);
        ~ArrayInt();
        
        int& operator[](int index);
        //ArrayInt& operator+(ArrayInt& obj);
        friend ArrayInt& operator+(ArrayInt& obj1, ArrayInt& obj2);

        void append(int new_element);
        void print();
        void print_all_stats();
        ArrayInt& quick_sort(ArrayInt& inp_array);
};

int* ArrayInt::create_temp_array()
{
    int* temp = new int[actual_length];
    for (int i = 0; i < actual_length; i++)
        temp[i] = array[i];
    return temp;
}

int* ArrayInt::create_temp_array(int* inp_array, int length)
{
    int* temp = new int[length];
    for (int i = 0; i < length; i++)
        temp[i] = inp_array[i];
    return temp;
}

ArrayInt::ArrayInt()
{
    reserve_length = RECREATION_STEP;
    actual_length = 0;
    array = new int[reserve_length];
}

ArrayInt::ArrayInt(int size)
{
    reserve_length = size;
    actual_length = 0;
    array = new int[reserve_length];
}

ArrayInt::~ArrayInt()
{
    delete[] array;
}

int& ArrayInt::operator[](int index)
{
    if ((index >= 0) && (index < actual_length))
    {
        return array[index];
    }
    cout << "Index error" << endl;
    exit(0);
}

// ArrayInt& ArrayInt::operator+(ArrayInt& obj)
// {
//     ArrayInt new_array = ArrayInt();
//     for (int i = 0; i < actual_length; i++)
//     {
//         new_array.append(array[i]);
//     }

//     for (int i = 0; i < obj.actual_length; i++)
//     {
//         new_array.append(obj[i]);
//     }

//     return new_array;
// }

void ArrayInt::append(int new_element)
{
    if (actual_length+1 > reserve_length)
    {
        int* temp_arr = create_temp_array();
        delete[] array;

        reserve_length += RECREATION_STEP;
        array = new int[reserve_length];
        int i = 0;
        for (; i < actual_length; i++)
            array[i] = temp_arr[i];
        delete[] temp_arr;

        actual_length++;
        array[i] = new_element;
    }
    else
    {
        array[actual_length] = new_element;
        actual_length++;
    }
}

void ArrayInt::print()
{
    if (actual_length > 0)
        for (int i = 0; i < actual_length; i++)
        {
            if (i==actual_length-1)
                cout << array[i] << endl;
            else
                cout << array[i] << ", ";
        }
    else
    {
        cout << "Empty array" << endl;
    }
}

void ArrayInt::print_all_stats()
{
    cout << "len=" << actual_length << "; reserve_len=" << reserve_length << endl;
    if (actual_length > 0)
        for (int i = 0; i < actual_length; i++)
        {
            if (i==actual_length-1)
                cout << array[i] << endl;
            else
                cout << array[i] << ", ";
        }
    else
    {
        cout << "Empty array" << endl;
    }
}

ArrayInt& ArrayInt::quick_sort(ArrayInt& inp_array)
{
    if (inp_array.actual_length == 1)
    {
        return inp_array;
    }  

    int pivot = inp_array[inp_array.actual_length/2];
    ArrayInt left = ArrayInt();
    ArrayInt right = ArrayInt();
    ArrayInt middle = ArrayInt();

    // cout << "SORTING STEP 1" << endl;
    // cout << "inp_arr  ";
    // inp_array.print();
    for (int i = 0; i < inp_array.actual_length; i++)
    {
        if (inp_array[i] < pivot) left.append(inp_array[i]);
        else if (inp_array[i] > pivot) right.append(inp_array[i]);
        else if (inp_array[i] == pivot) middle.append(inp_array[i]);
    }
    // cout << "SORTING STEP 2" << endl;
    // left.print(); middle.print(); right.print();
    // cout << "length = " << left.actual_length << " " << middle.actual_length << " " << right.actual_length << endl;
    // cout << "pivot " << pivot << endl << endl; 

    if ((left.actual_length>0) && (middle.actual_length>0) && (left.actual_length>0)) return ((quick_sort(left) + middle) + quick_sort(right));
    else if (left.actual_length>0 && middle.actual_length>0) return (quick_sort(left) + middle);
    else if (left.actual_length>0 && right.actual_length>0) return (quick_sort(left) + quick_sort(right));
    else if (middle.actual_length>0 && right.actual_length>0) return (middle + quick_sort(right));
}

ArrayInt& operator+(ArrayInt& obj1, ArrayInt& obj2)
{
    ArrayInt* new_array = new ArrayInt();
    //cout << "OPERATOR DEBUG" << endl;
    //obj1.print(); obj2.print();

    for (int i = 0; i < obj1.actual_length; i++)
    {
        new_array->append(obj1[i]);
    }

    for (int i = 0; i < obj2.actual_length; i++)
    {
        new_array->append(obj2[i]);
    }

    //new_array->print();
    //cout << "OPERATOR DEBUG END" << endl << endl;
    return *new_array;
}




int main()
{
    ArrayInt arr1 = ArrayInt();
    for (int i = 10; i >= 0; i--)
        arr1.append(i);

    ArrayInt arr_sorted = arr1.quick_sort(arr1);    
    
    arr1.print_all_stats();
    arr_sorted.print_all_stats();
}