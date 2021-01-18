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

Node *getLCA(Node *root, int a, int b) {
	if (!root)
		return nullptr;
	if (root->data == a || root->data == b)
		return root;
	Node *left = getLCA(root->left, a, b);
	Node *right = getLCA(root->right, a, b);
	if (left && right)
		return root;
	if (left)
		return left;
	return right;
}

void height(Node *root, int search, int &ans, int level) {
	if (!root)
		return;
	if (root->data == search) {
		ans = level;
		return;
	}
	height(root->left, search, ans, level + 1);
	height(root->right, search, ans, level + 1);
}

int findDist(Node *root, int a, int b) {
	Node *lca = getLCA(root, a, b);
	int a_height, b_height;
	height(lca, a, a_height, 0);
	height(lca, b, b_height, 0);
	return a_height + b_height;
}

int main() {
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	cout << findDist(root, 2, 3);
	return 0;
}