#include<bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;
	
	Node(char x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void preorder(Node *root){
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
Node *convertExpression(string str,int i);
int main(){
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		Node *root=convertExpression(str,0);
		preorder(root);
		cout<<endl;
	}
}// } Driver Code Ends


/*Complete the function below
Node is as follows
struct Node{
	char data;
	Node *left,*right;
};
*/
Node *convertExpression(string str,int i)
{
    if (i >= str.size())
        return nullptr;
        
    Node *head = new Node(str[i]);
    if (i + 1 < str.size()) 
    {
        if (str[i + 1] == '?') 
            head->left = convertExpression(str, i + 2);
        if (str[i + 1] == ':')
            head->right = convertExpression(str, i + 2);
    }
    return head;
}
