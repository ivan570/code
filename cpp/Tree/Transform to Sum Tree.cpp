/*
Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree. The values of leaf nodes are changed to 0.

Example 1:

Input:
             10
          /      \
        -2        6
       /   \     /  \
     8     -4   7    5

Output:
            20
          /    \
        4        12
       /  \     /  \
     0     0   0    0

Explanation:

           (4-2+12+6)
          /           \
      (8-4)          (7+5)
       /   \         /  \
      0     0       0    0
*/
int sumTree(Node *root) {
    if (!root)
        return 0;
    if (!root->right && !root->left) {
        int temp = root->data;
        root->data = 0;
        return temp;
    }
    int left = sumTree(root->left);
    int right = sumTree(root->right);
    int temp = root->data;
    root->data = left + right;
    return root->data + temp;
}

void toSumTree(Node *root) {
    if (!root)
        return;
    sumTree(root);
}


