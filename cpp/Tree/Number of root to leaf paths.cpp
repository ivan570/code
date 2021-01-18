// Number of root to leaf paths
/*
Given a binary tree, you need to find the number of all root to leaf paths along with their path lengths.

Example(To be used only for expected output):
Input:
2
2
3 2 L 3 4 R
4
10 20 L 10 30 R 20 40 L 20 60 R
Output:
2 2 $
2 1 $3 2 $

Explanation :
Testcase1:
There are 2 root to leaf paths of length 2.    

Testcase2:
There is 1 root to leaf paths of length 2 and 2 root to leaf paths of length 3.

*/

vector<int> vFinal;

void preorder(Node *root, int vec) {
    if (!root)
        return;
    if (!root->left && !root->right) {
        vFinal.push_back(vec + 1);
        return;
    }
    preorder(root->left, vec + 1);
    preorder(root->right, vec + 1);
}

void pathCounts(Node *root)
{
    vFinal.clear();
    preorder(root, 0);
    
    unordered_map<int, int> frq;
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i : vFinal) {
        frq[i] += 1;
        mini = min(mini, i);
        maxi = max(maxi, i);
    }
    
    for (auto i : frq) {
        cout << i.first << " " << i.second << " $";
    }
}
