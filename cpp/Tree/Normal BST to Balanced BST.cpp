#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node* insert(struct Node* node, int key){
    if (node == NULL) return new Node(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}

void preOrder(Node* node)
{
    if (node == NULL)return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int height(struct Node* node)
{
    if (node==NULL) return 0;
    else
    {
        int lDepth = height(node->left);
        int rDepth = height(node->right);
        if (lDepth > rDepth) return(lDepth+1);
        else return(rDepth+1);
    }
}

Node* buildBalancedTree(Node* root);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        struct Node *root = NULL;
        int n, temp;
        cin>>n;
        while(n--)
        {
            cin>>temp;
            root = insert(root, temp);
        }
        root = buildBalancedTree(root);
        cout<<height(root)<<endl;
    }
    return 0;
}

void inorder(Node *root, vector<int> &arr) {
    if (!root)
        return ;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

Node *createBalancedTree(const vector<int>& arr, int low, int high) {
    if (low > high)
        return nullptr;
    int mid = low + (high - low) / 2;
    Node *head = new Node(arr[mid]);
    head->left = createBalancedTree(arr, low, mid - 1);
    head->right = createBalancedTree(arr, mid + 1, high);
    return head;
}

Node *buildBalancedTree(Node* root)
{
    vector<int> arr;
    inorder(root, arr);
    return createBalancedTree(arr, 0, arr.size() - 1);
}
