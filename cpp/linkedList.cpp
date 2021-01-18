#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data = -1;
    class Node *next;
};
typedef class Node node;
node *root = NULL;

int isThere(int key)
{
    node *temp = root;
    int f = 0;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            f++;
            break;
        }
        temp = temp->next;
    }
    return f;
}

node *getData()
{
    int data;
    cout << "   Enter your data ";
    cin >> data;
    cout << endl;
    node *cur = new node();
    cur->data = data;
    cur->next = NULL;
    return cur;
}

void push_back()
{
    if (root == NULL)
        root = getData();

    else
    {
        node *cur = root;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = getData();
    }
}

void deleteNode()
{
    int key;
    cout << "   Enter your key(delete) ";
    cin >> key;
    cout << endl;
    node *temp = root;
    int f = isThere(key);
    if (f == 0)
    {
        cout << "data not found" << endl;
        return;
    }
    if (root->data == key)
    {
        node *cur = root;
        root = root->next;
        free(cur);
    }
    else
    {
        node *cur = root;
        while (cur->next->data != key)
        {
            cur = cur->next;
        }
        node *temp = cur->next;
        cur->next = temp->next;
        free(temp);
    }
}

void show()
{
    node *cur = root;
    while (cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    if (root == NULL)
        cout << "   No data Found";
    cout << endl;
}

void insertAfter()
{
    int key;
    cout << "   Enter the key (data will inserted after key) ";
    cin >> key;
    node *cur = root;
    int f = isThere(key);
    if (f == 0)
    {
        cout << "data not found" << endl;
        return;
    }
    while (cur != NULL && cur->data != key)
        cur = cur->next;

    node *temp = getData();
    temp->next = cur->next;
    cur->next = temp;
}
void insertFirst()
{
    node *temp = getData();
    temp->next = root;
    root = temp;
}
void insertBefore()
{
    int key;
    cout << "   Enter the key(before data will inserted) ";
    cin >> key;
    cout << endl;
    if (key == root->data)
    {
        insertFirst();
        return;
    }
    int f = isThere(key);
    if (f == 0)
    {
        cout << "data not found" << endl;
        return;
    }
    else
    {
        node *temp = getData();
        node *cur = root;
        while (cur->next->data != key)
            cur = cur->next;
        temp->next = cur->next;
        cur->next = temp;
    }
}

int main()
{
    int ch = 0;
    cout << "1) for push_back " << endl;
    cout << "2) for delete " << endl;
    cout << "3) for show " << endl;
    cout << "4) for insert after key " << endl;
    cout << "5) for check cointain " << endl;
    cout << "6) for insert first " << endl;
    cout << "7) for insert before key " << endl;
    cout << "0) for exit " << endl;
    cout << "   Enter your ch ";
    cin >> ch;
    cout << endl;
    while (ch)
    {
        switch (ch)
        {
            case 1:
            push_back();
            break;
            case 2:
            deleteNode();
            break;
            case 3:
            show();
            break;
            case 4:
            insertAfter();
            break;
            case 5:
            cout << "   Enter the key(for serch) ";
            cin >> ch;
            if (isThere(ch))
                cout << "true" << endl;

            else
                cout << "false" << endl;
            break;
            case 6:
            insertFirst();
            break;
            case 7:
            insertBefore();
            break;
        }
        cout << "   Enter your ch ";
        cin >> ch;
        cout << endl;
    }
}