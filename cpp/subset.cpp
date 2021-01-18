#include <bits/stdc++.h>
using namespace std;

bool subset(int arr[], int cap, int n) {
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
    int arr[] = { 3, 34, 4, 12, 5, 2 };
    int capasity = 30, n = 6;
    cout << subset(arr, capasity, n) << endl;
    return 0;
}
