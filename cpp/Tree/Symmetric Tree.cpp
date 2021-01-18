// Symmetric Tree

/*
Given a Binary Tree. Check whether it is Symmetric or not, i.e. whether the binary tree is a Mirror image of itself or not.

Example 1:

Input:
         5
       /   \
      1     1
     /       \
    2         2
Output: True
Explanation: Tree is mirror image of
itself i.e. tree is symmetric
Example 2:

Input:
         5
       /   \
      10     10
     /  \     \
    20  20     30
Output: False
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    explicit Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

bool fun(Node *root, Node *head) {
    if (!root && !head)
        return true;
    if (!root || !head)
        return false;
    if (root->data != head->data)
        return false;
    return fun(root->left, head->right) && fun(root->right, head->left);
}

bool isSymmetric(Node *root) {
    if(!root)
        return true;
    return fun(root->left, root->right);
}
