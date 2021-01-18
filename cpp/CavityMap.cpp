#include <bits/stdc++.h>
using namespace std;

void printVector(vector<auto> arr) {
    for (auto i : arr) {
        cout << i << endl;
    }
}

void getOutput(vector<string> grid) {

    int n = grid.size();

    if (n > 2) {
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                auto temp = grid[i][j];
                if (temp > grid[i][j - 1] && temp > grid[i][j + 1] && temp > grid[i - 1][j] && temp > grid[i + 1][j])
                    grid[i][j] = 'X';
            }
        }
    }
    printVector(grid);
}

int main() {
    int n;
    cin >> n;
    vector<string> grid(n);

    for (int n_time = 0; n_time < n; ++n_time) {
        cin >> grid[n_time];
    }

    getOutput(grid);
    return 0;
}
