struct Node {
	int data;
	Node* left;
	Node* right;
};

bool checkBST(Node* root) {
	if (!root)
		return false;
	if (root->left && root->left->data >= root->data)
		return false;
	if (root->right && root->right->data <= root->data)
		return false;
	if (!checkBST(root->left) && !checkBST(root->right))
		return false;
	return true;
}