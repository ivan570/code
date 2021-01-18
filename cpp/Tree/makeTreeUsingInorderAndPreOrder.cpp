#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left, *right;

    explicit Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node *makeTree(int in[], int pre[], int size, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
        return nullptr;

    int rootIndex = -1; 				// the index of root
    for (int i = inS; i <= inE; ++i)
    {
        if (in[i] == pre[preS])
        {
            rootIndex = i;
            break;
        }
    }
    int leftInS = inS,  				// left infix start
	leftInE = rootIndex - 1,  			// left infix end
    	rightInS = rootIndex + 1, 			// right infix start
	rightInE = inE, 				// right infix end
    	leftPreS = preS + 1, 				// left prefix start
	leftPreE = leftInE - leftInS + leftPreS, 	// left prefix end
    	rightPreS = leftPreE + 1, 			// right prefix start
	rightPreE = preE; 				// right prefix end

    Node *head = new Node(pre[preS]);
    head->left = makeTree(in, pre, size, leftInS, leftInE, leftPreS, leftPreE);
    head->right = makeTree(in, pre, size, rightInS, rightInE, rightPreS, rightPreE);
    return head;
}

void inorder(Node *head)
{
    if (head)
    {
        inorder(head->left);
        cout << head->data << " ";
        inorder(head->right);
    }
}

int main()
{
    int in[] = {6, 4, 7, 2, 10, 5, 1, 8, 3, 11, 9};
    int pre[] = {1, 2, 4, 6, 7, 5, 10, 3, 8, 9, 11};
    int size = sizeof(pre) / sizeof(pre[0]);
    Node *head = makeTree(in, pre, size, 0, size - 1, 0, size - 1);
    inorder(head);

    return 0;
}
