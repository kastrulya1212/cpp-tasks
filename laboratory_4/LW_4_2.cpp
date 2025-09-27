// CASE 2

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string>

using namespace std;



// Class Vector3D
class Vector3D
{
    private:
        double x_cord;
        double y_cord;
        double z_cord;
    public:
        // Constructors
        Vector3D(double inp_x = 0, double inp_y = 0, double inp_z = 0);
        Vector3D(Vector3D& obj);

        // Overloads
        Vector3D operator+(Vector3D& obj);
        Vector3D operator-(Vector3D& obj);
        double operator*(Vector3D& obj);
        Vector3D operator*(double num);
        bool operator==(Vector3D& obj);

        // Funtions
        double len();
        bool equal_len(Vector3D& obj);
        void print();
};

Vector3D::Vector3D(double inp_x, double inp_y, double inp_z)
{
    x_cord = inp_x;
    y_cord = inp_y;
    z_cord = inp_z;
}

Vector3D::Vector3D(Vector3D& obj)
{
    x_cord = obj.x_cord;
    y_cord = obj.y_cord;
    z_cord = obj.z_cord;
}

Vector3D Vector3D::operator+(Vector3D& obj)
{
    return Vector3D(
        x_cord+obj.x_cord,
        y_cord+obj.y_cord,
        z_cord+obj.z_cord);
}

Vector3D Vector3D::operator-(Vector3D& obj)
{
    return Vector3D(
        x_cord-obj.x_cord,
        y_cord-obj.y_cord,
        z_cord-obj.z_cord);
}

double Vector3D::operator*(Vector3D& obj)
{
    return (x_cord*obj.x_cord)+(y_cord*obj.y_cord)+(z_cord*obj.z_cord);
}

Vector3D Vector3D::operator*(double num)
{
    return Vector3D(
        x_cord * num,
        y_cord * num,
        z_cord * num);
}

bool Vector3D::operator==(Vector3D& obj)
{
    return ((x_cord==obj.x_cord) && (y_cord==obj.y_cord) && (z_cord==obj.z_cord));
}

double Vector3D::len()
{
    return sqrt(pow(x_cord, 2) + pow(y_cord, 2) + pow(z_cord, 2));
}

bool Vector3D::equal_len(Vector3D& obj)
{
    return (len() == obj.len());
}

void Vector3D::print()
{
    cout << "(" << x_cord << ", " << y_cord << ", " << z_cord << ")";
}
// End class Vector3D





int main()
{
    Vector3D obj1;
    Vector3D obj2 = Vector3D(3, 4, 0);
    Vector3D obj3 = Vector3D(obj2);
    
    // Test operator '+' for class Vector3D
    cout << "Testing operator '+' for class Vector3D: " << endl;
    cout << "Objects - "; obj2.print(); obj3.print(); cout << endl;
    cout << "Result - "; (obj2+obj3).print(); cout << endl << endl << endl;

    // Test operator '-' for class Vector3D
    cout << "Testing operator '-' for class Vector3D: " << endl;
    cout << "Objects - "; obj2.print(); obj3.print(); cout << endl;
    cout << "Result - "; (obj2-obj3).print(); cout << endl << endl << endl;

    // Test operator '*' for class Vector3D (num multiplication)
    cout << "Testing operator '*' for class Vector3D (num multiplication): " << endl;
    double num = 3;
    cout << "Objects - "; obj3.print(); cout << " " << num << endl;
    cout << "Result - "; (obj3*num).print(); cout << endl << endl << endl;

    // Test operator '*' for class Vector3D (scalar multiplication)
    cout << "Testing operator '*' for class Vector3D (scalar multiplication): " << endl;
    cout << "Objects - "; obj2.print(); obj3.print(); cout << endl;
    cout << "Result - "; cout << (obj2*obj3) << endl << endl << endl;

    // Test operator '==' for class Vector3D
    cout << "Testing operator '==' for class Vector3D: " << endl;
    cout << "Objects - "; obj2.print(); obj3.print(); cout << endl;
    cout << "Result - "; cout << (obj2==obj3) << endl << endl << endl;

    // Test func 'len' for class Vector3D
    cout << "Testing func 'len' for class Vector3D: " << endl;
    cout << "Objects - "; obj2.print(); cout << endl;
    cout << "Result - "; cout << obj2.len() << endl << endl << endl;

    // Test func 'equal_len' for class Vector3D
    cout << "Testing func 'equal_len' for class Vector3D: " << endl;
    cout << "Objects - "; obj1.print(); obj2.print(); cout << endl;
    cout << "Result - "; cout << obj1.equal_len(obj2) << endl << endl << endl;

    // Test func 'equal_len' for class Vector3D
    cout << "Testing func 'equal_len' for class Vector3D: " << endl;
    cout << "Objects - "; obj2.print(); obj3.print(); cout << endl;
    cout << "Result - "; cout << obj2.equal_len(obj3) << endl << endl << endl;
}