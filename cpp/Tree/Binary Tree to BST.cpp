#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* right;
	Node* left;

	Node(int x) {
		data = x;
		right = NULL;
		left = NULL;
	}
};

Node *ret = NULL;
Node *insert(Node *root, int data) {
	if (!root) 
		root = new Node(data);
	else
		if (root->data < data)
			root->right = insert(root->right, data);
		else if (root->data > data)
			root->left = insert(root->left, data);
	return root;
}

void inorder(Node *root) {
	if (!root)
		return;
	inorder(root->left);
	ret = insert(ret, root->data);
	inorder(root->right);
}

Node *binaryTreeToBST (Node *root) {
	ret = NULL;
	inorder(root);
	return ret;
}