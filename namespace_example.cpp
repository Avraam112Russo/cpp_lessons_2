#include <array>
#include <iostream>
using namespace std;
namespace my_namespace {
    const char * c  = "Hello, Russo! \n";
}


int main(int argc, char * argv []) {
    std::cout << my_namespace::c;
    return 0;
}