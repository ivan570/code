/*
Given a Binary Tree of size N, your task is to complete the function rightLeafSum(), that should return the sum of all the leaf nodes that are right child of their parent of the given binary tree.
Example:

Input : 
         1
        /  \
       2    3
     /  \     \
    4    5     8 
     \        /  \
      2       6   7
Output :
sum = 2 + 5 + 7 = 14
*/
int rightLeafSum(Node *root) {
    if (!root)
        return 0;
    Node *pNode = root->right;
    int left, right;
    if (pNode && !pNode->left && !pNode->right)
        right = pNode->data;
    else
        right = rightLeafSum(root->right);
    left = rightLeafSum(root->left);
    return left + right;
}
