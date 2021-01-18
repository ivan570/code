#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    explicit Node(int data = 0) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

void inorder(Node *head, string *ans) {
    if (head) {
        inorder(head->left, ans);
        *ans += to_string(head->data) + " ";
        inorder(head->right, ans);
    }
}

void preorder(Node *head, string *ans) {
    if (head) {
        *ans += to_string(head->data) + " ";
        preorder(head->left, ans);
        preorder(head->right, ans);
    }
}

bool isSub(string one, string two) {
    return one.find(two) != string :: npos;
}

int main() {
    Node *first = new Node(20);
    first->left = new Node(30);
    first->right = new Node(40);
    first->left->left = new Node(45);
    first->left->right = new Node(45);
    first->right->right = new Node(45);

    Node *ll = first->left->left;
    ll->left = new Node(50);
    ll->left->left = new Node(67);

    Node *lr = first->left->right;
    lr->left = new Node(50);
    lr->right = new Node(57);
    lr->left->left = new Node(67);

    Node *rr = first->right->right;
    rr->left = new Node(80);
    rr->right = new Node(100);

    Node *second = new Node(45);
    second->left = new Node(50);
    second->right = new Node(57);
    second->left->left = new Node(67);

    string one = "";
    inorder(first, &one);

    string two = "";
    inorder(second, &two);

    if (isSub(one, two)) {
        one = "";
        two = "";
        preorder(first, &one);
        preorder(second, &two);
        if (isSub(one, two))
            cout << "Yes";
        else
            cout << "No";
    }
    else
        cout << "Not" << endl;
    return 0;
}

