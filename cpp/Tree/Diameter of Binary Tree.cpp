/*
Given a Binary Tree, find diameter of it.
The diameter of a tree is the number of nodes on the longest path between two leaves in the tree. The diagram below shows two trees each with diameter nine, the leaves that form the ends of a longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).



Example 1:

Input:
       1
     /  \
    2    3
Output: 3
Example 2:

Input:
         10
        /   \
      20    30
    /   \
   40   60
Output: 4
*/

int OfTree(Node *root, int *ans) {
    if (!root)
        return 0;
    if (!root->left && !root->right) {
        (*ans) = max((*ans), 1);
        return 1;
    }
    int left = OfTree(root->left, ans);
    int right = OfTree(root->right, ans);
    *ans = max((*ans), left + right + 1);
    return max(left, right) + 1;
}

int diameter(Node *node) {
    int ans = 0;
    OfTree(node, &ans);
    return ans;
}

