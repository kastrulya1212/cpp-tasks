// CASE 1

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string>

using namespace std;




double tri_square_v1(double a, double b, double c)
{
    if ((a<b+c) && (b<a+c) && (c<a+b))
    {
        double p = (a+b+c) / 2;
        double s = sqrt(p * (p-a) * (p-b) * (p-c));
        return s;
    }
    else
    {
        cout << "Error! Triangle with this params does not exist" << endl;
        return -1;
    }
}

double tri_square_v2(double a, double b, double c)
{
    if ((a<b+c) && (b<a+c) && (c<a+b))
    {
        double p = (a+b+c) / 2;
        double s = sqrt(p * (p-a) * (p-b) * (p-c));
        return s;
    }
    else
    {
        throw "Error! Triangle with this params does not exist";
    }
}

double tri_square_v3(double a, double b, double c)
{
    if ((a<b+c) && (b<a+c) && (c<a+b))
    {
        double p = (a+b+c) / 2;
        double s = sqrt(p * (p-a) * (p-b) * (p-c));
        return s;
    }
    else
    {
        throw logic_error("Logic error! Triangle with this params does not exist");
    }
}






class TriangleExceptionV1 {};  

class TriangleExceptionV2
{
    private:
        string message;
    public:
        TriangleExceptionV2(string message)
        {
            this->message = message;
        }

        string get_message()
        {
            return message;
        }
};

class TriangleExceptionV3 : exception
{
    private:
        string message;
    public:
        TriangleExceptionV3(string message):exception()
        {
            this->message = message;
        }

        string what()
        {
            return message;
        }
};

double tri_square_class_v1(double a, double b, double c)
{
    if ((a<b+c) && (b<a+c) && (c<a+b))
    {
        double p = (a+b+c) / 2;
        double s = sqrt(p * (p-a) * (p-b) * (p-c));
        return s;
    }
    else
    {
        throw TriangleExceptionV1();
    }
}

double tri_square_class_v2(double a, double b, double c)
{
    if ((a<b+c) && (b<a+c) && (c<a+b))
    {
        double p = (a+b+c) / 2;
        double s = sqrt(p * (p-a) * (p-b) * (p-c));
        return s;
    }
    else
    {
        throw TriangleExceptionV2("Logic error! Triangle with this params does not exist");
    }
}

double tri_square_class_v3(double a, double b, double c)
{
    if ((a<b+c) && (b<a+c) && (c<a+b))
    {
        double p = (a+b+c) / 2;
        double s = sqrt(p * (p-a) * (p-b) * (p-c));
        return s;
    }
    else
    {
        throw TriangleExceptionV3("Logic error! Triangle with this params does not exist");
    }
}




int main()
{
    double a1=3, b1=4, c1=5;
    double a2=1, b2=2, c2=100;
    double result1, result2;

    // Testing tri_square_v1
    cout << endl << "Testing tri_square_v1:" << endl;
    result1 = tri_square_v1(a1, b1, c1);
    result2 = tri_square_v1(a2, b2, c2);
    cout << "result1 = " << result1 << endl;
    cout << "result2 = " << result2 << endl; 
    

    // Testing tri_square_v2
    cout << endl << "Testing tri_square_v2:" << endl;
    try
    {
        result1 = tri_square_v2(a1, b1, c1);
        cout << "result1 = " << result1 << endl;
    }
    catch(const char* e)
    {
        cout << "Error! " << e << endl;
    }
    
    try
    {
        result2 = tri_square_v2(a2, b2, c2);
        cout << "result2 = " << result2 << endl;
    }
    catch(const char* e)
    {
        cout << "Error! " << e << endl;
    }
    

    // Testing tri_square_v3
    cout << endl << "Testing tri_square_v3:" << endl;
    try
    {
        result1 = tri_square_v3(a1, b1, c1);
        cout << "result1 = " << result1 << endl;
    }
    catch(exception e)
    {
        cout << "Error! " << e.what() << endl;
    }
    
    try
    {
        result2 = tri_square_v3(a2, b2, c2);
        cout << "result2 = " << result2 << endl;
    }
    catch(exception e)
    {
        cout << "Error! " << e.what() << endl;
    }


    // Testing TriangleExceptionV1
    cout << endl << "Testing TriangleExceptionV1:" << endl;
    try
    {
        result1 = tri_square_class_v1(a1, b1, c1);
        cout << "result1 = " << result1 << endl;
    }
    catch(TriangleExceptionV1 e)
    {
        cout << "Error! " << "TriangleExceptionV1 here" << endl;
    }
    
    try
    {
        result2 = tri_square_class_v1(a2, b2, c2);
        cout << "result2 = " << result2 << endl;
    }
    catch(TriangleExceptionV1 e)
    {
        cout << "Error! " << "TriangleExceptionV1 here" << endl;
    }


    // Testing TriangleExceptionV2
    cout << endl << "Testing TriangleExceptionV2:" << endl;
    try
    {
        result1 = tri_square_class_v2(a1, b1, c1);
        cout << "result1 = " << result1 << endl;
    }
    catch(TriangleExceptionV2 e)
    {
        cout << "Error! " << e.get_message() << endl;
    }
    
    try
    {
        result2 = tri_square_class_v2(a2, b2, c2);
        cout << "result2 = " << result2 << endl;
    }
    catch(TriangleExceptionV2 e)
    {
        cout << "Error! " << e.get_message() << endl;
    }


    // Testing TriangleExceptionV3
    cout << endl << "Testing TriangleExceptionV3:" << endl;
    try
    {
        result1 = tri_square_class_v3(a1, b1, c1);
        cout << "result1 = " << result1 << endl;
    }
    catch(TriangleExceptionV3 e)
    {
        cout << "Error! " << e.what() << endl;
    }
    
    try
    {
        result2 = tri_square_class_v3(a2, b2, c2);
        cout << "result2 = " << result2 << endl;
    }
    catch(TriangleExceptionV3 e)
    {
        cout << "Error! " << e.what() << endl;
    }
}