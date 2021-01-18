#include <bits/stdc++.h>
using namespace std;

struct node 
{
	int data;
	struct node *left;
	struct node *right;
    node(int x) {
        data = x;
        left = right = nullptr;
    }
};

vector<vector<int>> vFinal;

void preorder(node *root, vector<int> vec) {
    if (!root) 
        return;
    
    if (!root->left && !root->right) {
        vec.push_back(root->data);
        vFinal.push_back(vec);
        return ;
    }
    vec.push_back(root->data);
    preorder(root->left, vec);
    preorder(root->right, vec);
}

int main()
{
    node *root;
	root = new node(25);
	root->left = new node(10);
	root->right = new node(30);
    root->left->left = new node(25);
/* 
        25
       /  \
      10  30
     /
    25
*/
    vector<int> vec;
    preorder(root, vec);

    for (vector<int> temp : vFinal) {
        for (int i : temp) {
            cout << i << " ";
        }
        cout << endl;
    }

	return 0;
}
