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

void leftView(Node *head, int curIndex) {
    static int max = 0;
    if (head) {
        if (max < curIndex) {
            cout << head->data << " ";
            max = curIndex;
        }
        leftView(head->left, curIndex + 1);
        leftView(head->right, curIndex + 1);
    }
}

/*
 *           1
 *      10      20
 *                  22
 *
 *  output => 1 10 22
 *
 * */

int main() {
    Node *head = new Node(1);

    head->left = new Node(10);
    head->right = new Node(20);

    head->right->right = new Node(22);

    inorder(head);
    cout << endl;
    leftView(head, 1);
    return 0;
}

