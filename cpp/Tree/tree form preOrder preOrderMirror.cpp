//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

Node* constructBinaryTree(int pre[], int preMirror[], int size);

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    printInorder(constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}// } Driver Code Ends


Node *helper(int pre[], int size, int level, int cur, int &index) {
	if (index >= size || cur > level)
		return nullptr;
	Node *root = new Node(pre[index]);
	if (level == cur)
		return root;
	index += 1;
	root->left = helper(pre, size, level, cur + 1, index);
	index += 1;
	root->right = helper(pre, size, level, cur + 1, index);
	return root;
}

int hight(double size) {
	return int(log10(size) / log10(2)) + 1;
}

Node *constructBinaryTree(int pre[], int preMirror[], int size) {
	if (!size)
		return nullptr;
	int level = hight(size);
	int index = 0;
	return helper(pre, size, level, 1, index);
}