//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}

Node* insertToAVL( Node* node, int data);

int main()
{
	int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        
        for(int i=0; i<n; i++)
        {
            root = insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
    }
    return 0;
}// } Driver Code Ends


/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

/*You are required to complete this method */

int getHeight(Node *root) {
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    int left = 0, right = 0;
    if (root->left)
        left = root->left->height;
    if (root->right)
        right = root->right->height;
    return max(left, right) + 1;
}

int getBFactor(Node *root) {
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    return left - right;
}

Node *LeftLeft(Node *root) {
    Node *l = root->left;
    Node *lr = nullptr, *ll;
    if (l) {
        lr = l->right;
        ll = l->left;
    }

    l->right = root;
    root->left = lr;

    root->height = ll->height;
    return l;
}

Node *LeftRight(Node *root) {
    Node *l = root->left, *lr;
    if (l)
        lr = l->right;
    root->left = lr->right;
    l->right = lr->left;
    lr->left = l;
    lr->right = root;

    lr->height = l->height;
    l->height--;
    root->height = l->height;
    return lr;
}

Node *RightRight(Node *root) {
    Node *r = root->right, *rl = nullptr;
    Node *rr = nullptr;
    if (r) {
        rl = r->left;
        rr = r->right;
    }
    root->right = rl;
    r->left = root;

    root->height = rr->height;
    return r;
}

Node *RightLeft(Node *root) {
    Node *r = root->right;
    Node *l = root->left;
    Node *rl = nullptr;
    if (r)
        rl = r->left;
    root->right = rl->left;
    r->left = rl->right;
    rl->left = root;
    rl->right = r;


    root->height = rl->height;
    rl->height++;
    r->height = root->height;
    return rl;
}

int heightOfTree(Node *root) {
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    return max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
}

Node *insert(Node *root, int data) {
    if (!root)
        return new Node(data);
    if (root->data > data)
        root->left = insert(root->left, data);
    if (root->data < data)
        root->right = insert(root->right, data);

    root->height = getHeight(root);

    if (getBFactor(root) == 2 && getBFactor(root->left) == 1)
        return LeftLeft(root);
    else if (getBFactor(root) == 2 && getBFactor(root->left) == -1)
        return LeftRight(root);
    else if (getBFactor(root) == -2 && getBFactor(root->right) == -1)
        return RightRight(root);
    else if (getBFactor(root) == -2 && getBFactor(root->right) == 1)
        return RightLeft(root);
    return root;
}

Node* insertToAVL(Node* root, int data)
{
    return insert(root, data);
}