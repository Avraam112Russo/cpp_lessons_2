#include<iostream>
#include<fstream>
#include<vector>
using namespace std;



class Employee1 {
public:
    int id;
    std::string name;
    double salary;
    Employee1()=default;
    Employee1(int id, std::string name, double salary) {
        this->id=id;
        this->name=name;
        this->salary=salary;
    }
    friend ostream& operator<<(ostream& os, const Employee1& employee);
    friend istream& operator>>(istream& is, const Employee1& employee);
};

ostream& operator<<(ostream& os, const Employee1& employee){
    os << employee.id << " " << employee.name << " " << employee.salary << " ";
    return os;
}
istream& operator>>(istream& is, Employee1& employee) {
    is >> employee.id >> employee.name >> employee.salary;
    return is;
}





void write_read_text() {

    fstream file("some_file.txt", ios::out|ios::in|ios::app);
    if (file.is_open()) {
        std::string message;
        while (message != "stop") {
            cout << "Type your message: \n";
            getline(cin, message);
            if (message!="stop") file << message << endl;;
        }
        file.seekg(0);
        while (!file.eof()) {
            char buffer[1024];
            file.getline(buffer, 1024, '\n');
            cout << buffer << endl;
        }
        file.close();
    }
}

// ostream operator<<(const ostream & lhs, const Employee1 & rhs);

void write_object() {
    std::vector<Employee1> list_of_employees;
    Employee1 employee(100, "Zhores", 22.500);
    Employee1 employee2(200, "Leroy", 10.800);
    Employee1 employee3(300, "Michel", 40.300);
    list_of_employees.push_back(employee);
    list_of_employees.push_back(employee2);
    list_of_employees.push_back(employee3);
    fstream file("employee.txt", ios::out | ios::in | ios::app);
    // cout << employee;
    for (auto & emp : list_of_employees) file << emp << endl;
}
void read_object() {
    fstream file("employee.txt", ios::in);

    while (!file.eof()) {
        Employee1 employee;
        file >> employee;
        if (file.eof())break;
        cout << employee << endl;
    }

}
int main() {
    write_object();
    read_object();
    return 0;
}


/*
int main() {

    fstream file;
    file.open("myf.txt", ios::out | ios::in | ios::app);
    if (file.is_open()) {
        for (char a = 'a'; a <= 'z'; ++a) {
            file << a << endl;
        }
        cout << file.tellg() << endl;;
        file.seekg(15);
        cout << file.tellg()<< endl;;
        file.seekg(10);
        cout << file.tellg()<< endl;;
        file.seekg(15);
        cout << file.tellg()<< endl;;
        file.seekg(0);
        cout << file.tellg()<< endl;;
        file.seekg(15);
        cout << file.tellg()<< endl;;
        file.seekg(0);
        while (!file.eof()) {
            char buff [1024];
            file.getline(buff, 1024);
            cout << buff << endl;
        }
        file.close();
    }
    return 0;
}
*/

