#include <iostream>


using namespace std;

class My_class {

public:

    void operator()() const;
    int operator()(int a, int b) const;

private:

};

void My_class::operator()() const {
    cout << "The functor has been worked..." << endl;
}

int My_class::operator()(int a, int b) const {
    cout << "The functor has been worked..." << endl;
    int result = a * b;
    return result;
}

int main(int argc, char * argv[]) {

    My_class my_class;
    my_class(); // () -> we did overload operator ();

    My_class my_class2;
    int result = my_class2(100, 100); // 10 000
    cout << result << endl;

    return 0;
}
