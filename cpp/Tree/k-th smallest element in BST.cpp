/*
Given a BST and an integer K. Find the Kth Smallest element in the BST. 

Example 1:

Input:
      2
    /   \
   1     3
K = 2
Output: 2
Example 2:

Input:
        2
      /  \
     1    3
K = 5
Output: -1
 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1<=Number of nodes<=100000
*/

void smallest(Node *root, int &c, int &ans, int k) {
    if (!root)
        return;
    smallest(root->left, c, ans, k);
    c += 1;
    if (k == c) {
        ans = root->data;
        return;
    }
    smallest(root->right, c, ans, k);
}

int KthSmallestElement(Node *root, int K) {
    int c = 0;
    int ans = -1;
    smallest(root, c, ans, K);
    return ans;
}
