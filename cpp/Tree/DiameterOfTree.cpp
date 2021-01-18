#include <bits/stdc++.h>
using namespace std;

int max_dia = 0;
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

void in_order(Node *head)
{
    if (head)
    {
        in_order(head->left);
        cout << head->data << " ";
        in_order(head->right);
    }
}

void pre_order(Node *head)
{
    if (head)
    {
        cout << head->data << " ";
        pre_order(head->left);
        pre_order(head->right);
    }
}

int dia(Node *head)
{
    if (!head)
        return 0;
    int l = dia(head->left);
    int r = dia(head->right);
    int temp = l + r + 1;
    max_dia = max(max_dia, temp);
    if (l > r)
        return 1 + l;
    else
        return 1 + r;
}

int main()
{
    Node *head = new Node(1);
    head->left = new Node(2);
    head->left->left = new Node(4);
    head->left->left->left = new Node(14);
    head->left->left->left->left = new Node(114);
    head->left->right = new Node(5);
    head->left->right->right = new Node(15);
    head->left->right->right->right = new Node(16);
    in_order(head);
    cout << endl;
    pre_order(head);

    cout << endl << dia(head) << " " << max_dia;
    return 0;
}
