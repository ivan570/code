#include <bits/stdc++.h>

using namespace std;

struct Node {
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        key = x;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(int inorder[], int levelOrder[], int iStart, int iEnd, int n);

void printPreorder(Node *node) {
    if (node == NULL)
        return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int in[n], level[n];
        for (int i = 0; i < n; i++) {
            cin >> in[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> level[i];
        }
        Node *root = NULL;
        root = buildTree(in, level, 0, n - 1, n);
        printPreorder(root);
        cout << endl;
    }
    return 0;
}// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node* left, *right;
};
*/

bool search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; ++i) {
        if (arr[i] == value)
            return true;
    }
    return false;
}

int *createArr(int array[], int start, int end, int size, int n, int levelOrder[]) {
    int *returnArray = new int[size];
    int k = 0;
    for (int i = 0; i <= n; ++i) {
        if (search(array, start, end, levelOrder[i]))
            returnArray[k++] =  levelOrder[i];
    }
    return returnArray;
}

Node *buildTree(int inorder[], int levelOrder[], int iStart, int iEnd, int n) {
    if (iStart > iEnd)
        return nullptr;

    int data = levelOrder[0];
    int index = 0;

    for (int i = iStart; i <= iEnd; ++i) {
        if (inorder[i] == data) {
            index = i;
            break;
        }
    }

    Node *root = new Node(data);
    int *leftLevel = createArr(inorder, iStart, index - 1, index - iStart, n, levelOrder);
    int *rightLevel = createArr(inorder, index + 1, iEnd, iEnd - index, n, levelOrder);

    int leftStart = iStart, leftEnd = index - 1, rightStart = index + 1, rightEnd = iEnd;

    root->left = buildTree(inorder, leftLevel, leftStart, leftEnd, n);
    root->right = buildTree(inorder, rightLevel, rightStart, rightEnd, n);
    return root;
}