#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

// // callback function
// int foo(char c) {
//     return (int)c;
// }
//
// // another function that is taking callback
// void printASCIIcode(char c, int(*func_ptr)(char ch))
// {
//     int ascii = func_ptr(c);
//     cout << "ASCII code of " << c << " is: " << ascii;
// }
//
// // driver code
// int main()
// {
//
//     std::vector<int> nums = {1, 2, 3, 4, 5};
//     std::for_each(nums.begin(), nums.end() - 1, [](int n) { std::cout << n << " \n"; });
//     cout << "================\n";
//     printASCIIcode('a', &foo);
//     return 0;
// }

struct MyNode {
    int data;
    MyNode * left;
    MyNode * right;

};
MyNode * get_new_node(int data) {
    MyNode * node = nullptr;
    node = new MyNode;
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
MyNode * find_node(MyNode * root, int data) {
    if (root == nullptr) return nullptr;
    if (root->data == data) return root;
    if (data < root->data) return find_node(root->left, data);
    return find_node(root->right, data);
}
int find_min(MyNode * root) {
    if (root==nullptr) return -1;
    if (root->left==nullptr) return root->data;
    return find_min(root->left);
}
int find_max(MyNode * root) {
    if (root==nullptr)return -1;
    if (root->right==nullptr)return root->data;
    return find_max(root->right);
}
int find_height(MyNode* root) {
    if (root==nullptr)return -1;
    return max(find_height(root->left), find_height(root->right)) + 1;
}
int main(int argc, char * argv[]) {
    MyNode * root = nullptr;
    root = insert(root, 15);
    insert(root, 20);
    insert(root, 13);
    insert(root, 24);
    insert(root, 10);
    insert(root, 8);
    insert(root, 26);
    insert(root, 30);
    int in;
    cin>>in;
    MyNode * maybe_node = find_node(root, in);
    if ( maybe_node == nullptr) cout << "Not found" << endl;
    else cout << "Found: " << maybe_node->data << endl;
    cout << "Min: " << find_min(root )<< endl;
    cout << "Max: " << find_max(root )<< endl;
    cout << "Height: " << find_height(root )<< endl;
    return 0;
}

















