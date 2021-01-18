#include<bits/stdc++.h>
using namespace std;

struct et
{
	char value;
	et* left, *right;

	et(char x){
	    value = x;
	    left = right = NULL;
	}
};

bool isOperator(char c)
{
	if (c == '+' || c == '-' ||
			c == '*' || c == '/' ||
			c == '^')
		return true;
	return false;
}

void inorder(et *t)
{
	if(t)
	{
		inorder(t->left);
		printf("%c ", t->value);
		inorder(t->right);
	}
}

et* constructTree(char []);

int main() {
    int t;
    cin>>t;
    while(t--){
    char postfix[25];
	cin>>postfix;
	et* r = constructTree(postfix);
	inorder(r);
	cout<<endl;
}
return 0;
}// } Driver Code Ends


/*struct et
{
	char value;
	et* left, *right;
};*/

et *constructTree(char postfix[]) {

    string str(postfix);
    stack<et *> alpha;
    for (char i : str) {
        if (!isOperator(i)) {
            et *head = new et(i);
            alpha.push(head);
        }
        else {
            et *head = new et(i);

            et *right = alpha.top();
            alpha.pop();
            et *left = alpha.top();
            alpha.pop();

            head->left = left;
            head->right = right;

            alpha.push(head);
        }
    }
    return alpha.top();
}
