#include <bits/stdc++.h>
using namespace std;

int recursive(int arr[], int i, int j)
{
    if (i >= j)
        return 0;
    int ans = INT_MAX;
    for (int k = i; k <= j - 1; ++k)
    {
        int temp = recursive(arr, i, k) + recursive(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        ans = min(temp, ans);
    }
    return ans;
}
int memoization(int arr[], int i, int j)
{
    static vector<vector<int>> ay(j + 1, vector<int>(j + 1, -1));
    int ans = INT_MAX;
    if (ay[i][j] != -1)
        return ay[i][j];
    else if (i >= j)
        return 0;
    else
    {
        int t = INT_MAX;
        for (int k = i; k < j; ++k)
        {
            int temp = memoization(arr, i, k) + memoization(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
            t = min(t, temp);
        }
        ay[i][j] = t;
        ans = min(t, ans);
    }
    return ans;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 3, 7, 8, 1, 2, 5, 3, 6, 8, 9, 4, 2, 1, 3, 4, 7, 8, 9, 10, 2, 3, 4, 5, 6, 7, 8, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
//    cout << recursive(arr, 1, n - 1) << endl;
    cout << memoization(arr, 1, n - 1) << endl;
    return 0;
}
