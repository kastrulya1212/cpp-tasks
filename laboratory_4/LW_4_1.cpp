// CASE 1

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string>

using namespace std;



// Class Complex
class Complex
{
    private:
        double real_a;
        double imaginary_b;

    public:
        void read();
        void display();
        string ComplexToString();

        Complex(double inp_real_a = 0, double inp_imaginary_b = 0);
        Complex(Complex& obj);
        Complex operator+(Complex& obj);
        Complex operator-(Complex& obj);
        Complex operator*(Complex& obj);
        Complex operator/(Complex& obj);
        bool operator==(Complex& obj);

        Complex conjugated_complex();
};



// Functions realizations for struct "Complex"
void Complex::read()
{
    double inp_real, inp_imaginary;
    cout << "Введите действительную часть комплексного числа (дробное либо целое число): "; cin >> inp_real;
    cout << "Введите мнимую часть комплексного числа (дробное либо целое число): "; cin >> inp_imaginary;

    real_a = inp_real;
    imaginary_b = inp_imaginary;
}

void Complex::display()
{
    cout << "Действительная часть комлексного числа: " << real_a << endl;
    cout << "Мнимая часть комплексного числа: " << imaginary_b << endl; 
}

string Complex::ComplexToString()
{
    string str_real_a = to_string(real_a);
    string str_imaginary_b = to_string(imaginary_b);
    return str_real_a + ", " + str_imaginary_b + "i";
}

Complex::Complex(double inp_real_a, double inp_imaginary_b)
{
    //cout << "Init checking..." << endl;
    real_a = inp_real_a;
    imaginary_b = inp_imaginary_b;
    //cout << "Init completed!" << endl;
}

Complex::Complex(Complex& obj)
{
    real_a = obj.real_a;
    imaginary_b = obj.imaginary_b;
}

Complex Complex::operator+(Complex& obj)
{
    Complex new_obj = Complex(
        this->real_a + obj.real_a,
        this->imaginary_b + obj.imaginary_b);
    return new_obj;
}

Complex Complex::operator-(Complex& obj)
{
    Complex new_obj = Complex(
        this->real_a - obj.real_a,
        this->imaginary_b - obj.imaginary_b);
    return new_obj;
}

Complex Complex::operator*(Complex& obj)
{
    Complex new_obj = Complex(
        (real_a*obj.real_a) - (imaginary_b*obj.imaginary_b),
        (real_a*obj.imaginary_b) + (imaginary_b*obj.real_a));
    return new_obj;
}

Complex Complex::operator/(Complex& obj)
{
    if ((obj.real_a*obj.real_a + obj.imaginary_b*obj.imaginary_b == 0))
    {
        cout << "ERROR devision by ZERO is restricted" << endl;
        exit(0);
    }

    Complex new_obj = Complex(
        (real_a*obj.real_a + imaginary_b*obj.imaginary_b)/(obj.real_a*obj.real_a + obj.imaginary_b*obj.imaginary_b),
        (imaginary_b*obj.real_a - real_a*obj.imaginary_b)/(obj.real_a*obj.real_a + obj.imaginary_b*obj.imaginary_b));
    return new_obj;
}

bool Complex::operator==(Complex& obj)
{
    return ((real_a==obj.real_a) && (imaginary_b==obj.imaginary_b));
}

Complex Complex::conjugated_complex()
{
    Complex new_obj = Complex(
        real_a,
        -imaginary_b);
    return new_obj;
}
// Functions realizations END





int main()
{
    Complex obj1 = Complex(2, 3);
    Complex obj2 = Complex(obj1);
    Complex obj3 = Complex(10, 1);

    // Test read/display funcs
    cout << "Testing read/display funcs..." << endl << endl;
    obj1.display();
    obj1.read();
    obj1.display();

    // Test ComplexToString func
    cout << endl << endl << "Testing ComplexToString func..." << endl << endl;
    cout << obj1.ComplexToString() << endl;

    // Test operator "+" for class "Complex"
    cout << endl << endl << "Testing operator '+' for class 'Complex'..." << endl << endl;
    cout << "obj1: ";
    obj1.display();
    cout << "obj2: ";
    obj2.display();
    
    Complex test_add = obj1 + obj2;
    cout << "result: ";
    test_add.display();

    // Test operator "-" for class "Complex"
    cout << endl << endl << "Testing operator '-' for class 'Complex'..." << endl << endl;
    cout << "obj3: ";
    obj3.display();
    cout << "obj2: ";
    obj2.display();

    Complex test_sub = obj3 - obj2;
    cout << "result: ";
    test_sub.display();

    // Test operator "*" for class "Complex"
    cout << endl << endl << "Testing operator '*' for class 'Complex'..." << endl << endl;
    cout << "obj1: ";
    obj1.display();
    cout << "obj2: ";
    obj2.display();

    Complex test_mul = obj1 * obj2;
    cout << "result: ";
    test_mul.display();

    // Test operator "/" for class "Complex"
    cout << endl << endl << "Testing operator '-' for class 'Complex'..." << endl << endl;
    cout << "obj3: ";
    obj3.display();
    cout << "obj1: ";
    obj1.display();

    Complex test_div = obj3 / obj1;
    cout << "result: ";
    test_div.display();

    // Test operator "==" for class "Complex"
    cout << endl << endl << "Testing operator '==' for class 'Complex'..." << endl << endl;
    cout << "obj1: ";
    obj1.display();
    cout << "obj2: ";
    obj2.display();

    bool test_equ = (obj1 == obj2);
    cout << "result: " << test_equ << endl;

    // Test conjucated complex
    cout << endl << endl << "Testing conjugated func..." << endl << endl;
    cout << "obj2: ";
    obj2.display();
    cout << "conjugated complex num: " << obj2.conjugated_complex().ComplexToString() << endl;
}