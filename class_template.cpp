#include <iostream>
#include <fstream>
using namespace std;

template<typename T>
class Person {
public:
    T value;
    int id;
    Person(T value, int id):value(value), id(id) {
        cout << "Person has been constructed" << endl;
    }
    virtual ~Person() {
        cout << "Person has been destroyed..." << endl;
    }
};
template<typename T>
class Employee: public Person<T> {
public:
    Employee(int id, T value):Person<T>(value, id) {
        cout << "Employee has been constructed" << endl;
    }
    ~Employee() {
        cout << "Employee has been destroyed..." << endl;
    }
};
template<typename T>
class SmartPointer {
public:
    SmartPointer(T* ptr) {
        this->ptr=ptr;
    }
    ~SmartPointer() {
        delete ptr;
    }
private:
    T* ptr;
};
template<typename T>
class MyClass1 {
public:
    void print(T value) {
        cout << value << endl;
    }
};

// defined specialty behavior for type string
template<>
class MyClass1<string> {
public:
    void print(string & value) {
        cout << "-----" << value << "-----"<< endl;
    }
};
int main(int argc,char*argv[]) {
    Person<std::string> * p = new Employee<std::string>(100, "RUSSO");
    cout << p->id << endl;
    cout << p->value << endl;
    delete p;

    system("echo -e '\n\n'");
    Person<double> * pp = new Employee<double>(100, 666.666);
    cout << pp->id << endl;
    cout << pp->value << endl;
    delete pp;

    MyClass1<int> c;
    c.print(545);
    MyClass1<string> mc;
    string s = "HOLA!!!";
    mc.print(s);
    return 0;
}