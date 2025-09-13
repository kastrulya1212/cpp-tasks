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
    bool rangecheck(double cheked_num);

    NewData(double inp_first = 1, double inp_second = 1);
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
    
    cout << "Введите левую границу диапазона: "; cin >> check_first;
    cout << "Введите правую границу диапазона: "; cin >> check_second;
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

bool NewData::rangecheck(double checked_num)
{
    return ((first <= checked_num) && (checked_num <= second));
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
NewData* make_NewData(double inp_first = 1, double inp_second = 1)
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

    // object rangecheck func test
    cout << endl << endl << "Check object rangecheck func..." << endl;
    obj1.display();

    cout << "Введите проверяемое число: "; 
    double num; cin >> num;
    
    cout << "rangecheck func result: "; 
    bool result = obj1.rangecheck(num);
    if (result == true) cout << "Значение входит в диапазон" << endl;
    else cout << "Значение не входит в диапазон" << endl;
} 