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

void inorder(Node *root) {
	if (!root)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void preorder(Node *root) {
	if (!root)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node *root) {
	if (!root)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

vector<int> bottomView(Node *root) {
	queue<pair<Node *, int>> qu;
	vector<int> ans;
	if (!root)
		return ans;
	qu.push(make_pair(root, 0));
	map<int, int> index;

	while (!qu.empty()) {
		pair<Node *, int> temp = qu.front();
		qu.pop();
		int hd = temp.second;
		Node *node = temp.first;
		index[hd] = node->data;
		if (node->left)
			qu.push(make_pair(node->left, hd - 1));
		if (node->right)
			qu.push(make_pair(node->right, hd + 1));
	}
	for (auto i : index)
		ans.push_back(i.second);
	return ans;
}

int main() {
	Node *root = new Node(20);
	root->left = new Node(8);
	root->right = new Node(22);
	root->left->right = new Node(3);
	root->left->left = new Node(5);
	root->left->right->left = new Node(10);

	root->right->left = new Node(4);
	root->right->right = new Node(25);
	root->right->left->right = new Node(14);

	vector<int> v = bottomView(root);
	for (int i : v) {
		cout << i << " ";
	}
	return 0;
}
