#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;
};

vector<int> leftView(struct Node *root);

// Utility function to create a new Tree Node
Node *newNode(int val) {
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
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

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
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


int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        vector<int> vec = leftView(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// A wrapper over leftViewUtil()

void getLeft(Node *root, vector<int> &ans, int level) {
    static int max = 0;
    if (!root)
        return;
    if (max < level) {
        ans.push_back(root->data);
        max = level;
    }
    getLeft(root->left, ans, level + 1);
    getLeft(root->right, ans, level + 1);
}

vector<int> leftView(Node *root) {
    vector<int> ans;
    if (!root) {
        return ans;
    }
    getLeft(root, ans, 1);
    return ans;
}

// 2nd way
vector<int> leftView(Node *root) {
    vector<int> ans;
    if (!root)
        return ans;
    map<int, int> maped;
    queue<pair<Node *, int>> qu;

    qu.push(make_pair(root, 0));
    while (!qu.empty()) {
        pair<Node *, int> temp = qu.front();
        qu.pop();
        int level = temp.second;
        Node *node = temp.first;
        if (maped.find(level) == maped.end())
            maped[level] = node->data;
        if (node->left)
            qu.push(make_pair(node->left, level + 1));
        if(node->right)
            qu.push(make_pair(node->right, level + 1));
    }
    for (auto i : maped)
        ans.push_back(i.second);
    return ans;
}
