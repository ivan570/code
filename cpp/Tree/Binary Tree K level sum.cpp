/*
(0(5(6()())(4()(9()())))(7(1()())(3()())))
                             0
                          /     \
                       5         7
                    /      \     /    \
                   6       4    1     3
                             \
                             9
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
	explicit Node(int val) {
		data = val;
		left = right = nullptr;
	}
};


void test_case() {
	int k, level = -1, sum = 0;
	string tree;
	cin >> k;
	cin >> tree;
	for (int i = 0; i < tree.size(); ++i) {
		if (tree[i] == '(')
			level++;
		else if (tree[i] == ')')
			level--;
		else if (level == k) {
			int num = 0;
			for (int j = i; j < tree.size(); ++j) {
				if (tree[j] == '(' || tree[j] == '(') {
					i = j - 1;
					break;
				}
				int ch = tree[j] - '0';
				num = num * 10 + ch;
			}
			sum += num;
		}
	}
	cout << sum << endl;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		test_case();
}