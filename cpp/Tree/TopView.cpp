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

void topView(Node *root) {
    if (!root)
        return;

    queue<pair<Node *, int>> qu;
    map<int, int> index;

    pair<Node *, int> temp, loop;
    temp = make_pair(root, 0);

    qu.push(temp);

    while (!qu.empty()) {
        loop = qu.front();
        qu.pop();

        int cur = loop.second;
        Node *curNode = loop.first;
        if (!index[cur])
            index[cur] = curNode->data;

        if (curNode->left) {
            temp = make_pair(curNode->left, cur - 1);
            qu.push(temp);
        }
        if (curNode->right) {
            temp = make_pair(curNode->right, cur + 1);
            qu.push(temp);
        }
    }

    for (auto i : index) {
        cout << i.second << " ";
    }
}

int main() {
    Node *cur = new Node(1);
    cur->left = new Node(2);
    cur->right = new Node(3);
    cur->left->left = new Node(4);
    cur->left->right = new Node(5);
    cur->right->right = new Node(7);
    cur->right->left = new Node(6);

    topView(cur);
    return 0;
}