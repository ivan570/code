#include <bits/stdc++.h>
#define MAX 6
using namespace std;

bool isTrue = false;
void helper(int m[MAX][MAX], int **solution, int n, int x, int y) {
	if (x >= n || y >= n || x < 0 || y < 0 || solution[x][y] || !m[x][y])
		return;
	if (x == n - 1 && y == n - 1) {
		solution[x][y] = 1;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j)
				cout << solution[i][j];
			cout << endl;
		}
		isTrue = true;
		return;
	}
	solution[x][y] = 1;
	for (int k = 1; k <= m[x][y]; ++k) {
		helper(m, solution, n, x + k, y);
		helper(m, solution, n, x, y - k);
		helper(m, solution, n, x, y + k);
		helper(m, solution, n, x - k, y);
	}
	solution[x][y] = 0;
}

void inMaze(int m[MAX][MAX], int n) {
	int **solution = new int*[n];
	for (int i = 0; i < n; ++i)
		solution[i] = new int[n];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			solution[i][j] = 0;

	helper(m, solution, n, 0, 0);
	if (!isTrue)
		cout << "-1" << endl;
}


void test_case() {
	isTrue = false;
	int n;
	cin >> n;
	int arr[MAX][MAX];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];
	inMaze(arr, n);
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
		test_case();
}