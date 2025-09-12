#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>

using namespace std;



// Struct "NewData"
struct NewData
{
    double first;
    double second;

    void init(double check_first, double check_second);
    void read();
    void display();
    double power();

    NewData(double inp_first = 0, double inp_second = 0);
    NewData& operator=(NewData& obj);

    friend NewData* make_NewData(double inp_first, double inp_second);
};



// Functions realizations for struct "NewData"
void NewData::init(double check_first, double check_second)
{
    cout << "INIT checking..." << endl;
    cout << "INIT all is fine!" << endl;
}

void NewData::read()
{
    double check_first;
    double check_second;

    cout << "Введите значение для поля first: "; cin >> check_first;
    cout << "Введите значение для поля second: "; cin >> check_second;
    init(check_first, check_second);
    
    first = check_first;
    second = check_second;
}

void NewData::display()
{
    cout << "Вывод значений структуры." << endl;
    cout << "Вывод first: " << first << endl;
    cout << "Вывод second: " << second << endl;
}

double NewData::power()
{
    return pow(first, second);
}

NewData::NewData(double inp_first, double inp_second)
{
    init(inp_first, inp_second);

    first = inp_first;
    second = inp_second;
}

NewData& NewData::operator=(NewData& obj)
{
    if (this == &obj) return *this;

    first = obj.first;
    second = obj.second;

    return *this;
}
// Functions realizations END



// External functions
NewData* make_NewData(double inp_first = 0, double inp_second = 0)
{   // !IMPORTANT TO RELEASE THE MEMORY!
    return new NewData(inp_first, inp_second);
}
// External functions END



// main func
int main()
{
    // object creation tests
    cout << "Check object test..." << endl << endl;
    NewData obj1 = NewData();
    NewData obj2 = NewData(1.5,2.5);
    NewData* obj3 = make_NewData(4,4);              // remember to release the memory
    cout << "obj1 statistic - "; obj1.display();
    cout << "obj2 statistic - "; obj2.display();
    cout << "obj3 statistic - "; obj3->display();
    delete obj3;

    // list_object creation tests 
    cout << endl << endl << "Check object list..." << endl << endl;
    int length = 2;
    NewData* obj_list = new NewData[length];
    cout << "obj_list[0] before assigment" << endl;
    obj_list[0].display();

    cout << "obj_list[0] after assigment" << endl;
    obj_list[0] = obj2;
    obj_list[0].display();
    cout << "variable's addresses: " << &obj2 << " " << &obj_list[0];
    delete[] obj_list;

    // object read func test
    cout << endl << endl << "Check object read func..." << endl;
    obj1.read();
    obj1.display();

    // object power func test
    cout << endl << endl << "Check object power func..." << endl;
    obj1.display();
    cout << "power func result - " << obj1.power() << endl;
} 