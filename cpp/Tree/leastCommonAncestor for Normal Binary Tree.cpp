#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left, *right;
    explicit Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void inorder(Node *head)
{
    if (head)
    {
        inorder(head->left);
        cout << head->data << " ";
        inorder(head->right);
    }
}

void preorder(Node *head)
{
    if (head)
    {
        cout << head->data << " ";
        preorder(head->left);
        preorder(head->right);
    }
}

Node *normalTree(Node *root, int p, int q) {
    if (!root)
        return nullptr;

    if (p == root->data || q == root->data)
        return root;

    Node *left = normalTree(root->left, p, q);
    Node *right = normalTree(root->right, p, q);

    if (left && right)
        return root;

    if (left)
        return left;
    return right;
}

int main()
{
    Node *head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right->left = new Node(6);
    head->right->right = new Node(7);
    return 0;
}

