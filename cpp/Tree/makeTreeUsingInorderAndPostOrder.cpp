#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left, *right;

    explicit Node(int data = 0) {
        this->data = data;
        left = right = nullptr;
    }
};

Node *createTree(const int in[], const int post[], int size, int inS, int inE, int postS, int postE) {
    if (inS > inE)
        return nullptr;
    int data = post[postE];
    Node *root = new Node(data);
    int index = -1;
    for (int i = inS; i <= inE; ++i) {
        if (in[i] == data) {
            index = i;
            break;
        }
    }
    int inLeftS = inS, inLeftE = index - 1,
            inRightS = index + 1, inRightE = inE;

    int postLeftS = postS, postLeftE = inLeftE - inLeftS + postLeftS,
            postRightE = postE - 1, postRightS = postLeftE + 1;
    root->left = createTree(in, post, size, inLeftS, inLeftE, postLeftS, postLeftE);
    root->right = createTree(in, post, size, inRightS, inRightE, postRightS, postRightE);
    return root;
}

void preorder(Node *root) {
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void inorder(Node *root) {
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int post[] = {11, 10, 12, 14, 16, 15, 13};
    int in[] = {11, 12, 10, 13, 14, 15, 16};
    int size = sizeof(in) / sizeof(in[0]);
    Node *root = createTree(in, post, size, 0, size - 1, 0, size - 1);
    cout << "preorder\n==> ";
    preorder(root);
    cout << "\ninoder\n==> ";
    inorder(root);
    cout << "\npostorder\n==> ";
    postorder(root);
    return 0;
}
