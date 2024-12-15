#include <iostream>
#include <queue>
using namespace std;


struct My_node {
    int data;
    My_node * left;
    My_node * right;
};
My_node * get_new_node(int data) {
    My_node * new_node = nullptr;
    new_node = new My_node;
    new_node->data = data;
    new_node->left=nullptr;
    new_node->right=nullptr;
    return new_node;
}
My_node * insert(My_node * root, int data) {
    if (root == nullptr) root = get_new_node(data);
    else if (data <= root->data) root->left=insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}
bool search(My_node * root, int search_data) {
    if (root == nullptr) return false;
    if (root->data == search_data) return true;
    if (search_data < root->data) return search(root->left, search_data);
    return search(root->right, search_data);
}
My_node * find_min(My_node * root) {
    if (root == nullptr) return root;
    if (root->left == nullptr) return root;
    return find_min(root->left);
}
My_node * find_max(My_node * root) {
    if (root == nullptr) return root;
    if (root->right==nullptr) return root;
    return find_max(root->right);
}
int find_height(My_node * root) {
    if (root == nullptr) return -1;
    return std::max(find_height(root->left), find_height(root->right)) + 1;
}
void level_order(My_node * root) {
    if (root == nullptr) return;
    std::queue<My_node *> q;
    q.push(root);
    while (!q.empty()) {
        My_node * current = q.front();
        cout << "DATA: " << current->data << endl;
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
    if (root == nullptr) return;
    post_order(root->left);
    post_order(root->right);
    cout << root->data << endl;
}

My_node * delete_node(My_node * root, int data) {
    if (root == nullptr) return root;
    else if (data < root->data) root->left = delete_node(root->left, data);
    else if (data > root->data) root->right = delete_node(root->right, data);
    else {

        if (root->left ==  nullptr && root->right == nullptr) {
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
            My_node * temp = find_min(root->right);
            root->data = temp->data;
            root->right=delete_node(root->right, temp->data);

        }
    }
    return root;
}
    int main(int argc, char * argv []) {
        My_node * root = nullptr;
        root = insert(root, 15);
        root = insert(root, 10);
        root = insert(root, 20);
        root = insert(root, 25);
        root = insert(root, 8);
        root = insert(root, 12);

        int i = 0;
        cout << "Type the value: ";
        cin >> i;
        if (search(root, i) == true) cout << "FOUND: " << i << endl;
        else cout << "NOT_FOUND" << endl;



        cout << "========================" << endl;
        cout << "MAX: " << find_max(root)->data << endl;
        cout << "MIN: " << find_min(root)->data << endl;
        cout << "========================" << endl;
        cout << "Height: " << find_height(root) << endl;
        cout << "========================" << endl;
        cout << "level order: " << endl;
        level_order(root);
        cout << "========================" << endl;
        cout << "pre order: " << endl;
        pre_order(root);
        cout << "========================" << endl;
        cout << "in order: " << endl;
        in_order(root);
        cout << "========================" << endl;
        cout << "post order: " << endl;
        post_order(root);
        cout << "========================" << endl;
        delete_node(root, 10);
        in_order(root);
        cout << "pre ===" << endl;
        pre_order(root);
        cout << "post ===" << endl;
        post_order(root);
        return 0;
    }
