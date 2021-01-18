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

bool isSame(Node *tree, Node *subTree) {
	if (!tree && !subTree)
		return true;
	if (!tree || !subTree)
		return false;
	if (tree->data != subTree->data)
		return false;
	return isSame(tree->left, subTree->left) && isSame(tree->right, subTree->right);
}

bool isSubTree(Node *tree, Node *subTree) {
	if (!subTree)
		return true;
	if (!tree)
		return false;
	if (isSame(tree, subTree))
		return true;
	return isSubTree(tree->left, subTree) || isSubTree(tree->right, subTree);
}

int main() {
	Node *root = new Node(10);
	root->left = new Node(4);
	root->right = new Node(6);
	root->right->left = new Node(30);

	Node *tree = new Node(26);
	tree->left = new Node(10);
	tree->left->right = new Node(6);
	tree->left->right->left = new Node(30);
	tree->right = new Node(3);
	tree->right->right = new Node(3);
	tree->left->left = new Node(4);

	cout << isSubTree(tree, root) << endl;

}