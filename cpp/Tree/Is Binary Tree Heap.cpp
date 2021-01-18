// Given a binary tree you need to check if it follows max heap property or not.
bool isHeap(Node *root) {
    if (!root || (!root->left && !root->right))
        return true;
    int data = root->data, left = root->left->data, right = root->right->data;
    return (data >= left && data >= right) &&
            isHeap(root->left) &&
            isHeap(root->right);
}
