#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

void foo(int result, std::mutex& mtx) {

}
int main(int argc, char * argv[]) {

    auto foo = [](int & result, std::mutex& mtx) {

        // when object lock_guard created it run the lock in constructor, then will be run unlock when it deleted from stack(from scope)


        // set scope for std::lock_guard manually usage { }
        {
        std::lock_guard<mutex> lock_guard(mtx);// lock()
        for (int i = 0; i < 1000000; ++i)
            ++result;

        // delete std::lock_guard<mutex> from stack and run unlock();
        }
        cout << "Unlock space code and it execute serve threads to one time" << endl;
        cout << "Unlock space code and it execute serve threads to one time" << endl;
    };
    int count = 0;
    std::mutex mtx;
    std::thread t(foo, std::ref(count), std::ref(mtx));
    std::thread t2(foo, std::ref(count), std::ref(mtx));

    if (t.joinable()) t.join();
    if (t2.joinable()) t2.join();

    cout << count << endl;
    return 0;
}