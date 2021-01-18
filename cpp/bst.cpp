#include <iostream>
#include <queue>
using namespace std;

struct BST_Node {
    int data;
    struct BST_Node *left;
    struct BST_Node *right;
};

typedef struct BST_Node node;

node* getNewNode(int data) {
    node* newNode = (node *) malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* insert(node* head, int data) {
    if (head == NULL) {
        head = getNewNode(data);
    } else {
        if (data >= head->data) {
            head->right = insert(head->right, data);
        } else {
            head->left = insert(head->left, data);
        }
    }

    return head;
}

void inOrder(node* head) {
    if (head == NULL)
        return;
    inOrder(head->left);
    cout << " " << head->data;
    inOrder(head->right);
}

void postOrder(node* head) {
    if (head == NULL)
        return;
    postOrder(head->left);
    postOrder(head->right);
    cout << " " << head->data;
}

void preOrder(node* head) {
    if (head == NULL)
        return;
    cout << " " << head->data;
    preOrder(head->left);
    preOrder(head->right);
}

void levelOrder(node* head) {
    if (head == NULL)
        return;

    queue<node *> que;
    que.push(head);

    while (!que.empty()) {
        node* temp = que.front();
        cout << " " << temp->data;
        if (temp->left != NULL)
            que.push(temp->left);

        if (temp->right != NULL)
            que.push(temp->right);

        que.pop();
    }
}

bool search(node* head, int data) {

    if (head == NULL)
        return false;
    if (head->data == data)
        return true;
    if (head->data < data)
        return search(head->right, data);
    else if (head->data > data)
        return search(head->left, data);

    return false;
}

node* find(node* head, int data) {

    if (head == NULL)
        return NULL;
    if (head->data == data)
        return head;
    if (head->data < data)
        return find(head->right, data);
    else if (head->data > data)
        return find(head->left, data);

    return NULL;
}

node* min(node* head) {
    node* temp = head;
    node* ans = 0;
    if (head == NULL)
        ans = NULL;

    else {
        while (temp->left != NULL) {
            temp = temp->left;
        }
        ans = temp;
    }
    return ans;
}

node* max(node* head) {
    node* ans = 0;
    node* temp = head;
    if (head == NULL)
        ans = NULL;

    else{
        while (temp->right != NULL) {
            temp = temp->right;
        }
        ans = temp;
    }
    return ans;
}

node* inOrderSuccessor(node* head, int data) {
    node* temp = find(head, data);

    if (temp == NULL)
        return NULL;

    else if (temp->right != NULL)
        return min(head->right);

    else {
        node* returnNode = NULL;
        node* testingNode = head;

        while (testingNode != temp) {
            if (testingNode->data > temp->data) {
                returnNode = testingNode;
                testingNode = testingNode->left;
            }
            else {
                testingNode = testingNode->right;
            }
        }
        return returnNode;
    }
}

bool isLeaf(node* head) {
    if (head->right == NULL && head->left == NULL)
        return true;

    return false;
}

bool isOnlyLeft(node* head) {

    return (head->left != NULL && head->right == NULL);
}

bool isOnlyRight(node* head) {

    return (head->right != NULL && head->left == NULL);
}

node* deleteNode(node* head, int data) {
    node* cur = head;
    if (head == NULL)
        return head;

    else if (head->data < data)
        head->right = deleteNode(head->right, data);

    else if (head->data > data)
        head->left = deleteNode(head->left, data);

    else {
        if (isLeaf(head)) {
            delete head;
            return NULL;
        }
        else if (isOnlyLeft(head)) {
            node* temp = head;
            head = head->left;
            delete temp;
        }
        else if (isOnlyRight(head)) {
            node* temp = head;
            head = head->right;
            delete temp;
        }
        else {
            node* temp = min(head->right);
            head->data = temp->data;
            head->right = deleteNode(head->right ,temp->data);
        }
        return head;
    }

    return cur;
}

int main() {
    node* root = NULL;
    int limit = rand() % 24;
    int arr[limit];
    for (int i =0; i < limit; i++)
        arr[i] = abs(rand() - 8979);

    for (int i = 0; i < limit; i++)
        root = insert(root, arr[i]);

    cout << " root is: " << root->data << endl;
    inOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    levelOrder(root);
    root = deleteNode(root, 9488);
    int val = rand();
    if (search(root, val))
        cout << endl << " " << val << " is there" << endl;

    else
        cout << endl << " " << val << " is not there" << endl;

    cout << " min data is: " << min(root)->data << endl;
    cout << " max data is: " << max(root)->data << endl;
    cout << endl;
    inOrder(root);
    cout << endl;
    cout << " inorderSuccessor data is: " << inOrderSuccessor(root, 6745)->data << endl;

    return 0;
}