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

int getMaxPath(Node *root, int &ans) {
	if (!root)
		return 0;
	if (!root->left && !root->right)
		return root->data;
	int left = getMaxPath(root->left, ans);
	int right = getMaxPath(root->right, ans);

	if (root->left && root->right) {
		ans = max(ans, left + right + root->data);
		return max(left, right) + root->data;
	}
	if (root->left) 
		return left + root->data;
	
	else
		return right + root->data;	
}

int maxPathSum(Node* root) {
	int ans = INT_MIN;
	getMaxPath(root, ans);
	return ans;
}

int main() {
	Node *root = new Node(-15);
	root->left = new Node(5);
	root->left->right = new Node(1);
	root->left->left = new Node(-8);
	root->left->left->left = new Node(2);
	root->left->left->right = new Node(-3);
	root->right = new Node(6);
	root->right->left = new Node(3);
	root->right->right = new Node(9);
	root->right->right->right = new Node(0);
	root->right->right->right->left = new Node(4);
	root->right->right->right->right = new Node(-1);
	root->right->right->right->right->left = new Node(10);


	cout << maxPathSum(root);
	return 0;
}