/*Given a binary tree and an integer X. Your task is to complete the function countSubtreesWithSumX() that returns the count of the number of subtress having total node’s data sum equal to the value X.
Example: For the tree given below:            

              5
            /    \
        -10     3
        /    \    /  \
      9     8  -4 7

Subtree with sum 7:
             -10
            /      \
          9        8

and one node 7.

Example 1:

Input:
       5
    /    \
  -10     3
 /   \   /  \
 9   8 -4    7
X = 7
Output: 2
Explanation: Subtrees with sum 7 are [9, 8, -10] and [7] (refer the example in the problem description).
Example 2:

Input:
    1
  /  \
 2    3
X = 5
Output: 0
Explanation: No subtree has sum equal
to 5.
*/


void getSum(Node *root, int *ans) {
    if (!root)
        return;
    getSum(root->left, ans);
    getSum(root->right, ans);
    (*ans) += root->data;
}

int countSubtreesWithSumX(Node *root, int sum) {
    if (!root)
        return 0;
    int ans = 0;
    getSum(root, &ans);
    return countSubtreesWithSumX(root->left, sum) + countSubtreesWithSumX(root->right, sum) + (ans == sum);
}
