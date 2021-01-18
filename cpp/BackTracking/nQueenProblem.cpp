#include <bits/stdc++.h>

using namespace std;

int board[11][11] = {0};

bool isPossible(int row, int col, int size) {
    for (int i = 0; i < row; ++i)
        if (board[i][col])
            return false;


    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        if (board[i][j])
            return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < size; --i, ++j)
        if (board[i][j])
            return false;

    return true;
}

void nQueenProblem(int size, int row) {
    if (row == size) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j)
                cout << board[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        if (isPossible(row, i, size)) {
            board[row][i] = 1;
            nQueenProblem(size, row + 1);
            board[row][i] = 0;
        }
    }
}

int main() {

    int n;
    cin >> n;
    nQueenProblem(n, 0);
    return 0;
}
