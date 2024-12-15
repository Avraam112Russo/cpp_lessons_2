#include <chrono>
#include<iostream>
#include <thread>

void foo() {
    for (int i = 0; i < 5; ++i) {
        std::cout << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
int main(int argc, char * argv[]) {

    auto start = std::chrono::high_resolution_clock::now();
    foo(); // calling function in main thread
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration = end - start; // time for execute
    std::cout << "Result thread_main: \t" << duration.count() << std::endl; // 2.5s

    start = std::chrono::high_resolution_clock::now();
    std::thread t(foo);// calling function in other thread
    if (t.joinable()) t.join();
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Result thread_2: \t" << duration.count() << std::endl;
    return 0;
}
