/*
Given a Binary Tree of size N, Print the corner nodes ie- the node at the leftmost and rightmost of each level.

Example 1:

Input :
         1
       /  \
     2      3
    / \    / \
   4   5  6   7    

Output: 1 2 3 4 7

Explanation:
Corners at level 0: 1
Corners at level 1: 2 3
Corners at level 2: 4 7

Example 2:

Input:

        10
      /    \
     20     30
    / \  
   40  60

Output: 10 20 30 40 60
*/

// ==> 1st that pass the <== gfg
void printCorner(Node *root) {
    if (!root)
        return;
    queue<Node *> qu;
    qu.push(root);

    while (!qu.empty()) {
        int n = qu.size();
        for (int i = 0; i < n; ++i) {
            Node *head = qu.front();
            qu.pop();
            if (i == 0 || i == n - 1)
                cout << head->data << " ";
            if (head->left)
                qu.push(head->left);
            if (head->right)
                qu.push(head->right);
        }
    }
}

// ==> 2nd that not pass the gfg but work on CLion

void printCorner(Node *root) {
    unordered_map<int, pair<int, int>> index;
    if (!root)
        return;
    queue<pair<Node *, int>> qu;
    cout << root->data << " ";
    qu.push(make_pair(root, 0));

    while (!qu.empty()) {
        Node *head = qu.front().first;
        int hInt = qu.front().second;
        qu.pop();

        if (index[hInt].first == 0) {
            index[hInt].first = head->data;
        }
        index[hInt].second = head->data;

        if (head->left)
            qu.push(make_pair(head->left, hInt + 1));
        if (head->right)
            qu.push(make_pair(head->right, hInt + 1));
    }

    int i = 1;
    while (true) {
        if (index[i].second == 0 && index[i].first == 0)
            break;
        cout << index[i].first << " " << index[i].second << " ";
        i++;
    }
    cout << endl;
}