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

void inorder(Node *root, vector<int> &vec) {
	if (!root)
		return;
	inorder(root->left, vec);
	vec.push_back(root->data);
	inorder(root->right, vec);
}

int pairsViolatingBST(Node *root, int n) {
	vector<int> vec;
	inorder(root, vec);
	int c = 0;
	for (int i = 0; i < vec.size(); ++i) 
		for (int j = 0; j < i; ++j) 
			if (vec[i] < vec[j]) 
				c++;
	return c;
}

int main() {
	Node *root = new Node(50);
	root->left = new Node(30);
	root->right = new Node(60);
	root->left->left = new Node(20);
	root->left->right = new Node(25);
	root->right->right = new Node(40);
	root->right->left = new Node(10);
	cout << pairsViolatingBST(root, 0);
	return 0;
}
