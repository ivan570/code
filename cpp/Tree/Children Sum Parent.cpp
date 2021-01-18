/*
Given a Binary Tree. Check whether all of its nodes have the value equal to the sum of their child nodes.

Example 1:

Input:
     10
    /
  10
Output: 1
Explanation: Here, every node is sum of
its left and right child.
Example 2:

Input:
       1
     /   \
    4     3
   /  \
  5    N
Output: 0
Explanation: Here, 1 is the root node
and 4, 3 are its child nodes. 4 + 3 =
7 which is not equal to the value of
root node. Hence, this tree does not
satisfy the given conditions.
*/
int isSumPropertyHelper(Node *root) {
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return root->data;
    int left = isSumPropertyHelper(root->left);
    if (left == -1)
        return -1;

    int right = isSumPropertyHelper(root->right);
    if (right == -1)
        return -1;

    if (root->data != left + right)
        return -1;
    return root->data;
}


int isSumProperty(Node *root)
{
    int h = isSumPropertyHelper(root);
    if (h == -1)
        return 0;
    return 1;
}
