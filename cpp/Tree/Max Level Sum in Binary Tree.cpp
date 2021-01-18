/*
Given a Binary Tree having positive and negative nodes. Find the maximum sum of a level in the given Binary Tree.

Example 1:

Input :
             4
          /    \
         2     -5
        / \    / \
      -1   3  -2  6

Output: 6

Explanation :
Sum of all nodes of 0'th level is 4
Sum of all nodes of 1'th level is -3
Sum of all nodes of 2'th level is 6
Hence maximum sum is 6

Example 2:

Input :
            1
          /   \
         2     3
        / \     \
       4   5     8
                / \
               6   7

Output :  17

Explanation: Maximum sum is at level 2. */

void finalSum(Node *root, unordered_map<int, int> &sum, int level) {
    if (!root)
        return;
    sum[level] += root->data;
    finalSum(root->left, sum, level + 1);
    finalSum(root->right, sum, level + 1);
}

int maxLevelSum(Node *root) {
    if (!root)
        return 0;
    unordered_map<int, int> sum;
    finalSum(root, sum, 0);
    int m = INT_MIN;
    for (auto i : sum)
        m = max(i.second, m);
    return m;
}
