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

void inorder(Node *root, int level, map<int, int> &maped) {
	if (!root)
		return;
	inorder(root->left, level + 1, maped);
	if (!(level % 2))
		maped[level] = (root->data);
	else if (level % 2)
		if (maped[level] == 0)
			maped[level] = (root->data);
	inorder(root->right, level + 1, maped);
}

vector<int> ExtremeNodes(Node *root) {
	vector<int> ans;
	if (!root)
		return ans;
	map<int, int> maped;
	inorder(root, 0, maped);
	for (auto i : maped)
		ans.push_back(i.second);
	return ans;
}

int main() {
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	cout << "inorder ";
	inorder(root);
	cout << endl;
	vector<int> ret = ExtremeNodes(root);
	for (int i : ret)
		cout << i << " ";
	return 0;
}