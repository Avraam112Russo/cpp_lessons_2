#include<iostream>
#include <queue>
#include<vector>
using namespace std;


/*
class Product {
public:
    int id;
    double price;
    Product() {
        cout << "Product constructor..." << endl;
    }
    Product(int id, double price) {
        cout << "Product constructor with args..." << endl;
        this->id=id;this->price=price;
    }
    virtual ~Product() {
        cout << "Product destructor..." << endl;
    }

    virtual void show_info() = 0;
};
class Laptop : public Product {
public:
    double diagonal_display;
    Laptop(int id, double price):Product(id, price) {
        cout << "Laptop constructor \n";
    }

    ~Laptop() override {
        cout << "Laptop destructor \n";
    }
    void show_info() override {
        cout<<"Laptop show info\n";
        system("echo -e '==========================\n' ");
    }
};
class HuaweiMateBook: public Laptop {

public:
    int old_price = 0;
    HuaweiMateBook(int id, double price):Laptop(id, price) {
        cout << "HuaweiMateBook constructor \n";
    }

    ~HuaweiMateBook() override {
        cout << "HuaweiMateBook destructor \n";
    }
    void show_info() override {
        cout<<"Huaweimatebook show info\n";
        system("echo -e '==========================\n' ");
    }
};
class Hp: public Laptop {
public:
    Hp(int id, double price):Laptop(id, price) {
        cout << "Hp constructor \n";
    }
    ~Hp() override {
        cout << "Hp destructor \n";
    }
    void show_info() override {
        cout<<"Hp show info\n";
        system("echo -e '==========================\n' ");
    }
};
void get_info(Product * product) {
    product->show_info();
}






class A {
protected:
    int id;
public:
    A() {
        cout<<"Object class A take memory\n";
    }
    virtual~A() {
        cout<<"Object class A return memory\n";
    }
};
class B:public A {
public:
    B() {
        cout<<"Object class B take memory\n";
    }
    ~B() override{
        cout<<"Object class B return memory\n";
    }
};





class Car {
protected:
    int id;
public:
    Car(int id):id(id) {}
    virtual ~ Car(){};
};
class Bmw :public Car{
public:
    int series;
    Bmw(int id, int series):Car(id) {
        this->series=series;
    }
    void show_info() {
        cout << "Id: " << id << ". Series: " << this->series << endl;
    }
    Bmw * operator ++ () {
        this->series++;
        return this;
    }
    };

struct Node {
    int data;
    Node * left;
    Node * right;
};
Node * get_new_node(int data) {
    Node * node = new Node;
    node->data=data;
    node->left=nullptr;
    node->right=nullptr;
    return node;
}
Node * insert(Node * root, int data) {
    if (root == nullptr) root=get_new_node(data);
    else if (data < root->data) root->left=insert(root->left, data);
    else root->right=insert(root->right, data);
    return root;
}
bool search(Node * root, int data) {
    if (root == nullptr) return false;
    if (root->data==data)return true;
    if (data<root->data)return search(root->left,data);
    return search(root->right,data);
}
void level_order(Node * root) {
    if (root == nullptr )return;
    std::queue<Node*> queue_nodes;
    queue_nodes.push(root);
    while (!queue_nodes.empty()) {
        Node * current = queue_nodes.front();
        cout << current->data << endl;
        if (current->left!=nullptr)queue_nodes.push(current->left);
        if (current->right!=nullptr)queue_nodes.push(current->right);
        queue_nodes.pop();
    }
}
int find_min(Node*root) {
    if (root==nullptr)return-1;
    if (root->left==nullptr)return root->data;
    return find_min(root->left);
}
int find_max(Node*root) {
    if (root==nullptr)return-1;
    if (root->right==nullptr)return root->data;
    return find_max(root->right);
}
void pre_order(Node*root) {
    if (root==nullptr)return;;
    cout<<root->data<<endl;
    pre_order(root->left);pre_order(root->right);
}
void in_order(Node*root) {
    if (root==nullptr)return;
    in_order(root->left);
    cout<<root->data<<endl;
    in_order(root->right);
}
void post_order(Node*root) {
    if (root==nullptr)return;
    post_order(root->left);
    post_order(root->right);
    cout<<root->data<<endl;
}
int find_height(Node*root) {
    if (root==nullptr)return-1;
    return max(find_height(root->left), find_height(root->right)) + 1;
}
Node * find_min_node(Node * root) {
    if (root==nullptr)return root;
    if (root->left==nullptr)return root;
    return find_min_node(root->left);
}
Node * delete_node(Node*root, int data) {
    if (root==nullptr)return root;
    if (data < root->data) root->left=delete_node(root->left, data);
    if (data > root->data) root->right=delete_node(root->right,data);
    else {
        if (root->left==nullptr&&root->right==nullptr) {
            delete root;
            root = nullptr;
        }
        else if (root->right==nullptr) {
            Node* temp = root;
            root = root->left;
            delete temp;
            temp=nullptr;
        }
        else if (root->left==nullptr) {
            Node * temp = root;
            root = root->right;
            delete temp;
            temp=nullptr;
        }
        else {
            Node * min_Node_in_right = find_min_node(root->right);
            root->data=min_Node_in_right->data;
            root->right=delete_node(root->right, min_Node_in_right->data);
        }
    }
    return root;
}
*/






int main(int argc, char * argv[]) {


    /*
    Product * huawei = new HuaweiMateBook(100, 500.5);;
    Product * laptop = new Laptop(200, 400.7);
    Product * hp = new Hp(300, 300.5);
    std::vector<Product*> v;
    v.push_back(huawei);
    v.push_back(laptop);
    v.push_back(hp);
    for (Product* product: v) {
        get_info(product);
    }
    delete huawei;
    delete laptop;
    delete hp;
    */







    /*
    A * a = new A;
    A * b = new B;
    delete a;
    delete b;
    */









    /*
    Car * bmw = new Bmw(100, 5);

    // cast for ptr
    cout << "Series: " << dynamic_cast<Bmw*>(bmw)->series << endl;;
    dynamic_cast<Bmw*>(bmw)->show_info();
    Bmw b(200, 4.4);


    // cast for ref
    Car& ref = b;
    dynamic_cast<Bmw&>(ref).show_info();
    delete bmw;;

    */








    /*
    Car * bmw = new Bmw(100, 7);
    Car cc(100);
    dynamic_cast<Bmw*>(bmw)->operator++();
    dynamic_cast<Bmw*>(bmw)->show_info();


    cout<<"========================"<<endl;
    Car * car = new Car(200);



    cout << typeid(bmw).name() << endl;
    cout << typeid(car).name() << endl;;

    const type_info& ti2 = typeid(bmw);
    const type_info& ti = typeid(cc);
    cout << "Comparison: " << (ti == ti2) << endl;

    cout << typeid(
    []()->std::string {
        return "Hello, world!";
    }()
    ).name()<<endl;




    delete bmw;
    delete car;
    */














    /*

    Node * root = nullptr;
    root=insert(root, 100);
    insert(root, 130);
    insert(root, 110);
    insert(root, 10);
    insert(root, 20);
    insert(root, 160);
    insert(root, 170);
    insert(root, 190);
    insert(root, 200);
    insert(root, 160);
    insert(root, 80);
    insert(root, 40);
    insert(root, 1660);

    if (search(root, 800)==true)cout<<"FOUND: 80"<<endl;
    else cout<<"NOT FOUND"<<endl;
    cout<<"============\n";
    level_order(root);
    cout<<"============\n";
    cout<<find_max(root)<<endl;cout<<find_min(root)<<endl;;
    system("echo -e 'pre_order\n'");
    pre_order(root);
    system("echo -e 'in_order\n'");
    in_order(root);
    system("echo -e 'post_order\n'");
    post_order(root);
    system("echo -e 'height\n'");
    cout<<find_height(root)<<endl;;
    delete_node(root, 80);
    cout << "==================\n";
    in_order(root);


    */





}