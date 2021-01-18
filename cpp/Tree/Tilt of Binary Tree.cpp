/*
Given a binary tree of size N+1, your task is to complete the function tiltTree(), 
that return the tilt of the whole tree. 
The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null nodes are assigned tilt to be zero. 
Therefore, tilt of the whole tree is defined as the sum of all nodes’ tilt.

Examples:

Input :
    1
   / \
  2   3
Output : 1
Explanation: 
Tilt of node 2 : 0
Tilt of node 3 : 0
Tilt of node 1 : |2-3| = 1
Tilt of binary tree : 0 + 0 + 1 = 1

Input :
    4
   / \
  2   9
 / \   \
3   5   7
Output : 15
Explanation: 
Tilt of node 3 : 0
Tilt of node 5 : 0
Tilt of node 7 : 0
Tilt of node 2 : |3-5| = 2
Tilt of node 9 : |0-7| = 7
Tilt of node 4 : |(3+5+2)-(9+7)| = 6
Tilt of binary tree : 0 + 0 + 0 + 2 + 7 + 6 = 15
*/

struct Node {
	int val;
	struct Node *left, *right;
};

int sum(Node *root) {
    if (!root)
        return 0;
    return sum(root->right) + sum(root->left) + root->val;
}

int tiltTree(Node* root)
{
    if (!root)
        return 0;
    return abs(sum(root->right) - sum(root->left)) + tiltTree(root->left) + tiltTree(root->right);
}


// much better solution

int sum(Node *root, int *ans) {
    if (!root)
        return 0;
    int left = sum(root->left, ans);
    int right = sum(root->right, ans);
    (*ans) += abs(left - right);
    return left + right + root->val;
}

int tiltTree(Node* root)
{
    int ans = 0;
    sum(root, &ans);
    return ans;
}