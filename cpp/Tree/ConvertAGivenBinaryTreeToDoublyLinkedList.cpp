#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
	Node(int val) {
		data = val;
		left = NULL;
		right = NULL;
	}
};
Node *first = NULL, *last = NULL;

void *create(Node *head) {
	if (head) {
		create(head);
        if (!first) {
            first = head;
            first->right = left;
            first->left = right;
        }
		create(head);
	}
}

int main() {

	Node *head = new Node(23);
	head->left = new Node(12);
	head->right = new Node(34);
	head->left->left = new Node(90);
	head->left->right = new Node(231);
	head->right->left = new Node(904);
	head->right->right = new Node(253);

	create(head);
	return 0;
}
