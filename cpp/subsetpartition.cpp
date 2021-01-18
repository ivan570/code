#include <bits/stdc++.h>
using namespace std;

bool subsetpartitions(int arr[], int n) {
    int t = 0;
    for (int i = 0; i < n; ++i)
        t += arr[i];
    if (t % 2 != 0)
        return false;
    int cap = t / 2;
    bool ans[cap + 1][n + 1];
    for (int i = 0; i <= cap; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (j == 0)
                ans[i][j] = false;
            else if (i == 0)
                ans[i][j] = true;
            else if (arr[j - 1] <= i)
                ans[i][j] = ans[i - arr[j - 1]][j - 1] || ans[i][j - 1];
            else
                ans[i][j] = ans[i][j - 1];
        }
    }
    return ans[cap][n];
}

int main() {
    int arr[] = { 3, 4, 5, 2 };
    int n = 4;
    cout << subsetpartitions(arr, n) << endl;
    return 0;
}
