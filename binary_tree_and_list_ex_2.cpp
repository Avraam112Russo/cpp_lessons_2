// #include <iostream>
// #include<fstream>
// #include <queue>
// using namespace std;
//
// template<typename T>
// class Node {
// public:
//     T data;
//     Node * left;
//     Node * right;
// };
// template<typename T>
// Node<T> * get_new_node(T data) {
//     Node<T> * node = new Node<T>();
//     node->data = data;
//     node->left = nullptr;
//     node->right = nullptr;
//     return node;
// }
//
// template<typename T>
// Node<T> * search(Node<T> * root, T data) {
//     if (root == nullptr) return root;
//     if (root->data == data) return root;
//     if (data < root->data) return search(root->left, data);
//     return search(root->right, data);
// }
//
// template<typename T>
// Node<T> * insert(Node<T> * root, T data) {
//     if (root == nullptr) root = get_new_node(data);
//     else if (data < root->data) root->left = insert(root->left, data);
//     else root->right = insert(root->right, data);
//     return root;
// }
// template<typename T>
// void level_root(Node<T> * root) {
//     if (root == nullptr) return;
//     Node<T> * current = root;
//     std::queue<Node<T>*> q;
//     q.push(current);
//     while (!q.empty()) {
//         Node<T> * temp = q.front();
//         cout << temp->data << endl;
//         if (temp->left != nullptr) q.push(temp->left);
//         if (temp->right != nullptr) q.push(temp->right);
//         q.pop();
//     }
// }
// template<typename T>
// Node<T> * find_min(Node<T> * root) {
//     if (root == nullptr) throw std::invalid_argument("Root cannot be null");
//     if (root->left == nullptr) return root;
//     return find_min(root);
// }
//
// template<typename T>
// T& find_max(Node<T> * root) {
//     if (root == nullptr)throw invalid_argument("Root cannot be null");
//     if (root->right == nullptr) return root->data;
//     return find_max(root);
// }
// template<typename T>
// int find_height(Node<T> * root) {
//     if (root == nullptr) return -1;
//     return std::max(find_height(root->left), find_height(root->right)) + 1;
// }
// template<typename T>
// Node<T> * delete_node(Node<T> * root, T data) {
//     if (root == nullptr) return root;
//     else if (data < root->data) root->left = delete_node(root->left, data);
//     else if (data > root->data) root->right = delete_node(root->right, data);
//     else {
//         if (root->left == nullptr && root->right == nullptr) {
//             delete root;
//             root = nullptr;
//         }
//         else if (root->right == nullptr) {
//             Node<T> * temp = root;
//             root = root->left;
//             delete temp;
//             temp = nullptr;
//         } else if (root->left == nullptr) {
//             Node<T> * temp = root;
//             root = root->right;
//             delete temp;
//             temp = nullptr;
//         } else {
//             Node<T> * temp = find_min(root->right);
//             root->data = temp->data;
//             root->right = delete_node(root->right, temp->data);
//         }
//     }
//     return root;
// }
// template<typename T>
// void in_order(Node<T> * root) {
//     if (root == nullptr) return;
//     in_order(root->left);
//     cout << root->data << endl;
//     in_order(root->right);
// }
//
// template<typename T>
// class List {
// public:
//     List() {
//         this->head = nullptr;
//         this->size = 0;
//     }
//     ~List() {
//         clear();
//         cout << "List has been destroyed..." << endl;
//     }
//     void push_front(T data);
//     T& operator[](int index);
//     void clear();
//     int get_size();
// private:
//     class Node {
//     public:
//         Node(T data = T(), Node * next_node = nullptr) {
//             this->data = data;
//             this->next_node = next_node;
//         }
//         ~Node() {
//             cout << "Node with data " << data << " has been destroyed..." << endl;
//         }
//         T data;
//         Node * next_node;
//     };
//     Node * head;
//     int size;
// };
//
// template<typename T>
// void List<T>::push_front(T data) {
//     this->head = new Node(data, this->head);
//     ++size;
// }
//
// template<typename T>
// T & List<T>::operator[](int index) {
//     if (index == 0) return this->head->data;
//     Node * current = this->head;
//     int counter = 0;
//     while (counter != index) {
//         current = current->next_node;
//         ++counter;
//     }
//     return current->data;
// }
//
// template<typename T>
// void List<T>::clear() {
//     Node * temp = this->head;
//     while (size) {
//         this->head = this->head->next_node;
//         delete temp;
//         temp = nullptr;
//         --size;
//         temp = this->head;
//     }
// }
//
// template<typename T>
// int List<T>::get_size() {
//     return this->size;
// }
//
// template<typename T>
// class SmartPointer {
// public:
//     SmartPointer(T*ptr) {
//         this->ptr = ptr;
//     }
//     ~SmartPointer() {
//         delete ptr;
//         cout << "Smart pointer destructor has been worked..." << endl;
//     }
//     T& operator* () {
//         return *ptr;
//     }
//
// private:
//     T* ptr;
// };
// template<typename T>
// void bubble_sort(List<T> & l) {
//     for (int i = 0; i < l.get_size() - 1; ++i) {
//
//         for (int j = 0; j < l.get_size() - i - 1; ++j) {
//
//             if (l[j] > l[j + 1]) {
//                 T temp = l[j];
//                 l[j] = l[j + 1];
//                 l[j + 1] = temp;
//             }
//         }
//     }
// }
// int main(int argc, char * argv[]) {
//     Node<int> * root = nullptr;
//     root = insert(root, 100);
//     insert(root, 102);
//     insert(root, 98);
//     insert(root, 104);
//     insert(root, 96);
//     insert(root, 106);
//     insert(root, 92);
//     insert(root, 108);
//     insert(root, 90);
//
//     int val = 0;
//     system("echo -e 'Type the value: \n'");
//     cin >> val;
//     if (search(root, val) == nullptr)cout << "NOT_FOUND" << endl;
//     else cout << "FOUND: "<< val << endl;
//     cout << "\n\n\n";
//     level_root(root);
//     cout << "IN_ORDER\n";
//     in_order(root);
//     delete_node(root, 102);
//     cout << "IN_ORDER AFTER DELETING\n";
//     in_order(root);
//     cout << "======================" << endl;
//     SmartPointer<List<int>> l = new List<int>();
//     l.operator*().push_front(100);
//     l.operator*().push_front(90);
//     l.operator*().push_front(120);
//     l.operator*().push_front(80);
//     l.operator*().push_front(70);
//     l.operator*().push_front(130);
//     l.operator*().push_front(150);
//     cout << (*l).get_size() << endl;
//     cout << "Before: "<< endl;
//     for (int i = 0; i < (*l).get_size(); ++i) cout << (*l)[i] << endl;
//     bubble_sort((*l));
//     cout << "After: "<< endl;
//     for (int i = 0; i < (*l).get_size(); ++i) cout << (*l)[i] << endl;
//     return 0;
// }
