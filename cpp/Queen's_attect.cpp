#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<vector<int> > board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int output(vector<vector<int> > board, int i, int j) {

    int n = board.size();
    int c = 0;
    for (int k = i + 1; k < n; ++k) {
        if (board[k][j] > 0)
            break;
        c++;
    }
    for (int k = i - 1; k >= 0; --k) {
        if (board[k][j] > 0)
            break;
        c++;
    }
    for (int k = j + 1; k < n; ++k) {
        if (board[i][k] > 0)
            break;
        c++;
    }
    for (int k = j - 1; k >= 0; --k) {
        if (board[i][k] > 0)
            break;
        c++;
    }
    for (int k = i + 1, l = j + 1; k < n && l < n; ++k, ++l) {
        if (board[k][l] > 0)
            break;
        c++;
    }
    for (int k = i - 1, l = j + 1; k >= 0 && l < n; --k, ++l) {
        if (board[k][l] > 0)
            break;
        c++;
    }
    for (int k = i + 1, l = j - 1; k < n && l >= 0; ++k, --l) {
        if (board[k][l] > 0)
            break;
        c++;
    }
    for (int k = i - 1, l = j - 1; k >= 0 && l >= 0; --k, --l) {
        if (board[k][l] > 0)
            break;
        c++;
    }
    return c;
}

int main() {
    int size, test;
    cin >> size >> test;
    vector<vector<int> > board(size, vector<int>(size, 0));
    int i, j;
    cin >> i >> j;
    i--;
    j--;

    while (test-- > 0) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        board[x][y] = 1;
    }

    cout << output(board, i, j) << endl;
    return 0;
}
