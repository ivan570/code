#include <bits/stdc++.h>
#define size 2
using namespace std;

void helper(int arr[size][size], int **solution, int x, int y, string str) {

	if (x >= size || y >= size || x < 0 || y < 0 || solution[x][y] || !arr[x][y])
		return;
	if (x == size - 1 && y == size - 1) {
		cout << str << endl;
		return;
	}
	solution[x][y] = 1;
	helper(arr, solution, x - 1, y, (str + "U"));
	helper(arr, solution, x + 1, y, (str + "D"));
	helper(arr, solution, x, y - 1, (str + "L"));
	helper(arr, solution, x, y + 1, (str + "R"));
	solution[x][y] = 0;
}

void inMaze(int arr[size][size]) {

	int **solution = new int*[size];
	for (int i = 0; i < size; ++i)
		solution[i] = new int[size];

	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			solution[i][j] = 0;

	helper(arr, solution, 0, 0, "");
}

int main() {
	int arr[size][size] = {{1, 0}, {1, 0}}; // {1, 1, 0, 0}, {0, 1, 1, 1}};
	inMaze(arr);
	return 0;
}
