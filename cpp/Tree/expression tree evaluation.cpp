#include <bits/stdc++.h>
using namespace std;

struct node {
    string data;
    struct node *left;
    struct node *right;

    node(string x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

bool isExpression(string &s) {
    if (s == "+" or s == "-" or s == "*" or s == "/") return true;
    return false;
}

int evalTree(node *);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        int p = 0;
        node *root = new node(s[p++]);
        queue<node *> q;
        q.push(root);
        while (!q.empty()) {
            node *f = q.front();
            q.pop();
            node *l, *r;
            if (isExpression(f->data)) {
                l = new node(s[p++]);
                r = new node(s[p++]);
                f->left = l;
                f->right = r;
                q.push(l);
                q.push(r);
            }
        }

        cout << evalTree(root) << endl;
    }
}
// } Driver Code Ends


/*The structure of node is as follows
struct node{
    string data;
    node *left;
    node *right;
};
*/

void postorder(node *root, string &str) {
    if (root) {
        postorder(root->left, str);
        postorder(root->right, str);
        str += root->data + " ";
    }
}
vector<string> split(const string& str) {
    vector<string> ans;
    string temp;
    for (char i : str) {
        if (i == ' ') {
            ans.push_back(temp);
            temp = "";
        }
        else
            temp += i;
    }
    return ans;
}

bool isOperator(const string& temp) {
    return (temp == "+" || temp == "-" || temp == "*" || temp == "/");
}

int stringToInt(const string& one) {
    stringstream temp(one);
    int x;
    temp >> x;
    return x;
}

int evalTree(node* root) {
    string str;
    postorder(root, str);

    stack<string> number;
    vector<string> vec = split(str);

    for (const string& temp : vec) {
        if (isOperator(temp)) {
            string one = number.top();
            number.pop();
            string two = number.top();
            number.pop();
            int oneInt = stringToInt(one), twoInt = stringToInt(two);
            if (temp == "+") {
                int ans = oneInt + twoInt;
                number.push(to_string(ans));
            }
            else if (temp == "-") {
                int ans = twoInt - oneInt;
                number.push(to_string(ans));
            }
            else if (temp == "*") {
                int ans = oneInt * twoInt;
                number.push(to_string(ans));
            }
            else if (temp == "/") {
                int ans = twoInt / oneInt;
                number.push(to_string(ans));
            }
        }
        else {
            number.push(temp);
        }
    }
    return stringToInt(number.top());
}
