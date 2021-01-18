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

int size(Node *head)
{
    if (head)
        return 1 + size(head->left) + size(head->right);
    return 0;
}

int main() {
    Node *head = new Node(23);
    head->left = new Node(34);
    head->right = new Node(45);
    head->left->left = new Node(90);
    head->left->right = new Node(45);
    head->right->left = new Node(45);
    head->right->right = new Node(45);

    cout << size(head);
    return 0;
}
