#include <bits/stdc++.h>
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

vector<int> reverseLevelOrder(Node *root) {
	vector<int> ans;
	if (!root)
		return ans;
	map<int, vector<int>> maped;
	queue<pair<int, Node *>> que;
	que.push(make_pair(0, root));

	while (!que.empty()) {
		pair<int, Node *> temp = que.front();
		que.pop();
		Node *node = temp.second;
		int data = temp.first;
		maped[data].push_back(node->data);
		if (node->left)
			que.push(make_pair(data - 1, node->left));
		if (node->right)
			que.push(make_pair(data - 1, node->right));
	}

	for (auto i : maped) {
		for (int j : i.second) {
			ans.push_back(j);
		}
	}
	return ans;
}

int main() {
	Node *root = new Node(10);
	root->left = new Node(20);
	root->left->left = new Node(40);
	root->left->right = new Node(60);
	root->right = new Node(30);
	vector<int> arr = reverseLevelOrder(root);
	for (int i : arr)
		cout << i << " ";
}