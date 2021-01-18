#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, *right;

    explicit Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void levelTravel(Node *head)
{
    queue<Node *> arr;
    if (head)
    {
        arr.push(head);
        while (!arr.empty())
        {
            Node *temp = arr.front();
            arr.pop();
            cout << temp->data << " ";
            if (temp->left)
                arr.push(temp->left);
            if (temp->right)
                arr.push(temp->right);
        }
    }
}

int main() {
    Node *head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right->left = new Node(6);
    head->right->right = new Node(7);

    levelTravel(head);
    return 0;
}
