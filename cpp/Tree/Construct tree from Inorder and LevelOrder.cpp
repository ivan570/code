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

Node *helper(int inorder[], int levelOrder[], int inS, int inE, int levelS, int levelE) {
	if (inS > inE)
		return nullptr;
	if (inS == inE)
		return new Node(inorder[inS]);
	int data = levelOrder[0];
	Node *root = new Node(data);
	int index;
	for (int i = inS; i <= inE; ++i) {
		if (inorder[i] == data) {
			index = i;
			break;
		}
	}
	int leftInS = inS, leftInE = index - 1, rightInS = index + 1, rightInE = inE;
	int leftSize = index - inS;
	int rightSize = inE - index;
	int left[leftSize];
	int right[rightSize];

	unordered_map<int, int> maped;
	int l = 0, r = 0;
	for (int i = inS; i <= inE; ++i)
		maped[inorder[i]] = i;
	for (int i = levelS; i < levelE; ++i) {
		if (maped[levelOrder[i]] < index)
			left[l++] = levelOrder[i];
		else if (maped[levelOrder[i]] > index)
			right[r++] = levelOrder[i];
	}
	root->left = helper(inorder, left, leftInS, leftInE, 0, leftSize - 1);
	root->right = helper(inorder, right, rightInS, rightInE, 0, rightSize - 1);
	return root;
}

Node *buildTree(int inorder[], int levelOrder[], int iStart, int iEnd, int n) {
	return helper(inorder, levelOrder, 0, n - 1, 0, n - 1);
}

void inorder(Node *root) {
	if (!root)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int main() {
	int in[] = {4, 8, 10, 12, 14, 20, 22};
	int level[] = {20, 8, 22, 4, 12, 10, 14};
	int size = 7;
	Node *root = buildTree(in, level, 0, 6, 7);
	inorder(root);
	return 0;
}