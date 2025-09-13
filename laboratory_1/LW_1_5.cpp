#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>

using namespace std;



// Struct "NewData"
struct NewData
{
    double first;
    int second;

    void init(double check_first, int check_second);
    void read();
    void display();
    double cost();

    NewData(double inp_first = 1, int inp_second = 1);
    NewData& operator=(NewData& obj);

    friend NewData* make_NewData(double inp_first, int inp_second);
};



// Functions realizations for struct "NewData"
void NewData::init(double check_first, int check_second)
{
    cout << "INIT checking..." << endl;
    if (check_first<=0 || check_second<=0)
    {
        cout << "ERROR! Unexpected values for variables: ";
        cout << check_first << " " << check_second << endl;
        exit(0);
    }
    cout << "INIT all is fine!" << endl;
}

void NewData::read()
{
    double check_first; 
    int check_second;
    
    cout << "Введите цену одного товара (first): "; cin >> check_first;
    cout << "Введите кол-во единиц товара (second): "; cin >> check_second;
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

double NewData::cost()
{
    return first*second;
}

NewData::NewData(double inp_first, int inp_second)
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
NewData* make_NewData(double inp_first = 1, int inp_second = 1)
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
    NewData obj2 = NewData(2,5);
    NewData* obj3 = make_NewData(100,4);              // remember to release the memory
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

    // object cost func test
    cout << endl << endl << "Check object cost func..." << endl;
    obj1.display();
    cout << "cost func result: " << obj1.cost() << endl;
} 