#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    explicit Node (int data = 0) {
        this->data = data;
        right = left = nullptr;
    }
};

void inorder(Node *head) {
    if (head) {
        inorder(head->left);
        cout << head->data << " ";
        inorder(head->right);
    }
}

Node *removeShortPathLessThanK(Node *head, int k) {
    if (head == nullptr)
        return nullptr;
    if (k == 0)
        return head;
    head->left = removeShortPathLessThanK(head->left, k - 1);
    head->right = removeShortPathLessThanK(head->right, k - 1);

    if (head->left  == nullptr && head->right == nullptr) {
        delete(head);
        return nullptr;
    }
    return head;
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(7);
    root->right->right = new Node(6);
    root->right->right->left = new Node(8);

    inorder(root);
    cout << endl;
    inorder(removeShortPathLessThanK(root, 3));

}

