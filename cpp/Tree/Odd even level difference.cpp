/*
Given a Binary Tree. Find the difference between the sum of node values at even levels and the sum of node values at the odd levels.

Example 1:

Input:
            1
          /   \
         2     3

Output: -4

Explanation:
sum at odd levels - sum at even levels
= (1)-(2+3) = 1-5 = -4

*/
int odd, even;

void inorder(Node *root, int level)
{
    if (root)
    {
        inorder(root->left, level + 1);
        if (level % 2)
            odd += root->data;
        else
            even += root->data;
        inorder(root->right, level + 1);
    }
}

int getLevelDiff(Node *root)
{
    odd = 0;
    even = 0;
    inorder(root, 1);
    return odd - even;
}

