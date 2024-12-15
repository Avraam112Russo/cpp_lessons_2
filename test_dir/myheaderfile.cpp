#include "myheaderfile.h"
#include <iostream>
using namespace std;
MyClass::MyClass(int a, double b) {
    this->a = a;
    this->b = b;
}


void MyClass::some_func(int arg) {
    cout << "MyClass::some_func has been worked...\n";
}
void MyClass::some_func2(std::string &s) {
    cout << s << endl;
}

