/*
Given a Binary Tree of size N,
your task is to complete the function minLeafSum(),
that should return the sum of all the leaf nodes that are at minimum level of the given binary tree.
Example:

Input :
         1
        /  \
       2    3
     /  \     \
    4    5     8
  /  \
 7    2
Output :
sum = 5 + 8 = 13
*/

void order(Node *root, int *ans, int *level, int cur) {

    if (!root)
        return;

    if (!root->left && !root->right) {
        if (cur == (*level)) {
            (*ans) = (*ans) + root->data;
        }
        if (cur < (*level)) {
            (*ans) = root->data;
            (*level) = cur;
        }
        return;
    }
    order(root->left, ans, level, cur + 1);
    order(root->right, ans, level, cur + 1);
}


int minLeafSum(Node *root) {
    int ans = 0;
    int level = INT_MAX;
    order(root, &ans, &level, 0);
    return ans;
}
