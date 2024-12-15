#include <iostream>
#define AA "HELLO, WORLD!\n"
#define PI 3.14
#define FOO(a, b) a > b ? a : b;
#define RATING 5

#define begin {
#define end }

// #define DEBUG


int main() {
using namespace std;
    cout<<AA; // compiler insert value -> cout << "HELLO, WORLD!\n" replace macros AA before compile
    cout<<PI<<"\n";

    int i = FOO(100, 200); // i = 200;
    cout << i << endl;

    for (int a = 0; a < 10; ++a)
        begin
        cout<<a<<endl;
        end




    #ifdef DEBUG
    cout << "debug mode \n"; // working if we define DEBUG

    #else
    cout << "production mode \n"; // working if nodefine DEBUG




    #endif



    return 0;
}