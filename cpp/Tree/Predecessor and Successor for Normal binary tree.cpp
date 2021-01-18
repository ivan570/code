#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    explicit Node(int key) {
        this->key = key;
        left = right = nullptr;
    }
};

// rightMost
Node *rightMost(Node *root) {
    if (!root)
        return nullptr;
    if (!root->right)
        return root;
    return rightMost(root->right);
}

// leftMost
Node *leftMost(Node *root) {
    if (!root)
        return nullptr;
    if (!root->left)
        return root;
    return leftMost(root->left);
}
// Predecessor and Successor both
// if tree then is will work is complete
// else go for Inorder Successor in BST
void Predecessor(Node *root, int key, Node *&pre, Node *&succ) {
    if (!root)
        return;
    Predecessor(root->left, key, pre, succ);
    if (root->key == key) {
        if (root->left)
            pre = rightMost(root->left);
        if (root->right)
            succ = leftMost(root->right);
        return;
    }
    Predecessor(root->right, key, pre, succ);
}

int main()
{
    Node *root = new Node(200);
    root->left = new Node(15);
    root->right = new Node(56);
    root->left->left = new Node(110);
    root->left->right = new Node(171);
    root->right->left = new Node(520);
    root->right->right = new Node(476);

    root->left->left->left = new Node(2);
    root->left->left->right = new Node(3);

    root->left->right->left = new Node(4);
    root->left->right->right = new Node(5);

    root->right->left->left = new Node(6);
    root->right->left->right = new Node(7);

    root->right->right->left = new Node(8);
    root->right->right->right = new Node(9);

    Node *pre = nullptr, *succ = nullptr;
    int key = 15;
    Predecessor(root, key, pre, succ);
    cout << "Predecessor ";
    if (pre)
        cout << pre->key << endl;
    else
        cout << "-1" << endl;

    cout << "Successor ";
    if (succ)
        cout << succ->key << endl;
    else
        cout << "-1" << endl;
    return 0;
}