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

bool isSame(Node *first, Node *second)
{
    if (!first && !second)
        return true;
    if (first && second && first->data == second->data)
        return !(!isSame(first->left, second->left) || !isSame(first->right, second->right));
    
    return false;
}

int main()
{
    Node *head = new Node(23);
    head->left = new Node(34);
    head->right = new Node(45);
    head->left->left = new Node(90);
    head->left->right = new Node(45);
    head->right->left = new Node(45);
    head->right->right = new Node(45);

    Node *he = new Node(23);
    he->left = new Node(34);
    he->right = new Node(45);
    he->left->left = new Node(90);
    he->left->right = new Node(45);
    he->right->left = new Node(45);
    he->right->right = new Node(45);

    cout << isSame(head, he);
    return 0;
}
