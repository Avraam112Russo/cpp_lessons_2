#include <functional>
#include <iostream>
#include <thread>
#include<vector>
using namespace std;

void foo(std::string& text) {
    cout << text << endl;
}
int bar(int a, int b) {
    return a + b;
}
void foo2(std::function<void()>f) {
    cout << "Call polymorphism functiion" << endl;
    f();
}

void foo3(vector<std::function<int(int, int)>> vector) {
    for (auto & el : vector) {
        // call multiple functions from vector
        int result = el(100, 100);

    }
}



int foo4(std::function<int(int , int )> & func, int a, int b) {
    return func(a, b);
}
int main(int argc, char * argv []) {

    std::function<void(std::string&)> f_ptr;
    f_ptr = foo;
    std::string text = "Hello, world!";
    f_ptr(text);



    std::function<int(int, int)> ff_ptr;
    ff_ptr = bar;
    int result = ff_ptr(20, 30);
    cout  << result << endl;



    auto f = [](int a, int b) -> int {
        return a + b;
    };
    std::function<int(int, int)> fff_ptr;
    fff_ptr = f;
    cout << fff_ptr(100, 200) << endl;




    // return result from other thread usage std::ref()
    cout<<"\n\n\n";
    auto func = []( int a, int b, int& c) {
        c = a + b;
    };
    int c;
    int a = 300;
    int b = 400;
    std::thread t(func,a,b, std::ref(c));
    t.join();
    cout << c << endl;
    return 0;
}