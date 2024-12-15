
#include <cstring>
#include <iostream>
using namespace std;



class Drive {
public:
    int speed;
    Drive(int speed):speed(speed){}
    void show_speed() {
        cout << "Drive with speed: " << this->speed << endl;
    }
};
class Fly {
public:
    int height;
    Fly(int height):height(height){}
    void show_fly_height() {
        cout << "Fly height: " << this->height << endl;
    }
};
class Airplane:public Drive, Fly{
public:
    char * brand;
    Airplane(int speed, int height, const char * brand):Drive(speed), Fly(height) {
        this->brand = new char[strlen(brand) + 1];
        strcpy(this->brand, brand);
    }
};
int main(int argc, char * argv []) {

    const char * name = "BOING";
    Airplane a {100,5500,name};
    a.show_speed();




    return 0;
}