#include<bits/stdc++.h>

using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int val) {
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node *buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);
    Node *root = newNode(stoi(ip[0]));
    queue<Node *> queue;
    queue.push(root);
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node *currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if (currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];
        if (currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// in pair first for select the node
// and second for not select the node
pair<int, int> nonAdjacent(Node *root) {
    if (!root)
        return make_pair(0, 0);
    pair<int, int> left, right, ans;
    left = nonAdjacent(root->left);
    right = nonAdjacent(root->right);

    // if we select the node....
    // so we can't select the their child....
    // ans first will be sum of second of child and root data
    ans.first = left.second + right.second + root->data;

    // if we not select the node
    // we have choice to select or reject the child node
    // we take max of both the case...
    ans.second = max(left.second, left.first) + max(right.first, right.second);

    return ans;
}

int getMaxSum(Node *root) {
    pair<int, int> ans = nonAdjacent(root);
    return max(ans.second, ans.first);
}

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        cout << getMaxSum(root) << endl;
    }
    return 0;
}
