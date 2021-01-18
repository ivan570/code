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

Node *createTree(int parent[], int n) {
	if (!n)
		return nullptr;
	map<int, pair<int, int>> maped;
	for (int i = -1; i < n; ++i)
		maped[i] = make_pair(-2, -2);

	for (int i = 0; i < n; ++i) {
		if (maped[parent[i]].first == -2)
			maped[parent[i]].first = i;
		else if (maped[parent[i]].second == -2)
			maped[parent[i]].second = i;
	}
	int start = -1;

	queue<int> qu;
	qu.push(maped[start]);

	while (!qu.empty()) {
		
	}
}