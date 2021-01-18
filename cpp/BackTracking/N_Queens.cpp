#include <bits/stdc++.h>
using namespace std;

int board[20][20] = {0};

bool isPossible(int n, int row, int col) {
    
    // for a same col
    for (int i = 0; i < row; ++i)
        if (board[i][col])
            return false;

    // for left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j])
            return false;
    }

    // for right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
        if (board[i][j])
            return false;
    }

    return true;
}

void QueenProblem(int n, int row) {
    // which means that it's time to print the array(board);
    if (row == n) {
        cout << "[";
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n; ++j) 
                if (board[i][j])
                    cout << j + 1 << " ";
            
        cout << "] ";
    }
    else {
        for (int i = 0; i < n; ++i) 
            if (isPossible(n, row, i)) {
                board[row][i] = 1;
                QueenProblem(n, row + 1);
                board[row][i] = 0;
            }
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        for (int i = 0; i < 20; ++i) 
            for (int j = 0; j < 20; ++j)
                board[i][j] = 0;
        int n;
        cin >> n;
        QueenProblem(n, 0);
    }
    return 0;
}