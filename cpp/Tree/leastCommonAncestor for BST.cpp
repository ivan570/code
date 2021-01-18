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

Node *insert(int data, Node *head)
{
    if (!head)
        return new Node(data);
    else
    {
        if (data > head->data)
            head->right = insert(data, head->right);
        else
            head->left = insert(data, head->left);
        return head;
    }
}

void inorder(Node *head)
{
    if (head)
    {
        inorder(head->left);
        cout << head->data << " ";
        inorder(head->right);
    }
}

void preorder(Node *head)
{
    if (head)
    {
        cout << head->data << " ";
        preorder(head->left);
        preorder(head->right);
    }
}

int LCA(Node *head, int x, int y)
{
    if (!head)
        return 0;
    while(head)
    {
        if (head->data < x && head->data < y)
            head = head->right;
        else if (head->data > x && head->data > y)
            head = head->left;
        else
            return head->data;
    }
}

int main()
{
    Node *head = NULL;
    head = insert(5*2, head);
    head = insert(3*2, head);
    head = insert(2*2, head);
    head = insert(4*2, head);
    head = insert(7*2, head);
    head = insert(8*2, head);
    head = insert(6*2, head);
    head = insert(1, head);
    head = insert(5, head);
    head = insert(7, head);
    head = insert(9, head);
    inorder(head);
    cout << endl;
    preorder(head);
    cout << endl << LCA(head, 1, 9);
    return 0;
}
