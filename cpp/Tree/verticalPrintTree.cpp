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

void inorder(Node *head) {
    if (head) {
        inorder(head->left);
        cout << head->data << " ";
        inorder(head->right);
    }
}

map<int, vector<int>> link;

void first(Node *head, int hd) {
    if (head) {
        link[hd].push_back(head->data);
        first(head->left, hd - 1);
        first(head->right, hd + 1);
    }
}

void vertical(Node *head) {
    first(head, 0);
    for (auto i : link) {
        vector<int> temp = i.second;
        for (int i : temp) {
            cout << i << " ";
        }
    }
}

int main() {
    Node *head = new Node(0);

    head->left = new Node(10);
    head->right = new Node(20);

    head->left->left = new Node(11);
    head->left->right = new Node(12);

    head->right->left = new Node(21);
    head->right->right = new Node(22);

    Node *rl = head->right->left;
    Node *rr = head->right->right;
    Node *ll = head->left->left;
    Node *lr = head->left->right;

    ll->left = new Node(111);
    ll->right = new Node(112);

    lr->left = new Node(121);
    lr->right = new Node(122);

    rl->left = new Node(211);
    rl->right = new Node(222);

    rr->left = new Node(221);
    rr->right = new Node(2222);

    inorder(head);
    cout << endl;
    vertical(head);

    return 0;
}
