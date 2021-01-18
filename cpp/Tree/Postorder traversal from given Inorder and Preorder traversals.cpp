#include<bits/stdc++.h>
using namespace std;


void printPostOrder(int in[], int pre[], int n);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int pre[N],in[N];
        for(int i=0;i<N;i++)
            cin>>in[i];
        for(int i=0;i<N;i++)
            cin>>pre[i];
        printPostOrder(in,pre,N);
        cout<<endl;

    }
}
// } Driver Code Ends


struct Node {
    int data;
    Node *left, *right;
    explicit Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};


Node *createTree(int in[], int pre[], int size, int inS, int inE, int preS, int preE) {
    if (inS > inE)
        return nullptr;
    int root = pre[preS];
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (in[i] == root) {
            index = i;
            break;
        }
    }
    Node *head = new Node(root);

    int leftInS = inS,              leftInE = index - 1,
        leftPreS = preS + 1,        leftPreE = leftInE - leftInS + leftPreS,
        rightInS = index + 1,       rightInE = inE,
        rightPreS = leftPreE + 1,   rightPreE = preE;

    head->left = createTree(in, pre, size, leftInS, leftInE, leftPreS, leftPreE);
    head->right = createTree(in, pre, size, rightInS, rightInE, rightPreS, rightPreE);
    return head;
}

void postorder(Node *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void printPostOrder(int in[], int pre[], int n)
{
    Node *root = createTree(in, pre, n, 0, n - 1, 0, n - 1);
    postorder(root);
}
