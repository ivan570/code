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

void inorder(Node *root, int l, int h, int &ans) {
	if (!root)
		return;
	inorder(root->left, l, h, ans);
	if (root->data >= l && root->data <= h)
		ans++;
	inorder(root->right, l, h, ans);
}

int getCountOfNode(Node *root, int l, int h)
{
	int ans = 0;
	inorder(root, l, h, ans);
	return ans; 
}