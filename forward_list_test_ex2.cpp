#include<iostream>

using namespace std;

template<typename T>
class List {
public:
    List() {
        this->head=nullptr;
        size=0;
    }
    ~List() {
        clear();
        cout << "Destructor of my list has been worked" << endl;
    }
    void push_back(T data);
    int get_size();
    void push_front(T data);
    void pop_front();
    void clear();
    void insert(T data, int index);
    void remove_at(int index);
    void pop_back();
    T& operator[](int index);
private:
    class Node {

    public:
        Node(T data = T(), Node * next_node = nullptr) {
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
    if (this->head == nullptr) this->head=new Node(data);
    else {
        Node * current = this->head;
        while (current->next_node != nullptr) {
            current = current->next_node;
        }
        current->next_node=new Node(data);
    }
    size++;
}

template<typename T>
int List<T>::get_size() {
    return this->size;
}

template<typename T>
void List<T>::push_front(T data) {
    this->head = new Node(data, this->head);
    size++;
}

template<typename T>
void List<T>::pop_front() {
    Node * temp = this->head;
    this->head=this->head->next_node;
    delete temp;
    temp = nullptr;
    size--;
}

template<typename T>
void List<T>::clear() {
    Node * temp = this->head;
    while (size) {
        this->head=this->head->next_node;
        delete temp;
        temp=nullptr;
        size--;
        temp=this->head;
    }
}

template<typename T>
void List<T>::insert(T data, int index) {
    if (index==0)push_front(data);
    else {
        Node * prev = this->head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->next_node;
        }
        Node * new_node = new Node(data, prev->next_node);
        prev->next_node=new_node;
    }
    size++;
}

template<typename T>
void List<T>::remove_at(int index) {
    if (index == 0) pop_front();
    else {
        Node * prev = this->head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->next_node;
        }
        Node * temp = prev->next_node;
        prev->next_node = temp->next_node;
        delete temp;
        size--;
    }
}

template<typename T>
void List<T>::pop_back() {
   remove_at(size - 1);
}


template<typename T>
T & List<T>::operator[](int index) {
    Node * current = this->head;
    int count = 0;
    while (count != index) {
        current = current->next_node;
        count++;
    }
    return current->data;
}


int main(int argc, char * argv []) {


    List<int> * l = new List<int>();
    l->push_back(100);
    l->push_back(200);
    l->push_back(300);

    for (int i = 0; i < l->get_size(); ++i) cout << l->operator[](i) << endl;
    cout << "\n";
    l->push_back(400);
    l->push_back(500);
    l->push_back(600);
    for (int i = 0; i < l->get_size(); ++i) cout << l->operator[](i) << endl;
    l->push_front(666);
    l->push_front(777);
    cout << "\n";
    for (int i = 0; i < l->get_size(); ++i) cout << l->operator[](i) << endl;


    l->pop_front();
    l->pop_front();
    l->pop_front();
    cout << "\n";
    for (int i = 0; i < l->get_size(); ++i) cout << l->operator[](i) << endl;
    printf("Size: %d", l->get_size());
    l->clear();
    printf("\nSize: %d\n\n", l->get_size());

    l->push_back(100);
    l->push_back(200);
    l->push_back(300);
    //666
    l->push_back(400);
    l->push_back(500);
    l->insert(666, 3);
    for (int i = 0; i < l->get_size(); ++i) cout << l->operator[](i) << endl;
    l->remove_at(3);cout<<"\n\n";
    for (int i = 0; i < l->get_size(); ++i) cout << l->operator[](i) << endl;
    cout << "\n\n";
    l->pop_back();
    l->pop_back();
    l->pop_back();
    l->pop_back();
    l->pop_back();
    cout << l->get_size() << endl;
    // for (int i = 0; i < l->get_size(); ++i) cout << l->operator[](i) << endl;
    delete l;
    return 0;
}
