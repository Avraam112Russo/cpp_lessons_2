#include <iostream>
#include <thread>
#include <mutex>
using namespace std;


int main(int argc, char * argv[]) {
    int count = 0;
    std::mutex mtx;
    auto foo = [](int & count, std::mutex& mtx) {
        mtx.lock();
        for (int i = 0; i < 1000000; ++i) {

            // without mutex we have data race for count var
            ++count;
        }
        mtx.unlock();
        return count;
    };
    std::thread t(foo, std::ref(count), std::ref(mtx));
    std::thread t2(foo, std::ref(count), std::ref(mtx));
    t.join();
    t2.join();
    cout << count << endl;
    return 0;
}