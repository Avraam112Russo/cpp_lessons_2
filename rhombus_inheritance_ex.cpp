#include <iostream>
using namespace std;



// make inherit from A with Virtual keyword, as in B and C class
// without Virtual inherit we get ambiguous error in D class
class A {
public:
    A() {
        cout<<"A has been constructed.\n";
    }
    virtual void foo() {

    }
};
class B: public virtual A {
public:

    B() {
        cout<<"B has been constructed.\n";
    }
    void foo()override {

    }
};
class C: public virtual A {
public:

    C() {
        cout<<"C has been constructed.\n";
    }
    void foo()override {

    }
};
class D: public B, public C {
public:

    D() {
        cout<<"D has been constructed.\n";
    }
};


int main(int argc, char * argv []) {
    D * d = new D();
    return 0;
}