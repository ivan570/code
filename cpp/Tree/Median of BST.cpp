void inorder(Node *root, vector<int> &vec) {
    if (!root)
        return;
    inorder(root->left, vec);
    vec.push_back(root->data);
    inorder(root->right, vec);
}

float findMedian(struct Node *root) {
    vector<int> vec;
    inorder(root, vec);
    int size = vec.size();
    if (size % 2)
        return vec[size / 2];
    else
        return (float)(vec[(size / 2) - 1] + vec[(size / 2)]) / 2;
}
