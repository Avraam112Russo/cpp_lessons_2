#include <forward_list>
#include <iostream>
#include <list>
#include <thread>
#include <unistd.h>
using namespace std;

template<typename T>
class MyList {
public:
    MyList();
    ~MyList();
    void push_back(T);
    int get_size();
    void pop_front();
    void delete_all();
    void clear();
    void push_front(int data);


    T& operator[](int index);

private:



    class Node {

    public:
        Node * next_node;
        T data;

        // T data=T() -> default values for any type data
        Node(T data=T(), Node * next_node = nullptr) {
            this->data=data;
            this->next_node=next_node;
        }
    };

    Node * head;
    int size;
};
















template<typename T>
MyList<T>::MyList() {
    size=0;
    head=nullptr;
};

template<typename T>
MyList<T>::~MyList() {
    clear(); // call my func clear and delete all elements from list
    cout << "List destructor has been worked..." << endl;
}

template<typename T>
int MyList<T>::get_size() {
    return size;
}

template<typename T>
T& MyList<T>::operator[](const int index) {
    Node* current = this->head;
    int counter = 0;
    while (current != nullptr) {
        if (counter == index) {
            return current->data;
        }
        current = current->next_node;
        counter++;
    }
}

template<typename T>
void MyList<T>::pop_front() {
    Node * temp = this->head;
    this->head = head->next_node;
    delete temp;
    size--;
}

template<typename T>
void MyList<T>::delete_all() {
    while (head!=nullptr) {
        pop_front();
    }
}

template<typename T>
void MyList<T>::clear() {
    while (size) { // size > 0 = true || size == 0  = false
        pop_front();
    }
    cout << "Clear function has been worked..." << endl;
}

template<typename T>
void MyList<T>::push_front(int data) {
    this->head = new Node(data, head);
    size++;
}


template<typename T>
void MyList<T>::push_back(T data) {
    if (head==nullptr) {
        head = new Node(data);
    } else {
        Node * current = this->head;
        while (current->next_node != nullptr) {
            current = current->next_node;
        }
        current->next_node = new Node(data);
    }
    ++size;
}


















int main() {
    cout << "===========================================================================" << endl;
    MyList<int> * list = new MyList<int>();
    list->push_back(100);
    list->push_back(200);
    list->push_back(300);
    list->push_back(400);
    list->push_back(500);
    list->push_back(600);
    list->push_back(700);

    cout << list->operator[](0) << endl;;
    cout << list->operator[](1) << endl;;


    cout << "===========================================================================" << endl;
    auto foo = [&list]() {
        list->pop_front(); // delete first element
        list->pop_front(); // delete first element
        cout << "Both front elements deleted successfully" << endl;
    };
    cout << "Size of list: " << list->get_size() << endl; // 5
    std::thread t(foo);
    if (t.joinable()) t.join();
    cout << "Size of list after deleted in other thread: " << list->get_size() << endl; // 3
    for (int i = 0; i < list->get_size();++i)cout << list->operator[](i) << endl;


    cout << "===========================================================================" << endl;
    cout << "Size of list: " << list->get_size() << endl;
    list->delete_all();
    cout << "Size of list after: " << list->get_size() << endl;
    cout << "===========================================================================" << endl;
    list->push_back(100);list->push_back(200);list->push_back(300);
    cout << "Size of list: " << list->get_size() << endl;
    list->clear(); // same func as delete_all();
    cout << "Size of list after: " << list->get_size() << endl;
    cout << "===========================================================================" << endl;
    list->push_front(100);
    list->push_front(200);
    cout << list->operator[](0) << endl;
    cout << list->operator[](1) << endl;
    delete list;
    return 0;
}
