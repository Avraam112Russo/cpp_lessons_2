#include<iostream>
int main(int argc, char * argv[]) {


    using namespace std;
    int i = 5;
    int b = ++i + ++i;
    cout<<b<<endl; // output: 14 (WHY???!!????)
    return 0;
}