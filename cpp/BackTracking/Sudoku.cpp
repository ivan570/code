#include<bits/stdc++.h>

using namespace std;

void print(int pad[9][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j)
            cout << pad[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int pad[9][9]) {
    unordered_map<int, int> row[9], col[9], box[3][3];
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            row[i][pad[i][j]] += 1;
            col[j][pad[i][j]] += 1;
            box[i / 3][j / 3][pad[i][j]] += 1;
            if (row[i][pad[i][j]] > 1 || col[j][pad[i][j]] > 1 || box[i / 3][j / 3][pad[i][j]] > 1)
                return false;
        }
    }
    return true;
}

bool sudoku(int pad[9][9], int x, int y) {
    if (x == 8 && y == 9)
        return isSafe(pad);
    if (y == 9) {
        x++;
        y = 0;
    }
    if (pad[x][y])
        return sudoku(pad, x, y + 1);
    for (int number = 1; number <= 9; ++number) {
        pad[x][y] = number;
        if (sudoku(pad, x, y + 1))
            return true;
        pad[x][y] = 0;
    }
    return false;
}

int main() {
    int pad[9][9] = {{3, 1, 6, 5, 7, 8, 4, 9, 2},
                     {5, 2, 9, 1, 3, 4, 7, 6, 8},
                     {4, 8, 7, 6, 2, 9, 5, 3, 1},
                     {2, 6, 3, 0, 1, 5, 9, 8, 7},
                     {9, 7, 4, 8, 6, 0, 1, 2, 5},
                     {8, 5, 1, 7, 9, 2, 6, 4, 3},
                     {1, 3, 8, 0, 4, 7, 2, 0, 6},
                     {6, 9, 2, 3, 5, 1, 8, 7, 4},
                     {7, 4, 5, 0, 8, 6, 3, 1, 0}};

    if (sudoku(pad, 0, 0))
        print(pad);
    else
        cout << "not possible";

    return 0;
}

/*
{3, 1, 6, 5, 7, 8, 4, 9, 2,
 5, 2, 9, 1, 3, 4, 7, 6, 8,
 4, 8, 7, 6, 2, 9, 5, 3, 1,
 2, 6, 3, 4, 1, 5, 9, 8, 7,
 9, 7, 4, 8, 6, 3, 1, 2, 5,
 8, 5, 1, 7, 9, 2, 6, 4, 3,
 1, 3, 8, 9, 4, 7, 2, 5, 6,
 6, 9, 2, 3, 5, 1, 8, 7, 4,
 7, 4, 5, 2, 8, 6, 3, 1, 9};
 */