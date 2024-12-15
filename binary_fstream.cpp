// reading an entire binary file
#include <iostream>
#include <fstream>
#include <numeric>
#include <vector>
using namespace std;


void foo() {

    std::ifstream input( "test_image.jpg", std::ios::binary );
    std::ofstream output( "new_copy_file.jpg", std::ios::binary );

    std::copy(
        std::istreambuf_iterator<char>(input),
        std::istreambuf_iterator<char>( ),
        std::ostreambuf_iterator<char>(output));
}
void foo2() {
    std::vector<int> from (10);
    std::iota(from.begin(), from.end(), 666); // fill vector values from 666 to 676


    // copy all values
    std::vector<int> to(from.size());
    std::copy(from.begin(), from.end(), to.begin());



    for (std::vector<int>::const_iterator cit = to.cbegin(); cit != to.end(); ++cit)
        cout << *cit << endl;
}
int main () {
    /*
    streampos size;
    char * memblock;

    ifstream file ("example.bin", ios::in|ios::out|ios::binary|ios::ate);//ios::ate -> Set the initial position at the end of the file.
    if (file.is_open())
    {
        size = file.tellg(); // stream position at the end
        memblock = new char [size];
        file.seekg (0, ios::beg); //  set the get position at the beginning of the file
        file.read (memblock, size);
        file.close();

        cout << "the entire file content is in memory";
        delete[] memblock;
    }

    else cout << "Unable to open file";
    */


    foo2();


    return 0;
}