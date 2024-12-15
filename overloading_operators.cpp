#include<iostream>
using namespace std;

/*
class  MyClass {
public:
        int id;
        MyClass(int id):id(id) {
        };


        MyClass& operator = (const MyClass & other) {
                cout << "Operator = working... " << this << endl;;
                return *this;
        }
};
*/

class Product {
public:
        int price;
        double rating;
        int count_purchase;;
        Product(int price, double rating, int count_purchase):price(price),rating(rating),count_purchase(count_purchase){}
        Product(){}
        ~Product()=default;





        Product operator + (const Product& other_product) const {
                Product product;
                product.price = other_product.price + this->price;
                product.rating = other_product.rating + this->rating;
                product.count_purchase = 666;
                return product;
        }
        Product* operator * (const Product& other_product) {
                this->count_purchase *= other_product.count_purchase;
                this->price *= other_product.price;
                this->rating *=other_product.rating;
                return this;
        }
        Product* operator++() {
                this->count_purchase ++;
                this->price ++;
                this->rating ++;
                return this;
        }
        Product* operator--() {
                this->count_purchase --;
                this->price --;
                this->rating --;
                return this;
        }

};
int main(int argc, char * argv []) {

        Product product(2000, 4.4, 1000);
        Product product2(3000, 5.0, 2000);

        // operator +
        Product pr = product.operator+(product2);

        cout << pr.count_purchase << endl; // 666
        cout << pr.rating << endl; // 9.4
        cout << pr.price << endl; // 5000
        cout << "==================" << endl;
        // operator *
        cout << product.operator*(product2)->count_purchase << endl;; // 2 000 000
        cout << product.rating << endl; // 22
        cout << product.price << endl; // 6 000 000
        cout << "==================" << endl;
        //operator ++
        product.operator++();
        cout << product.count_purchase << endl; // 2 000 001
        cout << product.rating << endl; // 23
        cout << product.price << endl; // 6 000 001
        cout << "==================" << endl;
        //operator --
        product.operator--();
        cout << product.count_purchase << endl; // 2 000 000
        cout << product.rating << endl; // 22
        cout << product.price << endl; // 6 000 000
        return 0;
}