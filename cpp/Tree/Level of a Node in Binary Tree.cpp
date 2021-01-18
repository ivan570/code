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

void hight(Node *node, int target, int &ans, int level) {
	if (!node)
		return;
	
	if (node->data == target){
		ans = level;
		return;
	}

	hight(node->left, target, ans, level + 1);
	hight(node->right, target, ans, level + 1);
}

int getLevel(Node *node, int target) {
	int ans = 0;
	hight(node, target, ans, 1);
	return ans;
}
