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

int helper(Node *root, int &ans) {
	if (!root)
		return 0;
	int left = helper(root->left, ans);
	int right = helper(root->right, ans);

	int first = max(max(left, right) + root->data, root->data);
	int second = max(first, left + right + root->data);
	ans = max(ans, second);
	return first;
}

int findMaxSum(Node* root) {
	if (!root)
		return 0;
	int ans = INT_MIN;
	helper(root, ans);
	return ans;
}

int main() {
	Node *root = new Node(10);
	root->left = new Node(2);
	root->right = new Node(5);
	root->right->right = new Node(-2);

	cout << findMaxSum(root) << endl;
	return 0;
}