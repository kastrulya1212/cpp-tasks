// Copied code from LW_9_1 and rewrite with constant, auto


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
        Twin(const Type& first, const Type& second);

        void swap();
        Type getFirst() const;
        Type getSecond() const;

        template <typename T>
        friend ostream& operator<<(ostream& stream, const Twin<T>& obj);

        template <typename T>
        friend istream& operator>>(istream& stream, Twin<T>& obj);
};


template <typename Type>
Twin<Type>::Twin(const Type& first, const Type& second) {
    this->first = first;
    this->second = second;
}

template <typename Type>
void Twin<Type>::swap() {
    auto temp = first;

    first = second;
    second = temp;
}

template <typename Type>
Type Twin<Type>::getFirst() const {
    return first;
}

template <typename Type>
Type Twin<Type>::getSecond() const {
    return second;
}

template <typename Type>
ostream& operator<<(ostream& stream, const Twin<Type>& obj) {
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
    const auto mamamia = Twin<int>(12, 13);
    cout << "Creating const auto object and getting elements (const methods)" << endl;
    cout << mamamia.getFirst() << endl;
    cout << mamamia.getSecond() << endl << endl;


    cout << "Creating unconst copy (using auto) and using swap method, then getting elements after swap" << endl;
    auto mamamia_copy_unconst = mamamia;
    mamamia_copy_unconst.swap();
    cout << mamamia_copy_unconst.getFirst() << endl;
    cout << mamamia_copy_unconst.getSecond() << endl << endl;

    cout << "Creating const copy (using decltype) and trying to use unconst method (error expects)" << endl;
    decltype(mamamia) mamamia_copy_const = mamamia;
    cout << "Impossible to use unconst method to const object (compiler fatal error)" << endl << endl;


    cout << "Getting elements by stream overload" << endl;
    cout << mamamia << endl << endl;

    cout << "Initialize object with auto" << endl;
    auto mamamia_auto = Twin<char>('A', 'Z');
    cout << "Elements output (using stream overload): " << mamamia_auto << endl << endl;


    auto mamamia2 = Twin<double>();
    cout << "Entering elemets with stream overload" << endl << "Enter 'double' type elements in object" << endl;
    cin >> mamamia2;
    cout << "Getting elements with istream" << endl;
    cout << mamamia2.getFirst() << endl;
    cout << mamamia2.getSecond() << endl << endl;
}