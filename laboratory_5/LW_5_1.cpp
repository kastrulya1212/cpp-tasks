// CASE 1

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string>

using namespace std;



// Class Car
class Car
{
    private:
        // Self fields
        string brand;
        int cylinder_count;
        int power;

    protected:
        // Internal protected methods
        void validate_Car(string check_brand, int check_cylinder_count, int check_power);

    public:
        // Constructors
        Car(string inp_brand, int inp_cylinder_count, int inp_power);
        Car(Car& obj);

        // Getters & Setters
        string get_brand();
        int get_cylinder_count();
        int get_power();
        void set_brand(string new_brand);
        void set_cylinder_count(int new_cylinder_count);
        void set_power(int new_power);

        // External public methods
        void print_stats();
        void change_power(int new_power);
};

void Car::validate_Car(string check_brand, int check_cylinder_count, int check_power)
{
    if (check_cylinder_count <=0)
    {
        cout << "Error! Cylinder count must be higher than 0" << endl;
        exit(0);
    }
    if (check_power <= 0)
    {
        cout << "Error! Power must be higher than 0" << endl;
        exit(0);
    }
}

Car::Car(string inp_brand, int inp_cylinder_count, int inp_power) 
{
    validate_Car(inp_brand, inp_cylinder_count, inp_power);

    brand = inp_brand;
    cylinder_count = inp_cylinder_count;
    power = inp_power; 
}

Car::Car(Car& obj)
{
    brand = obj.brand;
    cylinder_count = obj.cylinder_count;
    power = obj.power; 
} 

string Car::get_brand() {return brand;}
int Car::get_cylinder_count() {return cylinder_count;}
int Car::get_power() {return power;}

void Car::set_brand(string new_brand) 
{
    validate_Car(new_brand, cylinder_count, power);
    brand = new_brand;
}

void Car::set_cylinder_count(int new_cylinder_count)
{
    validate_Car(brand, new_cylinder_count, power);
    cylinder_count = new_cylinder_count;
}

void Car::set_power(int new_power)
{
    validate_Car(brand, cylinder_count, new_power);
    power = new_power;
}

void Car::print_stats()
{
    cout << "Brand: " << brand << endl;
    cout << "Cylinder cound: " << cylinder_count << endl;
    cout << "Power: " << power << endl;
}

void Car::change_power(int new_power)
{
    set_power(new_power);
}
// End class Car



// Class Lorry (inherited by Car)
class Lorry: public Car
{
    private:
        // Self fields
        double cargo_capacity;

    protected:
        // Internal protected methods
        void validate_Lorry(double check_cargo_capacity);

    public:
        // Constructors
        Lorry(string inp_brand, int inp_cylinder_count, 
            int inp_power, double inp_cargo_capacity);
        Lorry(Lorry& obj);

        // Getters & Setters
        double get_cargo_capacity();
        void set_cargo_capacity(double new_cargo_capacity);

        // External public methods
        void print_stats();
        void change_brand(string new_brand);
        void change_cargo_capacity(double new_cargo_capacity);
};

void Lorry::validate_Lorry(double check_cargo_capacity)
{
    if (check_cargo_capacity <= 0)
    {
        cout << "Error! Cargo capacity must be higher than 0" << endl;
        exit(0);
    }
}

Lorry::Lorry(string inp_brand, int inp_cylinder_count, 
    int inp_power, double inp_cargo_capacity): Car(inp_brand, inp_cylinder_count, inp_power)
{
    validate_Lorry(inp_cargo_capacity);
    cargo_capacity = inp_cargo_capacity;
}

Lorry::Lorry(Lorry& obj): Car(obj)
{
    cargo_capacity = obj.cargo_capacity;
}

double Lorry::get_cargo_capacity() {return cargo_capacity;}

void Lorry::set_cargo_capacity(double new_cargo_capacity)
{
    validate_Lorry(new_cargo_capacity);
    cargo_capacity = new_cargo_capacity;
}

void Lorry::print_stats()
{
    Car::print_stats();
    cout << "Cargo capacity: " << cargo_capacity << endl;
}

void Lorry::change_brand(string new_brand)
{
    set_brand(new_brand);
}

void Lorry::change_cargo_capacity(double new_cargo_capacity)
{
    set_cargo_capacity(new_cargo_capacity);
}
// End class Lorry





int main()
{  
    Lorry obj1 = Lorry("MAN", 6, 650, 15.5);
    Lorry obj2 = Lorry("Scania", 10, 900, 25);
    Lorry obj3 = Lorry(obj1);

    Car obj_car = Car("BMW", 6, 400);

    // Test class "Car" getters and setters
    cout << endl << endl << "Test class 'Car' getters and setters" << endl;
    cout << "Getters: " << obj_car.get_brand() << " " << obj_car.get_cylinder_count() << " " << obj_car.get_power() << endl;
    
    obj_car.set_brand("Mercedes");
    obj_car.set_cylinder_count(10);
    obj_car.set_power(700);

    cout << "After setters: " << obj_car.get_brand() << " " << obj_car.get_cylinder_count() << " " << obj_car.get_power() << endl;


    // Test class "Car" functions "change_power" and "print_stats"
    cout << endl << endl << "Test class 'Car' functions 'change_power' and 'print_stats'" << endl;
    obj_car.print_stats();
    obj_car.change_power(200);
    obj_car.print_stats();


    // Test class "Lorry" getters and setters
    cout << endl << endl << "Test class 'Lorry' getters and setters" << endl;   
    cout << "Getters: " << obj1.get_brand() << " " << obj1.get_cylinder_count() << " " << obj1.get_power() << " " << obj1.get_cargo_capacity() << endl;

    obj1.set_brand("KAMAZ");
    obj1.set_cylinder_count(14);
    obj1.set_power(1000);
    obj1.set_cargo_capacity(30);

    cout << "After setters: " << obj1.get_brand() << " " << obj1.get_cylinder_count() << " " << obj1.get_power() << " " << obj1.get_cargo_capacity() << endl;  


    // Test class "Lorry" functions "change_brand", "change_capacity", "print_stats"
    cout << endl << endl << "Test class 'Lorry' functions 'change_brand', 'change_capacity', 'print_stats'" << endl;
    obj1.print_stats();
    obj1.change_brand("Some lorry");
    obj1.change_cargo_capacity(1000);
    obj1.print_stats();
}