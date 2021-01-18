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

Node *helper(int pre[], int mirror[], int preS, int preE, int mS, int mE) {
	if (preS > preE)
		return nullptr;
	if (preS == preE)
		return new Node(pre[preS]);
	Node *root = new Node(pre[preS]); 
	int search = mirror[mS + 1];
	int index = -1;
	for (int i = preS; i <= preE; ++i) {
		if (pre[i] == search) {
			index = i;
			break;
		}
	}

	unordered_map<int, int> maped;
	for (int i = preS + 1; i < index; ++i) {
		maped[pre[i]] = 1;
	}

	int size = index - preS - 1;
	int left[size];
	int leftSize = size;
	int j = 0;
	for (int i = mS; i <= mE; ++i) {
		if (maped.find(mirror[i]) != maped.end()) {
			left[j++] = mirror[i];
		}
	}
	size = preE - index + 1;
	int rightSize = size;
	int right[size];
	maped.clear();
	for (int i = index; i <= preE; ++i) {
		maped[pre[i]] = 1;
	}
	j = 0;
	for (int i = mS; i <= mE; ++i) {
		if (maped.find(mirror[i]) != maped.end()) {
			right[j++] = mirror[i];
		}
	}

	int leftPreS = preS + 1, leftPreE = index - 1, rightPreS = index, rightPreE = preE;

	root->left = helper(pre, left, leftPreS, leftPreE, 0, leftSize - 1);
	root->right = helper(pre, right, rightPreS, rightPreE, 0, rightSize - 1);
	return root;
}

Node *constructBinaryTree(int pre[], int mirror[], int size) {
	return helper(pre, mirror, 0, size - 1, 0, size - 1);
}

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

int main() {
	int preOrder[] = {1, 2, 4, 5, 3, 6, 7};
	int preOrderMirror[] = {1, 3, 7, 6, 2, 5, 4};
	Node *root = constructBinaryTree(preOrder, preOrderMirror, 7);
	inorder(root);
	cout << endl;
	preorder(root);
	return 0;
}