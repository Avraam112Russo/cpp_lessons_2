#include <iostream>
#include <queue>

using namespace std;



enum Color {
    RED, BLUE, BLACK, YELLOW, WHITE
};
class Car {
public:
    std::string name;
    Color color;
};
int main(int argc, char * argv []) {

    Car car;
    car.name="BMW";
    car.color=Color::WHITE;

    switch (car.color) {
        case Color::RED :
            cout << "RED COLOR CHOOSE" << endl;
        break;
        case Color::BLUE :
            cout << "BLUE COLOR CHOOSE" << endl;
        break;
        case Color::WHITE :
            cout << "WHITE COLOR CHOOSE" << endl;
        break;
        case Color::YELLOW :
            cout << "YELLOW COLOR CHOOSE" << endl;
        break;
        case Color::BLACK :
            cout << "BLACK COLOR CHOOSE" << endl;
        break;
        default:
            cout << "default value has been worked...";
    }
    return 0;

}