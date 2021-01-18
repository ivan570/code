#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

void inorder(Node *root, vector<int> &vec) {
	if (!root)
		return;
	inorder(root->left, vec);
	vec.push_back(root->data);
	inorder(root->right, vec);
}

vector<int> printCommon(Node *root1, Node *root2) {
	vector<int> ans, one, two;
	inorder(root1, one);
	inorder(root2, two);

	int i = 0, j = 0;
	while (i < one.size() && j < two.size()) {
		if (one[i] == two[j]) {
			ans.push_back(one[i]);
			i++;
			j++;
		}
		else if (one[i] > two[j])
			j++;
		else
			i++;
	}

	return ans;
}