#include <bits/stdc++.h>
using namespace std;

bool issumpossible(vector<int> arr, int sum)
{
    vector<vector<int>> ans(sum + 1, vector<int>(arr.size() + 1));

    for (int i = 0; i < sum + 1; ++i)
    {
        for (int j = 0; j < arr.size() + 1; ++j)
        {
            if (j == 0 && i != 0)
                ans[i][j] = 0;
            else if (i == 0)
                ans[i][j] = 1;
            else if (arr[j - 1] <= i && j > 0)

                ans[i][j] = ans[i][j - 1] + ans[i - arr[j - 1]][j - 1];

            else
                ans[i][j] = ans[i][j - 1];
        }
    }

    return ans[sum][arr.size()];
}

int getOutput(vector<int> arr, int total)
{
    int mid = total / 2;
    while (mid > 0)
    {
        if (issumpossible(arr, mid))
            return total - 2 * mid;
    }
    return total;
}

int main()
{
    int k, total = 0;
    cin >> k;
    vector<int> arr(k);
    for (int i = 0; i < k; ++i)
    {
        int x;
        cin >> x;
        total += x;
        arr[i] = x;
    }

    cout << getOutput(arr, total) << endl;
    return 0;
}
