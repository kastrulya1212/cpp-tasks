// CASE 1

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string>
#include <vector>

using namespace std;


template <typename Type>
class Twin {
    private:
        Type first;
        Type second;
    public:
        Twin(){};
        Twin(Type first, Type second);

        void swap();
        Type getFirst();
        Type getSecond();

        template <typename T>
        friend ostream& operator<<(ostream& stream, Twin<T>& obj);

        template <typename T>
        friend istream& operator>>(istream& stream, Twin<T>& obj);
};


template <typename Type>
Twin<Type>::Twin(Type first, Type second) {
    this->first = first;
    this->second = second;
}

template <typename Type>
void Twin<Type>::swap() {
    Type temp;
    temp = first;

    first = second;
    second = temp;
}

template <typename Type>
Type Twin<Type>::getFirst() {
    return first;
}

template <typename Type>
Type Twin<Type>::getSecond() {
    return second;
}

template <typename Type>
ostream& operator<<(ostream& stream, Twin<Type>& obj) {
    stream << obj.first << " " << obj.second;
    return stream;
}

template <typename Type>
istream& operator>>(istream& stream, Twin<Type>& obj) {
    stream >> obj.first >> obj.second;
    return stream;
}





int main()
{
    Twin<int> mamamia = Twin<int>(12, 13);
    cout << "Getting elements" << endl;
    cout << mamamia.getFirst() << endl;
    cout << mamamia.getSecond() << endl << endl;

    mamamia.swap();
    cout << "Getting elements after swap" << endl;
    cout << mamamia.getFirst() << endl;
    cout << mamamia.getSecond() << endl << endl;

    cout << "Getting elements by stream overload" << endl;
    cout << mamamia << endl << endl;


    Twin<double> mamamia2 = Twin<double>();
    cin >> mamamia2;
    cout << "Getting elements with istream" << endl;
    cout << mamamia2.getFirst() << endl;
    cout << mamamia2.getSecond() << endl << endl;
}