/*
Given a binary tree and an integer S, check whether there is root to leaf path wiht its sum as S.

Example 1:

Input:
Tree = 
            1
          /   \
        2      3
S = 2

Output: 0

Explanation:
There is no root to leaf path with sum 2.
Example 2:

Input:
Tree = 
            1
          /   \
        2      3
S = 4

Output: 1

Explanation:
The sum of path from leaf node 3 to root 1 is 4.
*/


bool hasPathSum(Node *root, int sum) {
    if (!root && !sum)
        return true;
    if (!root)
        return false;

    if (!root->left && !root->right)
        return root->data == sum;

    return hasPathSum(root->left, sum - root->data) || hasPathSum(root->right, sum - root->data);
}
