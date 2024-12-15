// #include <iostream>
// #include <fstream>
// using namespace std;
//
//
// template<typename T>
// class List {
// public:
//
//     List();
//     ~List();
//     void push_back(T data);
//     int get_size() const;
//     void pop_front();
//     int clear();
//     void push_front(T data);
//     void insert(T data, int index);
//     T& operator[](int index);
// private:
//
//     class Node {
//     public:
//
//         Node(T data=T(), Node* next_node=nullptr) {
//             this->data=data;
//             this->next_node=next_node;
//         };
//         ~Node()=default;
//         T data;
//         Node * next_node;
//     };
//     Node * head;
//     int size;
// };
//
// template<typename T>
// List<T>::List() {
//     this->head=nullptr;
//     size=0;
// }
//
// template<typename T>
// List<T>::~List() {
//
// }
//
// template<typename T>
// void List<T>::push_back(T data) {
//     if (this->head==nullptr) this->head=new Node(data);
//     else {
//         Node * current = this->head;
//         while (current->next_node!=nullptr) {
//             current = current->next_node;
//         }
//         current->next_node=new Node(data);
//     }
//     size++;
// }
//
// template<typename T>
// int List<T>::get_size() const {
//     return this->size;
// }
//
// template<typename T>
// void List<T>::pop_front() {
//     Node * temp = this->head;
//     this->head=this->head->next_node;
//     delete temp;
//     size--;
//     temp=nullptr;
// }
//
// template<typename T>
// int List<T>::clear() {
//     Node * temp = this->head;
//     while (size) {
//         this->head = this->head->next_node;
//         delete temp;
//         size--;
//         temp=this->head;
//     }
//     return size;
// }
//
// template<typename T>
// void List<T>::push_front(T data) {;
//     this->head=new Node(data, this->head);
//     size++;
// }
//
// template<typename T>
// void List<T>::insert(T data, int index) {
//     if (index == 0) push_front(data);
//     else {
//         Node * prev = this->head;
//         for (int i = 0; i < index - 1; ++i) {
//             prev = prev->next_node;
//         }
//         Node * new_node = new Node(data, prev->next_node); // 10 20 30 40 50
//         prev->next_node = new_node;
//     }
// }
//
// //
// // template<typename T>
// // void List<T>::insert(T data, int index) {
// //     if (index == 0) push_front(data);
// //     else {
// //         Node * temp = this->head;
// //         for (int i = 0; i < index-1; ++i) { // 10 20 30 666 40 50
// //             temp=temp->next_node;
// //         }
// //         Node * new_node = new Node(data, temp->next_node);
// //         temp->next_node=new_node;
// //     }
// // }
//
// template<typename T>
// T & List<T>::operator[](int index) {
//     Node * current = this->head;
//     int count = 0;
//     while (count != index) {
//         current=current->next_node;
//         count++;
//     }
//     return  current->data;
// }
//
// int main(int argc, char * argv []) {
//
//     List<int> * l = new List<int>();
//     l->push_back(100);
//     l->push_back(200);
//     l->push_back(300);
//     l->push_back(400);
//     l->push_back(500);
//     int i = 0;
//     while (i < l->get_size()) {
//         cout << l->operator[](i) << endl;
//         i++;
//     }
//     system("echo -e '\n\n'");
//     l->pop_front();
//     l->pop_front();
//     for (int a = 0; a < l->get_size(); ++a)cout << l->operator[](a) << endl;
//     printf("Size: %d \n", l->get_size());
//     cout << l->clear() << endl;
//     printf("Size: %d \n ", l->get_size());
//     system("echo -e '\n\n'");
//     l->push_back(100);
//     l->push_back(200);
//     l->push_back(300);
//     l->push_back(400);
//     l->push_back(500);
//     l->push_front(666);
//     l->push_front(777);
//     for (int a = 0; a < l->get_size(); ++a)cout << l->operator[](a) << endl;
//     return 0;
//
// }



#include<iostream>
#include <queue>
using namespace std;

template<typename T>
class MyNode {
public:
    void set_left(MyNode * node);
    void set_right(MyNode * node);
    void set_data(T data);
    MyNode * get_left();
    MyNode * get_right();
    MyNode<T> * get_new_node(T data);
    MyNode<T> *  insert(MyNode<T>* root, T data);
    MyNode<T> * search(MyNode<T> * root, T data);
    void level_root(MyNode * root);
    T& find_min(MyNode * root);
    MyNode * find_min_node(MyNode * root);
    T& find_max(MyNode * root);
    int find_height(MyNode * root);
    void pre_order(MyNode * root);
    void in_order(MyNode * root);
    void post_order(MyNode * root);
    MyNode * delete_node(MyNode * root, int data);
private:
    T data;
    MyNode * left=nullptr;
    MyNode * right=nullptr;
};





template<typename T>
void MyNode<T>::set_left(MyNode *node) {
    this->left=node;
}

template<typename T>
void MyNode<T>::set_right(MyNode *node) {
    this->right=right;
}

template<typename T>
void MyNode<T>::set_data(T data) {
    this->data=data;
}

template<typename T>
MyNode<T> * MyNode<T>::get_left() {
    return this->left;
}

template<typename T>
MyNode<T> * MyNode<T>::get_right() {
    return this->right;
}

template<typename T>
MyNode<T> * MyNode<T>::get_new_node(T data) {
    MyNode<T> * node = new MyNode<T>();
    node->set_left(nullptr);
    node->set_right(nullptr);
    node->set_data(data);
    return node;
}

template<typename T>
MyNode<T> * MyNode<T>::insert(MyNode<T> * root, T data) {
    if (root == nullptr) root = get_new_node(data);
    else if (data < root->data) root->left=insert(root->left, data);
    else root->right=insert(root->right, data);
    return root;
}

template<typename T>
MyNode<T> * MyNode<T>::search(MyNode<T> *root, T data) {
    if (root==nullptr) return root;
    if (data == root->data) return root;
    if (data < root->data) return search(root->left, data);
    return search(root->right, data);
}

template<typename T>
void MyNode<T>::level_root(MyNode *root) {
    if (root == nullptr)return;
    MyNode * current = root;
    queue<MyNode*> q;
    q.push(current);
    while (!q.empty()) {
        current = q.front();
        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
        cout << current->data << endl;
        q.pop();
    }
}

template<typename T>
T& MyNode<T>::find_min(MyNode *root) {
    if (root==nullptr)throw std::invalid_argument("Root cannot be null");
    if (root->left == nullptr) return root->data;
    return find_min(root->left);
}

template<typename T>
MyNode<T> * MyNode<T>::find_min_node(MyNode *root) {
    if (root==nullptr)return root;
    if (root->left==nullptr)return root;
    return find_min_node(root->left);
}


template<typename T>
T& MyNode<T>::find_max(MyNode *root) {
    if (root==nullptr) throw std::invalid_argument("Root cannot be null");
    if (root->right==nullptr) return root->data;
    return find_max(root->right);
}

template<typename T>
int MyNode<T>::find_height(MyNode *root) {
    if (root==nullptr)return -1;
    return max(find_height(root->left), find_height(root->right)) + 1;
}

template<typename T>
void MyNode<T>::pre_order(MyNode *root) {
    if (root==nullptr)return;
    cout << root->data << endl;
    pre_order(root->left);
    pre_order(root->right);
}

template<typename T>
void MyNode<T>::in_order(MyNode *root) {
    if (root==nullptr)return;
    in_order(root->left);
    cout<<root->data<<endl;
    in_order(root->right);
}

template<typename T>
void MyNode<T>::post_order(MyNode *root) {
    if (root==nullptr)return;
    post_order(root->left);
    post_order(root->right);
    cout << root->data << endl;
}

template<typename T>
MyNode<T> * MyNode<T>::delete_node(MyNode *root, int data) {
    if (root == nullptr) return root;
    else if (data < root->data) root->left = delete_node(root->left, data);
    else if (data > root->data) root->right = delete_node(root->right, data);
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        else if (root->right == nullptr) {
            MyNode * temp = root;
            root = root->left;
            delete temp;
            temp = nullptr;
        }
        else if (root->left==nullptr) {
            MyNode * temp = root;
            root = root->right;
            delete temp;
            temp= nullptr;
        }
        else {
            MyNode * temp = find_min_node(root->right);
            root->data=temp->data;
            root->right=delete_node(root->right, temp->data);
        }
    }
    return root;
}

int main(int argc, char * argv[]) {

    MyNode<int> * root = nullptr;
    root = root->get_new_node(100);
    root->insert(root, 120);
    root->insert(root, 90);
    root->insert(root, 85);
    root->insert(root, 87);
    root->insert(root, 80);
    root->insert(root, 70);
    root->insert(root, 60);
    root->insert(root, 5);
    root->insert(root, 130);
    root->insert(root, 140);
    root->insert(root, 150);
    root->insert(root, 1500);
    root->insert(root, 180);

    root->level_root(root);
    if (root->search(root, 70)!=nullptr)cout << "FOUND" << endl;
    else cout << "NOT FOUND" << endl;
    cout << "================" << endl;
    cout << "Min: " << root->find_min(root) << endl;
    cout << "Max: " << root->find_max(root) << endl;
    cout << "Height: " << root->find_height(root) << endl;
    cout << "PRE: " << endl;
    root->pre_order(root);
    cout << "IN: " << endl;
    root->in_order(root);
    cout << "POST: " <<  endl;
    root->post_order(root);
    root->delete_node(root, 87);
    system("echo -e '\n\n'");
    root->in_order(root);
    return 0;
}
