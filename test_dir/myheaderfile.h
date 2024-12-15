//
// Created by n3zhy13c on 12/8/24.
//

#ifndef MYHEADERFILE_H
#define MYHEADERFILE_H
#include <string>

class MyClass {
public:

    int a;
    double b;
    MyClass(int a, double b);
    void some_func(int arg);
    void some_func2(std::string& s);
};
#endif //MYHEADERFILE_H
