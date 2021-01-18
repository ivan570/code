#include <bits/stdc++.h>
using namespace std;

int rec (int weight[], int profit[], int capacity, int n) {
    if (capacity == 0 || n == 0)
        return 0;
    if (weight[n - 1] <= capacity)
        return max(rec (weight, profit, capacity - weight[n - 1], n - 1) + profit[n - 1],
                   rec (weight, profit, capacity, n - 1));
    else
        return rec (weight, profit, capacity, n - 1);
}

int memorization (int weight[], int profit[], int capacity, int n) {
    static vector<vector<int>> ans( capacity + 1, vector<int> (n + 1, -1) );
    if (capacity == 0 || n == 0)
        return 0;

    if (ans[capacity][n] != -1)
        return ans[capacity][n];

    if (weight[n - 1] <= capacity)
        return ans[capacity][n] = max(memorization(weight, profit, capacity - weight[n - 1], n - 1) + profit[n - 1],
                                      memorization(weight, profit, capacity, n - 1));
    else
        return ans[capacity][n] = memorization(weight, profit, capacity, n - 1);
}

int topDown (int weight[], int profit[], int capacity, int n) {
    int ans[capacity + 1][n + 1];
    for (int i = 0; i <= capacity; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || j == 0)
                ans[i][j] = 0;
            else if (weight[j - 1] <= i)
                ans[i][j] = max(ans[i - weight[j - 1]][j - 1] + profit[j - 1],
                                ans[i][j - 1]);
            else
                ans[i][j] = ans[i][j - 1];
        }
    }
    return ans[capacity][n];
}

int main() {
    int weight[] = { 10, 20, 30 };
    int profit[] = { 60, 100, 120 };
    int capacity = 50;

    cout << rec(weight, profit, capacity, 3) << endl;
    cout << memorization(weight, profit, capacity, 3) << endl;
    cout << topDown(weight, profit, capacity, 3) << endl;

    cout << "ivan vaghani" << endl;

    return 0;
}

