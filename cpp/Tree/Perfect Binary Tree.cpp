/*
Given a Binary Tree, write a function to check whether the given Binary Tree is a prefect Binary Tree or not.
A Binary tree is Perfect Binary Tree in which all internal nodes have two children and all leaves are at same level.
*/

bool isPerfectRec(struct Node* root, int d, int level)
{
    if (!root)
        return true;

    if (!root->left && !root->right)
        return (level + 1 == d);

    if (!root->left || !root->right)
        return false;

    return  (isPerfectRec(root->left, d, level + 1) &&
            isPerfectRec(root->right, d, level + 1));
}

