#include <cstring>
#include <iostream>
#include <fstream>
#include <thread>
using namespace std;
/*
void foo() {

    fstream file("my_file.txt", ios::out);
    if (file.is_open()) {

        file << "Hello, world!!!" << endl;
        cout << "File bad: " << file.bad() << "\n"; //Returns true if a reading or writing operation fails.
        file.close();
    }
    file.open("my_file.txt",ios::in);
    if (file.is_open()) {
        char temp [1024];
        file.getline(temp,1024);
        int i = 0;
        while (temp[i] != '\0') {
            cout << temp[i];
            ++i;
        }system("echo -e '\n'");
        cout << "Eof(): " << boolalpha << file.eof()<< endl;
        cout << "Fail(): " << file.fail()<< endl;
        cout << "Good(): " << file.good()<< endl;
        file.close();
    }else throw fstream::failure("File not found");

}
*/


/*
void write_text_to_file(std::string & text) {

    fstream file("myfile.txt", ios::out);
    if (file.is_open()) {
        file << text << flush;
        file.close();
    }
    file.open("myfile.txt", ios::in);
    if (file.is_open()) {
        char * temp = new char[1024];
        file.getline(temp, 1024);
        cout << temp << endl;
        file.close();
        delete [] temp;
    }
}
*/

using namespace std;
// Class to define the properties
class Employee1 {
public:
    string Name;
    int Employee_ID;
    int Salary;
};
int main(){
    Employee1 Emp_1;
    Emp_1.Name="John";
    Emp_1.Employee_ID=2121;
    Emp_1.Salary=11000;
    //Wriring this data to Employee.txt
    ofstream file1;
    file1.open("Employee.txt", ios::app);
    file1.write((char*)&Emp_1,sizeof(Emp_1));
    file1.close();
    //Reading data from EMployee.txt
    ifstream file2;
    file2.open("Employee.txt",ios::in);
    file2.seekg(0);
    file2.read((char*)&Emp_1,sizeof(Emp_1));
    printf("\nName :%s",Emp_1.Name);
    printf("\nEmployee ID :%d",Emp_1.Employee_ID);
    printf("\nSalary :%d",Emp_1.Salary);
    file2.close();
    return 0;
}