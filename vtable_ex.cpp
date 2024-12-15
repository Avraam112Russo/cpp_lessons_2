#include <iostream>
#include "test_dir/myheaderfile.h"
using namespace std;



int main(int argc, char ** argv) {
    MyClass m(100,6.6);
    MyClass * c = new MyClass(100, 5.5);
    c->some_func(c->a);
    string s = "Hello, world!";
    c->some_func2(s);
    return 0;
}