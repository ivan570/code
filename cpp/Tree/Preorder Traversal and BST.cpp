#include <bits/stdc++.h>
using namespace std;

bool helper(int inorder[], int preorder[], int inS, int inE, int preS, int preE) {
	if (inS > inE)
		return true;
	int index = -1;
	unordered_map<int, int> maped;
	for (int i = inS; i <= inE; ++i) {
		maped[inorder[i]] = i;
		if (preorder[preS] == inorder[i]) {
			index = i;
			break;
		}
	}

	for (int i = preS + 1; i <= preS + index - inS; ++i) {
		if (maped.find(preorder[i]) == maped.end())
			return false;
	}

	int leftInS = inS, leftInE = index - 1, leftPreS = preS + 1, leftPreE = leftInE - leftInS + leftPreS;
	bool left = helper(inorder, preorder, leftInS, leftInE, leftPreS, leftPreE);
	int rightInS = index + 1, rightInE = inE, rightPreS = leftPreE + 1, rightPreE = preE;
	bool right = helper(inorder, preorder, rightInS, rightInE, rightPreS, rightPreE);
	return left && right;
}

bool check(int pre[], int n) {
	int in[n];
	for (int i = 0; i < n; ++i)
		in[i] = pre[i];
	sort(in, in + n);

	return helper(in, pre, 0, n - 1, 0, n - 1);
}

void test_case() {
	int n;
	cin >> n;
	int pre[n];
	for (int i = 0; i < n; ++i)
		cin >> pre[i];
	cout << check(pre, n) << endl;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		test_case();
	return 0;
}