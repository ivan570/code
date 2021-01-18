/*
Given two BST, Return elements of both BSTs in sorted form.

Example 1:

Input:
BST1:
       5
     /   \
    3     6
   / \
  2   4
BST2:
        2
      /   \
     1     3
            \
             7
            /
           6
BST2 = 2 1 3 N N N 7 6
Output: 1 2 2 3 3 4 5 6 6 7
Explanation: After merging and sorting the
two BST we get 1 2 2 3 3 4 5 6 6 7
Example 2:

Input:
BST1:
       12
     /
    9
   /
  6
   \
   11
BST2:
      8
    /  \
   5    10
  /
 2
Output: 2 5 6 8 9 10 11 12
Explanation: After merging and sorting the
two BST we get 2 5 6 8 9 10 11 12
*/


/*
===> 1st ways <===
*/

void inorder(Node *root, vector<int> &arr)
{
    if (root)
    {
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
}

vector<int> merge(Node *one, Node *two)
{
    vector<int> vOne, vTwo, ans;
    inorder(one, vOne);
    inorder(two, vTwo);
    int i = 0, j = 0;
    while (i < vOne.size() && j < vTwo.size()) {
        if (vOne[i] < vTwo[j])
            ans.push_back(vOne[i++]);
        else
            ans.push_back(vTwo[j++]);
    }

    while (i < vOne.size())
        ans.push_back(vOne[i++]);

    while (j < vTwo.size())
        ans.push_back(vTwo[j++]);
    return ans;
}

/*
===> 1st ways finish <===
*/

/*
===> 2nd ways <===
*/

/*
===> 2nd ways finish <===
*/
