#include <cstring>
#include <iostream>
using namespace std;



/// rules of 3
/// A. Destructor
/// B. Copy constructor
/// C. Copy assignment operator (Overloading operator =)
///
/// rules of 5 added
/// D. Move constructor
/// E. Move assignment operator
///
///
///
/// rules of 0 when we use smart pointer
class Message {
public:
    char * text;
    Message(const char * input) {
        text = new char[strlen(input) + 1];
        strcpy(text, input);
    }

    // copy constructor
    Message(Message& other) {
        text = new char[strlen(other.text) + 1];
        strcpy(text, other.text);
    }
    // destructor
    ~Message() {
        delete[] text;
    }
    void show_text() {
        cout << text << endl;
    }
    // overloading operator =
    Message& operator= (const Message& other) {
        if (this != &other) {
            delete[] text;
            text = new char[strlen(other.text) + 1];
            strcpy(text, other.text);
        }
        return *this;
    }
    // move constructor
    Message (Message&& other)noexcept :text(other.text) {
        other.text = nullptr;
    }

    // move assignment operator,
    Message& operator=(Message&& other) noexcept {
        if (this != &other) {
            delete text;
            text = other.text;
            other.text = nullptr;
        }
        return *this;
};
template<typename T>
class SmartPointer {
public:
    SmartPointer(T* ptr):ptr(ptr){};
    T& operator* () {
        return *ptr;
    }
    ~SmartPointer() {
        cout<<"Destructor of smart pointer has been worked...\n";
        delete ptr;
    }
private:
    T* ptr;
};
int main(int argc, char * argv[]) {

    const char * text = "Hello, my friend.";
    SmartPointer<Message> ptr = (SmartPointer<Message>) new Message(text);
    ptr.operator*().show_text();

    return 0;
}