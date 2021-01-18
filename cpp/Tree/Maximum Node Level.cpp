/*
Example 1:

Input:
      2
    /    \
   1      3
 /   \     \
4    6      8
     /
    5
Output: 2
Explanation: The level 2 with nodes 4,
6 and 8 is the level with maximum
number of nodes.
*/

void level(Node *root, unordered_map<int, int> &index, int lev) {
    if (!root)
        return;
    index[lev] += 1;
    level (root->left, index, lev + 1);
    level (root->right, index, lev + 1);
}

int maxNodeLevel(Node *root) {
    int m = INT_MIN;
    unordered_map<int, int> index;
    level(root, index, 0);
    int ans = -1;
    for (auto i : index) {
        if (i.second > m) {
            ans = i.first;
            m = i.second;
        }
        if (i.second == m)
            ans = min(i.first, ans);
    }
    return ans;
}
