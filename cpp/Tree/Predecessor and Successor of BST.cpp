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

void findPreSuc(Node *root, Node *&left, Node *&right, int key) {
    if (!root)
        return;
    findPreSuc(root->left, left, right, key);
    if (root->key < key)
        left = root;
    if (!right && root->key > key) {
        right = root;
        return;
    }
    findPreSuc(root->right, left, right, key);
}

int main()
{
    Node *root = new Node(23);
    root->left = new Node(15);
    root->right = new Node(56);
    root->left->left = new Node(10);
    root->left->right = new Node(17);
    root->right->left = new Node(50);
    root->right->right = new Node(76);

    Node *first = nullptr, *second = nullptr;
    pre_sur(root, first, second, 16);
    cout << "first ";
    if (first) 
        cout << first->key << endl;
    else 
        cout << "-1" << endl;
    
    cout << "second ";
    if (second)
        cout << second->key << endl;
    else 
        cout << "-1" << endl;
    return 0;
}