#include <atomic>
#include<iostream>
#include<thread>
#include <unistd.h>
#include <chrono>
using namespace std;
int main(int argc, char ** argv) {
    /*
    std::cout << "Main thread start..."<<endl;
    auto func = [](int i) {
        cout << "Arg i -> " << i << endl;
        cout << "2 thread start...\n";
        // sleep(5);
        this_thread::sleep_for(chrono::milliseconds(3000));
        cout << "2 thread finish...\n";
    };
    int i = 100;
    std::thread thread1(func, i);
    thread1.join();
    std::cout << "Main thread here..."<<endl;
    std::cout << "Main thread finish..."<<endl;
    */







    // undefined behavior
    /*

    int sum = 0;
    auto func = [&sum]() {
        cout<<"Thread: "<<this_thread::get_id()<<" start work "<<endl;
      for (int i = 0;i<1000000;++i)++sum;
        cout<<"Thread: "<<this_thread::get_id()<<" finish"<<endl;

    };
    std::thread t(func);
    std::thread t2(func);
    if (t.joinable()) t.join();
    if (t2.joinable())t2.join();
    cout<<sum<<endl;


    */



    // atomic operation
    // we will get expected result
    /*
    std::atomic<int> at_int {0};
    auto func = [&at_int]() {
      for (int i = 0; i < 1000000; ++i) ++at_int;
    };
    std::thread t(func);
    std::thread t2(func);
    if (t.joinable())t.join();
    if (t2.joinable())t2.join();

    std::cout<<at_int<<endl;
    */




    // load(); fetch_add()
    /*
    std::atomic<int> a {0};
    a.fetch_add(1);
    a.fetch_add(1);
    a.fetch_add(3);
    cout << a << endl; // 5
    std::atomic<int> b;

    b = a.load();
    cout << b << endl; // 5
    */

    thread_local int i = 10;
    cout << i << endl;
    int g = 100;
    return 0;
}