#include <iostream>
#include<thread>
#include<chrono>

class MyClass {
public:
    int foo();
};

int MyClass::foo() {
    std::cout << "Foo has been started..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout << "Foo has been finished..." << std::endl;
    return 100 + 100;
}

int main() {
    using namespace std;
    MyClass class_;
    int result;

    // pass Myclass object and call function in other thread
    std::thread t([&]() {
        result = class_.foo();
    });


    for (int i = 0; i < 10; ++i) {
        std::cout << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    if (t.joinable()) t.join();
    cout << result << endl;
    return 0;
}
