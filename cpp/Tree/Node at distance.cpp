#include <bits/stdc++.h>

using namespace std;
#define MAX_HEIGHT 100000
struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int val) {
    Node *temp = new Node;
    temp->data = val;
    temp->left = nullptr;
    temp->right = nullptr;

    return temp;
}


int printKDistantfromLeaf(Node *node, int k);

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


int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ks;
        getline(cin, s);
        Node *root = buildTree(s);
        getline(cin, ks);
        int k = stoi(ks);
        cout << printKDistantfromLeaf(root, k) << endl;
    }
    return 0;
}

void helper(Node *root, int arr[], int &count, int index, bool visited[], int k) {
    if (!root)
        return;
    arr[index++] = root->data;
    visited[index - 1] = false;

    if (!root->left && !root->right && index - k - 1 >= 0 && !visited[index - k - 1]) {
        count++;
        visited[index - k - 1] = true;
    }
    helper(root->left, arr, count, index, visited, k);
    helper(root->right, arr, count, index, visited, k);
}

int printKDistantfromLeaf(Node *root, int k) {
    if (!root)
        return 0;
    int c = 0;
    int arr[MAX_HEIGHT];
    bool visited[MAX_HEIGHT] = {false};
    helper(root, arr, c, 0, visited, k);
    return c;
}