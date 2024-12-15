#include<iostream>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

};
//     15
//  10   20
//8   12   25
bool search(Node * root, int search_data) { // (15, 19) (17, 19) (19, 19)
    if (root == nullptr) return false;
    if (root->data == search_data) return true;
    if (search_data <= root->data) return search(root->left, search_data);
    return search(root->right, search_data);
}
int find_min(Node<int> * root) {
    if (root == nullptr) return -1;
    Node * current = root;
    while (current->left != nullptr) current = current->left;
    return current->data;
}

Node * create_new_node(int data) {
    Node * node = nullptr;
    node = new Node;
    node->data=data;
    node->left=nullptr;
    node->right=nullptr;
    return node;
}
//       15
//   10       17
// 9   13   16  19


Node *insert(Node * root, int data) {
    if (root == nullptr) {
        root = create_new_node(data);
    }
    else if (data <= root->data) {
        root->left=insert(root->left, data);
    }
    else {
        root->right=insert(root->right, data);
    }
    return root;
}

int main(int argc, char * argv []) {

    /*
    cout << "Arguments array length: " << argc << endl;
    for (int i = 0; i < argc; ++i) cout << argv[i] << endl;
    */


    Node * root = nullptr;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 12);
    //     15
    //  10   20
    //8   12   25
    int in;
    std::cin >> in;
    if (search(root, in) == true) std::cout << "Found: " << in << endl;
    else std::cout << "NOT FOUND." << endl;
    return 0;
}




/*


#include <iostream>
#include <queue>
#include <list>
#include <vector>
using namespace std;


struct MyNode {
    int data;
    MyNode * left;
    MyNode * right;
};
MyNode * get_new_node(int data) {
    MyNode * node = new MyNode;
    node->data=data;
    node->left=nullptr;
    node->right=nullptr;
    return node;
}
MyNode * insert(MyNode * root, int data) {
    if (root == nullptr) root = get_new_node(data);
    else if (data <= root->data) root->left=insert(root->left, data);
    else root->right=insert(root->right, data);
    return root;
}
int search(MyNode * root, int search_data) {
    if (root==nullptr) return -1;
    if (root->data==search_data) return root->data;
    if (search_data <= root->data) return search(root->left, search_data);
    return search(root->right, search_data);
}
int find_min(MyNode * root) {
    if (root == nullptr) return -1;
    while (root->left != nullptr) {
        root = root->left;
    }
    return root->data;
}
int find_min_recursive(MyNode * node) {
    if (node==nullptr)return -1;
    if (node->left == nullptr) {
        return node->data;
    }
    return find_min_recursive(node->left);
}

int find_max(MyNode* root) {
    if (root==nullptr)return -1;
    if (root->right==nullptr)return root->data;
    return find_max(root->right);
}
int find_height(MyNode * root) {
    if (root == nullptr) return -1;
    return max(find_height(root->left), find_height(root->right))+1;
}
void level_order(MyNode * root) {
    if (root==nullptr)return;
    std::queue<MyNode*> queue_nodes;
    queue_nodes.push(root);
    while (!queue_nodes.empty()) {
        root = queue_nodes.front();
        cout << "DATA: " <<root->data << endl;
        if (root->left!=nullptr)queue_nodes.push(root->left);
        if (root->right!=nullptr) queue_nodes.push(root->right);

        queue_nodes.pop();
    }
}

void pre_order (MyNode * root) {
    if (root == nullptr) return;
    cout << root->data << endl;
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(MyNode * root) { // only in binary search tree elements will be in order 123456789....
    if (root == nullptr) return;
    in_order(root->left);
    cout << root->data << endl;
    in_order(root->right);
}

void post_order(MyNode * root) {
    if (root == nullptr) return;
    post_order(root->left);
    post_order(root->right);
    cout << root->data << endl;
}
int main(int argc ,char * argv []) {

    //
    MyNode * root = nullptr;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 12);
    //     15
    //  10   20
    //8   12   25

    // int i;
    // cin>>i;
    // system("clear");
    // int result = search(root, i);
    // if (result == -1) cout << "Something went wrong..." << endl;
    // else cout << "FOUND: " << result << endl;
    // cout << "===================" << endl;
    // cout << "FIND MIN: " << find_min(root)<<endl;;
    // cout << "FIND MIN RECURSIVE: " << find_min_recursive(root)<<endl;;
    // cout << "FIND MAX RECURSIVE: " << find_max(root)<<endl;;
    // cout << "===================" << endl;
    // cout << "FIND HEIGHT: " << find_height(root)<<endl;;
    //

    cout << "PRE ORDER" << endl;
    pre_order(root);
    cout << "IN ORDER" << endl; // sequence 1234567...
    in_order(root);
    cout << "POST ORDER" << endl;
    post_order(root);
    return 0;

}
*/













/*

#include<iostream>
#include<queue>
using namespace std;


struct MyNode {
    int data;
    MyNode * left;
    MyNode * right;
};
MyNode * get_new_node(int data) {
    MyNode * node = new MyNode;;
    node->data=data;
    node->left=nullptr;
    node->right=nullptr;
    return node;
}
MyNode * insert (MyNode * root, int data) {
    if (root == nullptr) root = get_new_node(data);
    else if (data <= root->data) root->left=insert(root->left, data);
    else root->right=insert(root->right, data);
    return root;
}
bool search(MyNode * root, int search_data) {
    if (root == nullptr) return false;
    if (root->data == search_data) return true;
    if (search_data <= root->data) return search(root->left, search_data);
    return search(root->right, search_data);
}
void level_order(MyNode * root) {
    if (root == nullptr) return;
    std::queue<MyNode *> q_nodes;
    q_nodes.push(root);
    while (!q_nodes.empty()) {
        root = q_nodes.front();
        cout << "Date: " << root->data << endl;
        if (root->left != nullptr) q_nodes.push(root->left);
        if (root->right != nullptr) q_nodes.push(root->right);
        q_nodes.pop();
    }
}
void pre_order(MyNode * root) {
    if (root == nullptr) return;
    cout << "PRE ORDER DATA: " << root->data <<endl;
    pre_order(root->left);
    pre_order(root->right);
}
void in_order(MyNode * root) {
    if (root == nullptr) return;
    in_order(root->left);
    cout << "IN ORDER: " << root->data << endl;
    in_order(root->right);
}
int total = 0;
void post_order(MyNode * root) {
    if (root==nullptr) return;
    post_order(root->left);
    post_order(root->right);
    cout << "POST ORDER: " << root->data << endl;
}
MyNode * find_min(MyNode * root) {
    if (root == nullptr) return root;
    if (root->left == nullptr) return root;
    return find_min(root->left);
}
MyNode * delete_from_bts(MyNode * root, int data) {

    if (root == nullptr) return root;
    else if (data < root->data) {
        root->left = delete_from_bts(root->left, data);
    }
    else if (data > root->data) {
        root->right = delete_from_bts(root->right, data);
    }
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr) {
            MyNode * temp = root;
            root = root->right;
            delete temp;
            temp = nullptr;
        }

        else if (root->right == nullptr) {
            MyNode * temp = root;
            root = root->left;
            delete temp;
            temp = nullptr;
        }
        else {
            MyNode * temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete_from_bts(root->right, temp->data);
        }
    }


    return root;


    //       15
    //   10       20
    //8    12  18   25
    //            23   27
}
int main(int argc, char * argv []) {
    MyNode * root = nullptr;
    root = insert(root, 15);
    insert(root, 20);
    insert(root, 22);
    insert(root, 18);
    insert(root, 27);
    insert(root, 13);
    insert(root, 11);
    insert(root, 29);
    insert(root, 34);
    insert(root, 10);
    insert(root, 6);

    int search_data;
    std::cin >> search_data;
    if (search(root, search_data) == true) cout << "FOUND: " << search_data << endl;
    else cout << "NOT FOUND: " << search_data << endl;
    cout << "============================" << endl;
    level_order(root);
    cout << "============================" << endl;
    pre_order(root);
    cout << "============================" << endl;
    in_order(root);
    cout << "============================" << endl;
    post_order(root);
    return 0;
}

*/



/*

#include<iostream>
#include <queue>
using namespace std;


struct My_node {
    int data;
    My_node * left;
    My_node * right;
};
My_node * get_new_node(int data) {
    My_node * node = new My_node;
    node->data=data;
    node->left=nullptr;
    node->right=nullptr;
    return node;
}
My_node * insert(My_node * root, int data) {
    if (root==nullptr) root = get_new_node(data);
    else if (data <= root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}
int search(My_node * root, int search_data) {
    if (root == nullptr) return -1;
    if (search_data == root->data) return root->data;
    if (search_data < root->data) return search(root->left, search_data);
    return search(root->right, search_data);
}
int find_min(My_node * root) {
    if (root == nullptr) return -1;;
    if (root->left == nullptr) return root->data;
    return find_min(root->left);
}
My_node * find_min_node(My_node * root) {
    if (root == nullptr) return root;
    if (root->left == nullptr) return root;
    return find_min_node(root->left);
}
int find_max(My_node * root) {
    if (root == nullptr) return -1;
    while (root->right  != nullptr) {
        root = root->right;
    }
    return root->data;
}
void level_order(My_node * root) {
    if (root == nullptr) return;
    std::queue<My_node *> q;
    q.push(root);
    while (!q.empty()) {
        My_node * current = q.front();
        cout << "Data: " << current->data << endl;
        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
        q.pop();
    }
}
void pre_order(My_node * root) {
    if (root == nullptr) return;
    cout << root->data << endl;
    pre_order(root->left);
    pre_order(root->right);
}
void in_order(My_node * root) {
    if (root == nullptr) return;
    in_order(root->left);
    cout << root->data << endl;
    in_order(root->right);
}
void post_order(My_node * root) {
    if (root == nullptr)return;
    post_order(root->left);
    post_order(root->right);
    cout << root->data << endl;
}
My_node * find_minimum(My_node * root) {
    if (root == nullptr) return root;
    if (root->left == nullptr) return root;
    return find_minimum(root->left);
}
My_node * delete_node(My_node * root, int data) {
    if (root == nullptr)return root;
    else if (data < root->data) root->left = delete_node(root->left, data);
    else if (data > root->data) root->right = delete_node(root->right, data);
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        else if (root->right == nullptr) {
            My_node * temp = root;
            root = root->left;
            delete temp;
            temp = nullptr;
        }
        else if (root->left == nullptr) {
            My_node * temp = root;
            root = root->right;
            delete temp;
            temp = nullptr;
        }
        else {
            My_node * temp = find_minimum(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
}


My_node * find(My_node * root, int data) {
    if (root == nullptr) return root;
    if (root->data == data) return root;
    if (data < root->data) return find(root->left, data);
    return find(root->right, data);
}

My_node * get_successor(My_node * root, int data) {
    My_node * current = find(root, data);
    if (current == nullptr) return nullptr;
    if (current->right != nullptr) {
        return find_min_node(current->right);
    }else {
        My_node * successor = nullptr;
        My_node * parent = root;
        while (parent != current) {
            if (current->data < parent->data) {
                successor = parent;
                parent = parent->left;
            } else parent = parent->right;
        }
        return successor;
    }
}



My_node * get_next_element(My_node * root, int data) {
    My_node * current = find(root,data);
    if (current == nullptr) return nullptr;
    if (current->right != nullptr) {
        return find_minimum(current->right);
    }
    My_node * successor = nullptr;
    My_node * parent = root;
    while (parent->data != current->data) {
        if (current->data < parent->data) {
            successor = parent;
            parent = parent->left;
        } else parent = parent->right;
    }
    return successor;
}






//       15
//   10     20
//8    12     25




int main(int argc, char * argv []) {


    My_node * root = nullptr;
    root = insert(root, 15);
    insert(root, 20);
    insert(root, 17);
    insert(root, 14);
    insert(root, 22);
    insert(root, 27);
    insert(root, 2);
    insert(root, 29);
    insert(root, 30);
    insert(root, 44);
    insert(root, 666);
    insert(root, 90);
    int i = 0;
    cin>>i;
    int result = search(root, i);
    if (result != -1) cout <<"FOUND: "<< result << endl;
    else cout << "Something went wrong" << endl;
    cout << "====================" << endl;
    cout << "Min: " << find_min(root) << endl;
    cout << "Max: " << find_max(root) << endl;
    cout << " level order====================" << endl;
    level_order(root);
    cout << " pre order====================" << endl;
    pre_order(root);
    cout << " in order====================" << endl;
    in_order(root);
    cout << " post order====================" << endl;
    post_order(root);
    delete_node(root, 17);
    cout << " in order after delete====================" << endl;
    in_order(root);

    // My_node * root = nullptr;
    // root = insert(root, 15);
    // root = insert(root, 10);
    // root = insert(root, 20);
    // root = insert(root, 25);
    // root = insert(root, 8);
    // root = insert(root, 12);





    My_node * root = nullptr;
    root = insert(root, 15);
    insert(root, 20);
    insert(root, 22);
    insert(root, 18);
    insert(root, 27);
    insert(root, 13);
    insert(root, 11);
    insert(root, 29);
    insert(root, 34);
    insert(root, 10);
    insert(root, 6);

    My_node * successor = get_next_element(root, 10);
    cout << successor->data << endl;
    //     15
    //  10   20
    //8   12   25


    return 0;
}

*/