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

Node *createTree() {
    int x;
    cout << "Enter the value ";
    cin >> x;

    // i dont want to continue
    if (x == -1)
        return nullptr;

    // i want to continue
    Node *root = new Node(x);

    // create tree for left side
    cout << "enter for left " << endl;
    root->left = createTree();

    // create tree for right side
    cout << "enter for right  " << endl;
    root->right = createTree();

    // return root
    return root;
}

int main() {
    Node *root = createTree();
    inorder(root);
}
