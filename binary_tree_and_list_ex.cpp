// #include <iostream>
// using namespace std;
//
//
// template<typename T>
// class List {
//
//
// public:
//     List() {
//         this->head = nullptr;
//         this->size = 0;
//     }
//     ~List() {
//         cout << "List destructor has been worked.."<< endl;
//         clear();
//     }
//     int get_size() {
//         return this->size;
//     }
//     void push_front(T data);
//     T& operator [](int index);
//     void pop_front();
//     void clear();
//     void push_back(T data);
//     void insert(T data, int index);
//     void remove_at(int index);
// private:
//     class Node {
//     public:
//     T data;
//     Node * next_node;
//
//         Node(T data = T(), Node * next_node = nullptr) {
//             this->data = data;
//             this->next_node=next_node;
//         }
//         ~Node() {
//             cout << "Node destructor has been worked.."<< endl;
//         }
//
//     };
//
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
// T& List<T>::operator [](int index) {
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
// void List<T>::pop_front() {
//     Node * temp = this->head;
//     this->head = this->head->next_node;
//     delete temp;
//     temp = nullptr;
//     --this->size;
//   }
//
// template<typename T>
// void List<T>::clear() {
//     Node * temp = this->head;
//     while (size) {
//         this->head = this->head->next_node;
//         delete temp;
//         temp = nullptr;
//         size--;
//         temp = this->head;
//     }
// }
//
// template<typename T>
// void List<T>::push_back(T data) {
//     if (this->head == nullptr) this->head = new Node (data);
//     else {
//         Node * current = this->head;
//         while (current->next_node != nullptr) {
//             current = current->next_node;
//         }
//         current->next_node = new Node(data);
//     }
//     ++size;
// }
//
//
//
// //
// // template<typename T>
// // void List<T>::insert(T data, int index) {
// //     if (index == 0) this->head = new Node(data, this->head);
// //     else {
// //         Node * previous = this->head;
// //         for (int i = 0; i < index - 1; ++i) {
// //             previous = previous->next_node;
// //         }
// //         Node * temp = previous->next_node;
// //         previous->next_node = new Node(data, temp);
// //     }
// //     ++size;
// // }
// template<typename T>
// void List<T>::insert(T data, int index) {
//     if (index == 0) this->head;
//     else {
//         Node * prev = this->head;
//         for (int i = 0; i < index  - 1; ++i)prev = prev->next_node;
//         prev->next_node=new Node(data, prev->next_node);
//     }
//     ++size;
// }
//
// template<typename T>
// void List<T>::remove_at(int index) {
//     if (index == 0) {
//         Node * temp = this->head;
//         this->head = this->head->next_node;
//         delete temp;
//         temp = nullptr;
//     }
//     else {
//         Node * prev = this->head;
//         for (int i = 0; i < index - 1; ++i) {
//             prev = prev->next_node;
//         }
//         Node * temp = prev->next_node;
//         prev->next_node = temp->next_node;
//         delete temp;
//         temp = nullptr;
//     }
//     --this->size;
// }
//
// /*
// template<typename T>
// void sort(List<T>& l) {
//
//     for (int i = 0; i < l.get_size() - 1; ++i) {
//
//         for (int j = 0; j < l.get_size() - i - 1; ++j) {
//
//             if (l.operator[](j) > l.operator[](j + 1)) {
//
//                 T temp = l.operator[](j);
//                 l.operator[](j) = l.operator[](j + 1);
//                 l.operator[](j + 1) = temp;
//
//             }
//         }
//     }
// }
// */
// template<typename T>
// void bubble_sort(List<T>& l) {
//     for (int i = 0; i < l.get_size() - 1; ++i) {
//
//         for (int j  = 0; j < l.get_size() - i - 1; ++j) {
//
//             if (l[j] > l[j + 1]) {
//                 T temp = l[j];
//                 l[j] = l[j + 1];
//                 l[j + 1] = temp;
//             }
//         }
//     }
// }
//
// template<typename T>
// class SmartPointer {
// public:
//     SmartPointer(T* ptr) {
//         this->ptr=ptr;
//     }
//     ~SmartPointer() {
//         cout << "Smart pointer constructor..." << endl;
//         delete ptr;
//
//     }
//     T& operator* () {
//         return *ptr;
//     }
// private:
//     T  * ptr;
// };
// int main(int argc, char * argv[]) {
//
//     SmartPointer<List<int>> l = new List<int>();
//     l.operator*().push_back(100);
//     l.operator*().push_back(90);
//     l.operator*().push_back(80);
//     l.operator*().push_back(70);
//     l.operator*().push_back(120);
//     l.operator*().push_back(150);
//     bubble_sort(*l);
//     for (int i = 0; i < l.operator*().get_size();++i)cout << l.operator*().operator[](i) << endl;
//     return 0;
// }
