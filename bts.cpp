#include <iostream>
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
    if (root == nullptr) root = get_new_node(data);
    else if (data <= root->data) root->left=insert(root->left, data);
    else root->right=insert(root->right, data);
    return root;
}
My_node * find (My_node * root, int data) {
    if (root == nullptr) return root;
    if (root->data == data) return root;
    if (data < root->data) return find(root->left, data);
    return find(root->right, data);
}
void level_root(My_node * root) {
    if (root == nullptr) return;
    std::queue<My_node *> q;
    q.push(root);
    while (!q.empty()) {
        My_node * current = q.front();
        cout << "Data from queue: " << current->data << endl;
        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
        q.pop();
    }
}
My_node * find_min(My_node * root) {
    if (root == nullptr) return root;
    if (root->left == nullptr) return root;
    return find_min(root->left);
}
My_node * find_max(My_node  * root) {
    if (root == nullptr) return root;
    if (root->right == nullptr) return root;
    return find_max(root->right);
}

int find_height(My_node * root) {
    if (root == nullptr) return -1;
    return max(find_height(root->left), find_height(root->right)) + 1;
}
void in_order(My_node * root) {
    if (root == nullptr) return;
    in_order(root->left);
    cout << root->data << endl;
    in_order(root->right);
}
My_node * delete_node(My_node * root, int data) {
    if (root  == nullptr) return root;
    else if (data < root->data) root->left=delete_node(root->left, data);
    else if (data > root->data) root->right=delete_node(root->right, data);
    else {
        if (root->left == nullptr && root->right == nullptr ) {
            delete root;
            root = nullptr;
        }
        else if (root->right == nullptr) {
            My_node * temporary = root;
            root = root->left;
            delete temporary;
            temporary  = nullptr;
        }
        else if (root->left == nullptr) {
            My_node * temporary = root;
            root = root->right;
            delete temporary;
            temporary = nullptr;
        }
        else {
            My_node * min_at_right = find_min(root->right);
            root->data = min_at_right->data;
            root->right=delete_node(root->right, min_at_right->data);
        }


    }
    return root;
}

My_node * get_successor(My_node * root, int data) {
    My_node * current = find(root, data);
    if (current == nullptr) return nullptr;
    if (current->right != nullptr) {
        return find_min(current->right);
    }
    My_node * successor = nullptr;
    My_node * parent = root;
    while (parent->data != current->data) {
        if (current->data < parent->data) {
            successor = parent;
            parent = parent->left;
        } else {
            parent=parent->right;
        }
    }
    return successor;
}
int main(int argc, char * argv []) {

    My_node * root = nullptr;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 6);
    root = insert(root, 12);
    level_root(root);
    cout << "=======================" << endl;
    // My_node * found_node = find(root, 111);
    // if (found_node != nullptr) cout << "Result: " << found_node->data << endl;
    // else cout << "Not found..." << endl;

    //
    // cout << "=======================" << endl;
    // My_node * min = find_min(root);
    // My_node * max = find_max(root);
    // cout << "Min: " << min->data << endl;
    // cout << "Max: " << max->data << endl;



    // cout << find_height(root) << endl;
    // in_order(root);

    // cout << "=======================" << endl;
    // delete_node(root, 6);
    // delete_node(root, 10);
    // in_order(root);
    cout << get_successor(root, 20)->data << endl;;


    return 0;


}