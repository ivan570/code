// Time Complexity: O(2^(n^2)).
// The recursion can run upperbound 2^(n^2) times.
// Space Complexity: O(n^2).
// Output matrix is required so an extra space of size n*n is needed.

#include <bits/stdc++.h>
#define N 4
using namespace std;

void helper(int arr[N][N], int **solution, int x, int y) {
	int n = N;
	if (x == n - 1 && y == n - 1) {
		solution[x][y] = 1;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j)
				cout << solution[i][j] << " ";
			cout << endl;
		}
		cout << endl;
		return;
	}
	if (arr[x][y] == 0 || x >= n || y >= n || x < 0 || y < 0 || solution[x][y])
		return;

	solution[x][y] = 1;
	helper(arr, solution, x - 1, y);
	helper(arr, solution, x + 1, y);
	helper(arr, solution, x, y - 1);
	helper(arr, solution, x, y + 1);
	solution[x][y] = 0;
}

void rateInMaze(int arr[N][N]) {
    int **solution = new int *[N];
    for (int i = 0; i < N; ++i)
        solution[i] = new int[N];

    helper(arr, solution, 0, 0);
}

int main() {
    int maze[N][N] = { { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 0, 1, 0, 0 },
                       { 1, 1, 1, 1 } };
    rateInMaze(maze);
    return 0;
}
