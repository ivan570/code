/*Given a Binary Tree of size N, your task is to complete the function countNonLeafNodes(), 
that should return the count of all the non-leaf nodes of the given binary tree.*/

int countNonLeafNodes(Node* root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
    	return 0;
    return countNonLeafNodes(root->left) + countNonLeafNodes(root->right) + 1;
}