#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    explicit Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

vector <int> zigZagTraversal(Node* root);

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        vector <int> res = zigZagTraversal(root);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}

/*
Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

Example 1:

Input:
        3
      /   \
     2     1
Output: 3 1 2
Example 2:

Input:
           7
        /     \
       9       7
     /  \     /
    8    8   6
   /  \
  10   9
Output: 7 9 7 8 8 6 9 10
*/
vector <int> zigZagTraversal(Node* root)
{
    vector<int> ans;
    vector<pair<int, int>> pair_vec;

    queue<pair<Node *, int>> qu;
    qu.push(make_pair(root, 0));

    while (!qu.empty()) {
        pair<Node *, int> temp = qu.front();
        qu.pop();
        Node *node = temp.first;
        int level = temp.second;
        pair_vec.push_back(make_pair(node->data, level));
        if (node->left)
            qu.push(make_pair(node->left, level + 1));
        if (node->right)
            qu.push(make_pair(node->right, level + 1));
    }

    map<int, vector<int>> index;
    for (pair<int, int> temp : pair_vec) {
        index[temp.second].push_back(temp.first);
    }

    for (auto i : index) {
        if (!(i.first % 2))
            for (int j : i.second)
                ans.push_back(j);

        else
            for (int j = i.second.size() - 1; j >= 0; --j)
                ans.push_back(i.second[j]);

    }

    return ans;
}