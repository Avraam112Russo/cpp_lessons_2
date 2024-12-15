#include <memory>
#include<iostream>
using namespace std;



int main(int argc, char ** argv) {


    // change directly pointer
    std::auto_ptr<int> ptr (new int(100));
    cout<<ptr.get()<<endl; // output: 0x5eaaf3f0d2b0
    std::auto_ptr<int> ptr2(ptr); // change pointer for this place memory
    cout<<ptr.get()<<endl; // output: 0
    cout<<ptr2.get()<<endl; // output: 0x5eaaf3f0d2b0




    cout << "======================" << endl;
    // change pointer for place memory usage std::move();
    std::unique_ptr<int> uptr (new int(500));
    cout<<uptr.get()<<endl; // 0x5fcf5ec496e0
    std::unique_ptr<int> uptr2 (std::move(uptr));
    cout<<uptr.get()<<endl; // 0
    cout<<uptr2.get()<<endl; // 0x5fcf5ec496e0




    cout << "======================" << endl;
    std::unique_ptr<int> uptr_3(new int(1000));
    cout << *uptr_3 << endl; // 1000
    cout << *uptr_3.get() << endl; // same output: 1000



    cout << "======================" << endl;
    std::unique_ptr<double> dptr(new double(4.4));
    dptr.release();// 4.4 value stay, but ptr is free



    cout << "======================" << endl;
    std::unique_ptr<double> dptr2(new double(6.6));
    cout << *dptr2 << endl;
    dptr2.reset(); // delete value and ptr is free



    // shared_ptr
    cout << "======================" << endl;
    std::shared_ptr<int> sp (new int(300));
    std::shared_ptr<int>sp2(sp);
    cout << sp2.use_count() <<"\n"; // output: 2




    // smart_ptr work with array
    cout << "======================" << endl;
    int size_arr = 5;
    std::shared_ptr<int[]>ptr_arr(new int[size_arr]{100, 200, 300, 400, 500});
    for (int i = 0; i < size_arr;++i)    cout << ptr_arr[i] << endl;
    return 0;
}