/*
Given a Binary Tree, find the maximum width of it. Maximum width is defined as the maximum number of nodes in any level.
For example, maximum width of following tree is 4 as there are 4 nodes at 3rd level.

          1
       /     \
     2        3
   /    \    /    \
  4    5   6    7
    \
      8

Example 1:

Input:
       1
     /    \
    2      3
Output: 2
Example 2:

Input:
        10
      /     \
    20      30
   /    \
  40    60
Output: 2
*/
void finalSum(Node *root, unordered_map<int, int> &sum, int level) {
    if (!root)
        return;
    sum[level] += 1;
    finalSum(root->left, sum, level + 1);
    finalSum(root->right, sum, level + 1);
}

int getMaxWidth(Node* root)
{
    if (!root)
        return 0;
    unordered_map<int, int> sum;
    finalSum(root, sum, 0);
    int m = INT_MIN;
    for (auto i : sum)
        m = max(i.second, m);
    return m;
}

