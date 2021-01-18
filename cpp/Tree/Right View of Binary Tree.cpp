/*
Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8

Example 1:

Input:
       1
    /    \
   3      2
Output: 1 2
Example 2:

Input:
     10
    /   \
  20     30
 /   \
40  60 
Output: 10 30 60
*/


vector<int> vec;
int maxii = 0;
void rightViewHelper(Node *root, int level) {
    
    if (!root)
        return;
    if (maxii < level) {
        vec.push_back(root->data);
        maxii = level;
    }
    rightViewHelper(root->right, level + 1);
    rightViewHelper(root->left, level + 1);
}

// Should return  right view of tree
vector<int> rightView(Node *root)
{
    vec.clear();
    maxii = 0;
    rightViewHelper(root, 1);
    return vec;
}


