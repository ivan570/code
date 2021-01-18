/*
Given a Binary Tree, check if all leaves are at same level or not.

Example 1:

Input:
            1
          /   \
         2     3

Output: 1

Explanation: 
Leaves 2 and 3 are at same level.

Example 2:

Input:
            10
          /    \
        20      30
       /  \        
     10    15

Output: 0

Explanation:
Leaves 10, 15 and 30 are not at same level.
*/
int depth(Node *root) {
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    return max(depth(root->left), depth(root->right)) + 1;
}

bool expression(Node *root, int depth) {
    if (!root)
        return true;
    if (!root->left && !root->right)
        return depth == 1;
    return expression(root->left, depth - 1) && expression(root->right, depth - 1);
}

bool check(Node *root) {
    int d = depth(root);
    return expression(root, d);
}
