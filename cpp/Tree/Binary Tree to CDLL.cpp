#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void inorder(Node *root, Node *&first, Node *&rear) {
    if (!root)
        return;
    inorder(root->left, first, rear);
    if (!first) {
        Node *temp = newNode(root->data);
        first = rear = temp;
        first->left = first->right = rear;
    }
    else {
        Node *temp = newNode(root->data);
        rear->right = temp;
        temp->left = rear;

        temp->right = first;
        first->left = temp;

        rear = temp;
    }
    inorder(root->right, first, rear);
}

Node *bTreeToCList(Node *root)
{
    Node *first = nullptr, *rear = nullptr;
    inorder(root, first, rear);
    return first;
}
