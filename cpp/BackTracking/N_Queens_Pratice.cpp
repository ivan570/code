#include <bits/stdc++.h>
using namespace std;

bool isPossible(int **arr, int x, int y, int n) {

	// same col
	for (int i = 0; i < n; ++i)
		if (arr[i][y])
			return false;

	// left side
	for (int i = x - 1, j = y - 1; i >= 0 && j >= o; --i, --j)
		if (arr[i][j])
			return false;

	// right side
	for (int i = x - 1, j = y + 1; i >= 0 && j < n; --i, ++j)
		if (arr[i][j])
			return false;

	return true;
}

void nQueensProblem(int **arr, int n, int row) {
	if (row == n) {
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j)
				cout << arr[i][j] << " ";
			cout << endl;
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (isPossible(arr, row, i, n)) {
			arr[row][i] = 1;
			nQueensProblem(arr, n, row + 1);
			arr[row][i] = 0;
		}
	}
}

int main() {
	int n;
	cin >> n;

	// making array
	int **arr = new int*[n];
	for (int i = 0; i < n; ++i)
		arr[i] = new int[n];

	// make it all zero
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			arr[i][j] = 0;


	nQueensProblem(arr, n, 0);
	return 0;
}