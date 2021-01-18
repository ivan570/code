#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    explicit Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

void inorder(Node *root) {
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root, int &ansSum, int curSum, int curLevel, int &maxLevel) {
    if (!root)
        return;
    if (!root->left && !root->right) {
        if (curLevel > maxLevel) {
            ansSum = curSum + root->data;
            maxLevel = curLevel;
        } else if (curLevel == maxLevel) {
            ansSum = max(ansSum, curSum + root->data);
            maxLevel = curLevel;
        }
    }
    preorder(root->left, ansSum, curSum + root->data, curLevel + 1, maxLevel);
    preorder(root->right, ansSum, curSum + root->data, curLevel + 1, maxLevel);
}

int sumOfLongRootToLeafPath(Node *root) {
    if (!root)
        return 0;
    int ansSum = 0, curSum = 0, curLevel = 0, maxLevel = 0;
    preorder(root, ansSum, curSum, curLevel, maxLevel);
    return ansSum;
}

int main() {
    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->left->right->left = new Node(6);
    root->right = new Node(5);
    root->right->left = new Node(2);
    root->right->right = new Node(3);

    cout << sumOfLongRootToLeafPath(root);
    return 0;
}	