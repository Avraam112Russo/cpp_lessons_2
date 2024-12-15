#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
template<typename T>
class List {
public:

    List() {
        head = nullptr;
        size = 0;
    }
    ~List() {

    }
    void push_back(T);
    T& operator[](int);
    int get_size();
    void push_front(T data);
private:

    class Node {
    public:
        Node(T data=T(), Node * next_node=nullptr) {
            this->data=data;
            this->next_node=next_node;
        }
        ~Node() {

        }
        T data;
        Node * next_node;
    };
    Node * head;
    int size;
};

template<typename T>
void List<T>::push_back(T data) {
    if (this->head == nullptr) head = new Node(data);
    else {
        Node * current = this->head;
        while (current->next_node != nullptr) {
            current = current->next_node;
        }
        current->next_node=new Node(data);
    }
    ++size;
}

template<typename T>
T & List<T>::operator[](int index) {
    if (index == 0) return this->head->data;
        Node * current = this->head;
        int count = 0;
        while (count != index) {
            current = current->next_node;
            ++count;
        }
        return current->data;
}

template<typename T>
int List<T>::get_size() {
    return this->size;
}

template<typename T>
void List<T>
int main(int argc, char * argv []) {
    in
    List<int> * l = new List<int>();
    l->push_back(100);
    l->push_back(200);
    l->push_back(300);
    l->push_back(400);
    l->push_back(500);
    l->push_back(600);
    l->push_back(700);

    for (int i = 0; i < l->get_size();++i) {
        cout << l->operator[](i) << endl;
    }
    delete l;
    return 0;

}
