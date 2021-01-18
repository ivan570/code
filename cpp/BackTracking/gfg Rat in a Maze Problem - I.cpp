// Rat in a Maze Problem - I 
/*
Consider a rat placed at (0, 0) in a square matrix of order N*N. It has to reach the destination at (N-1, N-1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and cannot be crossed while value 1 at a cell in the matrix represents that it can be traveled through.

Example 1:

Input: N = 4, m[][] = {{1, 0, 0, 0},
                       {1, 1, 0, 1}, 
                       {1, 1, 0, 0},
                       {0, 1, 1, 1}}
Output: DDRDRR DRDDRR
Explanation: The rat can reach the 
destination at (3, 3) from (0, 0) by two 
paths ie DRDDRR and DDRDRR when printed 
in sorted order we get DDRDRR DRDDRR.
Example 2:
Input: N = 2, m[][] = {{1, 0},
                       {1, 0}}
Output: -1
*/
#include <bits/stdc++.h>
#define MAX 6
using namespace std;

vector<string> ans_vec;

void helper(int m[MAX][MAX], int **solution, int n, int x, int y, string str) {

	
	if (x >= n || y >= n || x < 0 || y < 0 || solution[x][y] || !m[x][y]) 
		return;

	if (x == n - 1 && y == n - 1) {
		ans_vec.push_back(str);
		return;
	}

	solution[x][y] = 1;
	helper(m, solution, n, x + 1, y, str + "D");
	helper(m, solution, n, x, y - 1, str + "L");
	helper(m, solution, n, x, y + 1, str + "R");
	helper(m, solution, n, x - 1, y, str + "U");
	solution[x][y] = 0;
}

vector<string> printPath(int m[MAX][MAX], int n) {
	int **solution = new int*[n];
	for (int i = 0; i < n; ++i)
		solution[i] = new int[n];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			solution[i][j] = 0;

	ans_vec.clear();
	helper(m, solution, n, 0, 0, "");
	return ans_vec;
}


int main() {
	int n;
	cin >> n;
	int arr[MAX][MAX];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];

	cout << "Input taken ";

	vector<string> ans = printPath(arr, n);
	
	for (string i : ans)
		cout << i << endl;
	return 0;
}