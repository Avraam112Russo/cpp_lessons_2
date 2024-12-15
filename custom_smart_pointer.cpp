#include <iostream>

using namespace std;

template<typename T>
class SmartPointer {

public:
    SmartPointer(T* ptr) {
        this->ptr=ptr;
    }
    SmartPointer(){};
    ~SmartPointer() {
        cout<<"destructor work"<<endl;
        delete ptr;
    }
    T& operator * () {
        return *ptr;
    }


    // we should make ptr public
    T* operator -> () {
        return ptr;
    }
private:
    T* ptr;
};
class SomeClass {
public:
    int value;
    SomeClass(int a):value(a){};
};
int main(int argc, char * argv[]) {

    SmartPointer<int> smart_pointer = new int (5000);
    SmartPointer<SomeClass> smart_pointer2 = new SomeClass(100);
    cout<<smart_pointer.operator*()<<endl;;
    cout<<smart_pointer2.operator*().value<<endl;
    return 0;
}