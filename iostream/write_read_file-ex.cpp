#include<iostream>
#include<fstream>
using namespace std;



class Mobile {
public:
    int id, price;
    string name;
};
void output_mobile() {
    Mobile mobile;
    mobile.id=100;
    mobile.name="Motorolla";
    mobile.price=12500;
    ofstream output_file("mobile.txt", ios::app);
        cout << "Output file is open. We can write the object." << endl;
        output_file.write((char*)&mobile, sizeof(mobile));
    Mobile mobile2;
    mobile2.id=200;
    mobile2.name="Nokia";
    mobile2.price=15000;
    if (output_file.is_open()) {
        cout << "Output file is open. We can write the object." << endl;
        output_file.write((char*)&mobile2, sizeof(mobile2));
    }
    output_file.close();
}
void input_mobile() {
    ifstream input_file_stream("mobile.txt", ios::in);
        cout << "Input file is open. We can READ the object." << endl;
        Mobile mobile;
        input_file_stream.read((char*)&mobile, sizeof(mobile));
        while (!input_file_stream.eof()) {
            cout << "ID: " << mobile.id << endl;
            cout << "NAME: " << mobile.name << endl;
            cout << "PRICE: " << mobile.price << endl;
            input_file_stream.read((char*)&mobile, sizeof(mobile));

        }
        input_file_stream.close();
}
int main(int argc, char * argv []) {


    output_mobile();
    input_mobile();
    return 0;
}