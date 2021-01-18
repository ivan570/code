// AVL Tree Deletion
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next;

    explicit Node(int val, int height = 1) {
        data = val;
        next = nullptr;
    }
};

void deleteNode(Node *&first) {
    if (first->next == nullptr) {
        Node *temp = first;
        first = nullptr;
        delete(temp);
    }
    else {
        Node *temp = first;
        first = first->next;
        delete(temp);
    }
}

int main() {

    Node *head = new Node(23), *cur;
    head->next = new Node(90);
    head->next->next = new Node (231);
    head->next->next->next = new Node (2310);
    head->next->next->next->next = new Node (4310);

    deleteNode(head->next->next->next->next);
    cur = head;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    return 0;
}