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

int isSum(Node *head) {
    if (head == nullptr)
        return 0;
    if (head->left == nullptr && head->right == nullptr)
        return head->data;
    int left = isSum(head->left);
    int right = isSum(head->right);
    if (left == -1 || right == -1 || head->data != left + right)
        return -1;
    else
        return head->data * 2;
}

int main() {
    Node *head = new Node(70);

    head->left = new Node(20);
    head->right = new Node(30);

    head->left->left = new Node(10);
    head->left->right = new Node(10);

    if (isSum(head) != -1)
        cout << "yes it is" << endl;
    else
        cout << "no it's not" << endl;

    return 0;
}
