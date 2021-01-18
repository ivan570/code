/*
Given a Binary Tree of size N. Find the sum of all the leaf nodes that are left child of their parent of the given binary tree.

Example 1:

Input:
       1
     /   \
    2     3
Output: 2

Example 2:

Input :
         1
        /  \
       2    3
     /  \     \
    4    5     8
  /  \        /  \
 7    2      6    9
Output: 13
Explanation:
sum = 6 + 7 = 13
*/


int leftLeavesSum(Node *root) {
    if (!root)
        return 0;
    Node *pNode = root->left;
    int left, right;
    if (pNode && !pNode->left && !pNode->right) {
        left =  pNode->data;
    }
    else
        left = leftLeavesSum(root->left);
    right = leftLeavesSum(root->right);
    return left + right;
}
