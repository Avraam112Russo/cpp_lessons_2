#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
/*
void func() {
    int i = 0;
    std::cin >> i;
    if (i < 0) throw invalid_argument("value cannot be negative...");
    cout << "Your value: " << i << endl;
}
int main() {
    try {
        func();
    } catch (std::invalid_argument& exception) {
        cout << exception.what();
    }

    return 0;
}
*/


/*
void func() {
    int i = 0;
    std::cin >> i;
    if (i < 0) throw "error in func";
    if (i < 0) throw std::invalid_argument("Invalid argument....");
    if (true) throw 666; // for catch(...)
    cout << "Your value: " << i << endl;
}
int main() {
    try {
        func();
    } catch (std::exception&exception) {
        cout << "Something went wrong. Possible reason:" << exception.what() << endl;
    } catch (const char * exception) {
        cerr << "Something went wrong. Possible reason: " << exception << endl;
    } catch (...) {
        system("echo -e '\n\n' ");
        cerr << "Something went wrong. Reason undefined."<<endl;
    }

    return 0;
}
*/



/*
void foo() {
    fstream file("somefile.txt", ios::out);
    if (file.is_open()) {
        char text [1024];
        cout<<"Enter your message: "<<endl;
        cin.getline(text, 1024);
        file << text << endl;
        file.close();
    }
    cout<<"Success\n";


    ifstream read_file("dontexistfile.txt", ios::in);
    if (read_file.is_open()) {
        // some logic
    }
    else throw std::ifstream::failure("File not found exception");
}
int main(int argc, char * argv []) {

    try {
        foo();
    }catch (std::ifstream::failure & exception) {
        cout << exception.what() << endl;
        cout << "Error code: " << exception.code() << endl;
    }
    return 0;
}
*/



/*
class MyException:public std::invalid_argument{
public:
    const char * message;
    int data;
    MyException(const char * message, int data):message(message), data(data), invalid_argument(message) {
        cout << "My exception has been created..." << endl;
    }

private:
};
void func() {
    if (true) throw MyException("Message from my custom exception", 666);
}
int main(int argc, char * argv []) {

    try {
       func();
    }
    // catch (exception& exception) {
    //     cout << "Base exception has been worked..." << endl;
    // }
    catch (MyException& exception) {
        cout << exception.what() << endl;
        cout << exception.data << endl;
    }
    return 0;
}
*/


inline void foo() {
    cout << "Hello from inline function\n";

    std::vector<int> v = {100, 200, 300, 400, 500, 600};
    for (std::vector<int>::const_iterator cit = v.cbegin(); cit!=v.cend(); ++cit) cout << *cit << endl;
}
int main() {
    foo();
}