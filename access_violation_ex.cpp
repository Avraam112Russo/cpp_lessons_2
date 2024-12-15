#include <iostream>
int main() {


    // ACCESS VIOLATION
    // Three main reasons

    ///Dereferencing a null or invalid pointer.
    ///Accessing an array out of bounds.
    ///Reading or writing to memory freed by the user or the operating system.

    int *p = nullptr;
    int x = *p;

    using namespace std;
    int arr[5] = {1, 2, 3, 4, 5};
    cout << arr[5];
    cout << "helo"<<endl;



    int* p2 = new int[10];
    delete[] p2;
    p2[3] = 42;  // Access violation: writing to memory that has been freed
    return 0;
}