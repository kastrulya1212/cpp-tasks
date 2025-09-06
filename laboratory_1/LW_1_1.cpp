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

    void init();
    void read();
    void display();

    double power();

    NewData(double inp_first = -1, int inp_second = -1);
};



// Functions realizations for struct "NewData"
void NewData::init()
{
    cout << "init..." << endl;
}

void NewData::read()
{
    cout << "Введите значение для поля first: "; cin >> first;
    cout << "Введите значение для поля second: "; cin >> second;
}

void NewData::display()
{
    cout << "Вывод значений структуры: " << endl;
    cout << "Вывод first: " << first << endl;
    cout << "Вывод second: " << second << endl;
}

double NewData::power()
{
    return pow(first, second);
}

NewData::NewData(double inp_first, int inp_second)
{
    first = inp_first;
    second = inp_second;
}
// Functions realizations END



// main func
int main()
{
    cout << "Hello world!" << endl;
    NewData obj1(5, 3);
    obj1.display();
    cout << obj1.power() << endl;
}