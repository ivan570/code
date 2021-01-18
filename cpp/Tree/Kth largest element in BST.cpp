// Kth largest element in BST 
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

int kthLargest(Node *root, int k);

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int k;
        cin>>k;
        getchar();
        
        cout << kthLargest( head, k ) << endl;
    }
    return 1;
}// } Driver Code Ends


/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// >>= 1st Ways <<=
void inorder(Node *root, vector<int> &vec) {
    if (!root)
        return;
    inorder(root->left, vec);
    vec.push_back(root->data);
    inorder(root->right, vec);
}
int kthLargest(Node *root, int K)
{
    vector<int> vec;
    inorder(root, vec);
    return vec[vec.size() - K];
}

// =>>= 2nd Ways <<==

void largest(Node *root, int &c, int &ans, int k) {
    if (!root)
        return;
    largest(root->right, c, ans, k);
    c += 1;
    if (c == k) {
        ans = root->data;
    }
    largest(root->left, c, ans, k);
}

int kthLargest(Node *root, int K) {
    int c = 0;
    int ans = 0;
    largest(root, c, ans, K);
    return ans;
}