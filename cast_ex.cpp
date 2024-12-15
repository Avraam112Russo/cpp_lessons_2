
#include<iostream>
using namespace std;


void foo(const int & i) {
    const_cast<int &>(i) = 100;
    cout << i << endl;
}
int main(int argc, char * argv[]) {
    int i = 5;
    foo(i);
    return 0;
}