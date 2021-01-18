/*
Given a complete binary tree, reverse the nodes present at alternate levels.

Example 1:

Input:
             1
          /   \
        3      2

Output:

             1
          /   \
        2      3

Explanation: Nodes at level 2 are reversed.
Example 2:

Input:
              1
          /      \
         2        3
       /  \      /  \
     42   51   63   72

Output:
             1
          /      \
         3        2
       /  \      /  \
     42   51   63   72

Explanation:
Nodes at level 2 are reversed.
Level 1 and 3 remain as it is.
*/


void reverse(Node *root, Node *head, int level) {
    if (!root)
        return;
    if (level % 2)
        swap(root->data, head->data);

    reverse(root->left, head->right, level + 1);
    reverse(root->right, head->left, level + 1);
}

void reverseAlternate(Node *root)
{
    reverse(root->left, root->right, 1);
}