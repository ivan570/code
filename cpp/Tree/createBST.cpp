// create tree
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    explicit Node(int data = 0) {
        this->data = data;
        left = right = nullptr;
    }
};

void inorder(Node *root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

Node *binarySearchTree(Node *root, int data) {
    if (!root) {
        root = new Node(data);
        return root;
    }
//    data is less than root->data
//    goto left
    if (root->data > data) {
        root->left = binarySearchTree(root->left, data);
    }
//    if greater than root->data and not equal to any data;
//    goto right
    else if (root->data != data) {
        root->right = binarySearchTree(root->right, data);
    }

//    if it's equal
    else {
        return root;
    }
    return root;
}

int main() {
    Node *root = nullptr;
    for (int i = 0; i < 5; ++i) {
        int x = 0;
        cout << "enter the element ";
        cin >> x;
        cout << endl;
        root = binarySearchTree(root, x);
    }
    inorder(root);
}
