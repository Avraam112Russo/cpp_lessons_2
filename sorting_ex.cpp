

#include <algorithm>
#include <iostream>
#include <set>

#include "System.h"
using namespace std;

//

// void insertion_sort(int arr [], int size) {
//     for (int i = 1; i < size; ++i) {
//
//         int j = i - 1;
//         int current = arr[i];
//
//         while (j >= 0 && arr[j] > current) {
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }
//
//         arr[j + 1] = current;
//     }
// }

// void bubble_sort(int arr[], int size) {
//     for (int i = 0; i < size - 1; ++i) {
//
//         for (int j = 0; j < size - i - 1; ++j) {
//
//             if (arr[j] > arr[j + 1]) {
//
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//
//             }
//         }
//     }
// }

void bubble_sort(int arr [], int size) {

    for (int i = 0; i < size - 1; ++i) {

        for (int j = 0; j < size - i - 1; ++j) {

            if (arr[j] > arr[j + 1]) {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

            }
        }
    }
}

void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {

        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

    }
}
template<typename T>
class List {
public:
    List() {
        this->head = nullptr;
        this->size = 0;
    }
    ~List() {
        cout << "List destructor has been worked..." << endl;
        clear();
    }
    int get_size();
    void push_back(T data);
    void push_front(T data);
    void pop_back();
    void pop_front();
    void insert(T data, int index);
    void remove_at(int index);
    void clear();
    T& operator[](int index);
private:
    class Node {
    public:
        T data;
        Node * next_node;
        Node(T data = T(), Node * next_node = nullptr) {
            this->data = data;
            this->next_node = next_node;
        }
        ~Node() {
            cout << "Node destructor has been worked..." << endl;
        }
    };
    Node * head;
    int size;
};

template<typename T>
int List<T>::get_size() {
    return this->size;
}

template<typename T>
void List<T>::push_back(T data) {
    if (this->head == nullptr) this->head = new Node(data);
    else {
        Node * current = this->head;
        while (current->next_node != nullptr) {
            current = current->next_node;
        }
        current->next_node = new Node(data);
    }
    ++size;
}

template<typename T>
void List<T>::push_front(T data) {
    this->head = new Node(data, this->head);
    ++size;
}

template<typename T>
void List<T>::pop_back() {
    Node * current = this->head;
    for (int i = 0; i < size - 1; ++i) {
        current = current->next_node;
    }
    delete current->next_node;
    current->next_node = nullptr;
    size--;
}

template<typename T>
void List<T>::pop_front() {
    Node * temp = this->head;
    this->head = this->head->next_node;
    delete temp;
    temp = nullptr;
    --size;
}

template<typename T>
void List<T>::insert(T data, int index) {
    if (index == 0) push_front(data);
    else {
        Node * current = this->head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next_node;
        }
        Node * temp = current->next_node;
        current->next_node = new Node(data, temp);
    }
    ++size;
}

template<typename T>
void List<T>::remove_at(int index) {
    if (index == 0) pop_front();
    else {
        Node * current = this->head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next_node;
        }
        Node * temp = current->next_node;
        current->next_node = temp->next_node;
        delete temp;
        temp = nullptr;
        --size;
    }
}

template<typename T>
void List<T>::clear() {
    Node * temp = this->head;
    while (size) {
        this->head = temp->next_node;
        delete temp;
        temp = nullptr;
        size--;
        temp = this->head;
    }
}

template<typename T>
T & List<T>::operator[](int index) {
    if (index == 0) return this->head->data;
    Node * current = this->head;
    int counter = 0;
    while (counter != index) {
        current = current->next_node;
        ++counter;
    }
    return current->data;
}


int main(int argc, char * argv []) {





    // remove duplicates;
    /*
    int arr [] = {100, 150, 200, 150, 130, 120, 200, 300, 320, 300, 300};
    // int * new_arr = new int [];
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; ++i) {


        int temp = arr[i];
        for (int j = 0; j < size; j++) {
            if (temp == arr[j]) {
                if (temp == arr[j] && j == i) continue;
                arr[j] = 0;
            }
        }
    }


    cout << "\n\n";
    for (auto&el:arr) {
        if (el != 0) {
            cout << el << endl; // output without duplicates;
        }
    }
    */


    /*
    int arr [] = {100, 150, 200, 150, 130, 120, 200, 300, 320, 300, 300};
    // bubble_sort(arr, std::size(arr));
    insertion_sort(arr, std::size(arr));
    std::for_each(std::begin(arr), std::end(arr), [](int num)->void{cout << num << endl;});
    */

    /*
    List<int> * l = new List<int>();
    l->push_back(100);
    l->push_back(200);
    l->push_back(300);
    l->push_back(400); //
    l->push_back(500);
    l->push_back(600);
    l->clear();
    cout << l->get_size() << endl;


    delete l;
    */

    System * s = new System(100, 50);
    s->print_result();




    return 0;
}
