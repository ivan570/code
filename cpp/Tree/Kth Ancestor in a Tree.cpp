#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

Node *newNode(int val) {
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int kthAncestor(Node *root, int k, int node);

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        int k, node;
        scanf("%d ", &k);
        scanf("%d ", &node);
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        cout << kthAncestor(root, k, node) << endl;
    }
    return 0;
}
void inorder(Node *root) {
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void getArray(Node *root, int search, int level, vector<int> &ans, bool &isTrue, int &size) {
    if (!root || isTrue)
        return;
    if (!isTrue && root->data == search) {
        isTrue = true;
        ans.insert(ans.begin() + level, root->data);
        size = level;
        return;
    }
    ans.insert(ans.begin() + level, root->data);
    getArray(root->left, search, level + 1, ans, isTrue, size);
    getArray(root->right, search, level + 1, ans, isTrue,size);
}

int kthAncestor(Node *root, int k, int node) {
    if (!root)
        return 0;
    vector<int> ans;
    bool boolean = false;
    int size;
    getArray(root, node, 0, ans, boolean, size);
    int temp = size - k;
    if (temp >= 0)
        return ans[temp];
    return -1;
}
