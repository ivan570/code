#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    int height;
    Node *left, *right;

    Node(int data = 0) {
        this->data = data;
        height = 1;
        left = right = nullptr;
    }
};

Node *insert(Node *root, int data) {
    if (!root)
        return new Node(data);
    if (root->data > data)
        root->left = insert(root->left, data);
    if (root->data < data)
        root->right = insert(root->right, data);
    return root;
}

Node *getNext(Node *root) {
    if (root)
        return nullptr;
    while (root && root->left)
        root = root->left;
    return root;
}

Node *deleteNode(Node *root, int data) {
    if (!root)
        return nullptr;
    if (root->data > data)
        root->left = deleteNode(root->left, data);
    else if (root->data < data)
        root->right = deleteNode(root->right, data);
    else {
        if (!root->left && !root->right) {
            delete(root);
            return nullptr;
        }
        if (root->left && !root->right) {
            Node *temp = root->left;
            delete(root);
            return temp;
        }
        if (root->right && !root->left) {
            Node *temp = root->right;
            delete(root);
            return temp;
        }
        Node *temp = getNext(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node *root) {
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " height " << root->height << " ";
    cout << "left ";
    if (root->left)
        cout << root->left->data << " ";
    else
        cout << "-1 ";
    cout << "right ";
    if (root->right)
        cout << root->right->data << " ";
    else
        cout << "-1 ";
    cout << endl;
    inorder(root->right);
}

int main() {
    Node *root = nullptr;
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        root = insert(root, temp);
    }
    inorder(root);
    cout << "go for delete function " << endl;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        root = deleteNode(root, temp);
    }
    inorder(root);
    return 0;
}